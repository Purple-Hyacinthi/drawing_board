#include "canvaswidget.h"

#include "canvasfilecodec.h"
#include "canvasfilters.h"

#include <QFileInfo>
#include <QImageReader>
#include <QInputDialog>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QTextLayout>
#include <QQueue>
#include <QRandomGenerator>
#include <QResizeEvent>
#include <QTabletEvent>
#include <QTextOption>
#include <QWheelEvent>

#include <algorithm>
#include <cmath>
#include <functional>

namespace {

constexpr int kMargin = 28;

QString createId() {
    return QString::number(QRandomGenerator::global()->generate64(), 16);
}

QColor withOpacity(const QColor& color, qreal opacity) {
    QColor result(color);
    result.setAlphaF(std::clamp(opacity, 0.0, 1.0));
    return result;
}

QPainterPath regularPolygonPath(const QRectF& rect, int sides, qreal rotation = -M_PI_2) {
    QPainterPath path;
    if (sides < 3) {
        return path;
    }

    const QPointF center = rect.center();
    const qreal radius = std::min(rect.width(), rect.height()) * 0.5;
    for (int index = 0; index < sides; ++index) {
        const qreal angle = rotation + (M_PI * 2.0 * index) / static_cast<qreal>(sides);
        const QPointF point(center.x() + std::cos(angle) * radius, center.y() + std::sin(angle) * radius);
        if (index == 0) {
            path.moveTo(point);
        } else {
            path.lineTo(point);
        }
    }
    path.closeSubpath();
    return path;
}

QPainterPath starPath(const QRectF& rect, int points) {
    QPainterPath path;
    if (points < 4) {
        return path;
    }

    const QPointF center = rect.center();
    const qreal outerRadius = std::min(rect.width(), rect.height()) * 0.5;
    const qreal innerRadius = outerRadius * 0.45;
    for (int index = 0; index < points * 2; ++index) {
        const qreal angle = -M_PI_2 + (M_PI * index) / static_cast<qreal>(points);
        const qreal radius = (index % 2 == 0) ? outerRadius : innerRadius;
        const QPointF point(center.x() + std::cos(angle) * radius, center.y() + std::sin(angle) * radius);
        if (index == 0) {
            path.moveTo(point);
        } else {
            path.lineTo(point);
        }
    }
    path.closeSubpath();
    return path;
}

void drawWrappedText(QPainter* painter, const CanvasTypes::TextElement& textElement) {
    if (!painter) {
        return;
    }

    QFont font(textElement.style.fontFamily, textElement.style.size);
    font.setBold(textElement.style.bold);
    font.setItalic(textElement.style.italic);
    font.setLetterSpacing(QFont::AbsoluteSpacing, textElement.style.letterSpacing);

    QTextLayout layout(textElement.text, font);
    QTextOption option;
    option.setWrapMode(QTextOption::WordWrap);
    layout.setTextOption(option);

    const QFontMetricsF metrics(font);
    const qreal lineAdvance = metrics.lineSpacing() * std::max(textElement.style.lineHeight, 0.1);

    layout.beginLayout();
    qreal y = 0.0;
    while (true) {
        QTextLine line = layout.createLine();
        if (!line.isValid()) {
            break;
        }

        line.setLineWidth(textElement.rect.width());
        qreal x = 0.0;
        if (textElement.style.alignment.testFlag(Qt::AlignHCenter)) {
            x = (textElement.rect.width() - line.naturalTextWidth()) * 0.5;
        } else if (textElement.style.alignment.testFlag(Qt::AlignRight)) {
            x = textElement.rect.width() - line.naturalTextWidth();
        }
        line.setPosition(QPointF(std::max(0.0, x), y));
        y += lineAdvance;
    }
    layout.endLayout();

    painter->save();
    painter->setFont(font);
    painter->setPen(textElement.style.color);
    painter->setClipRect(textElement.rect);
    layout.draw(painter, textElement.rect.topLeft());
    painter->restore();
}

}  // namespace

CanvasWidget::CanvasWidget(QWidget* parent)
    : QWidget(parent) {
    setMouseTracking(true);
    setFocusPolicy(Qt::StrongFocus);
    initializeDefaults();
    createDocument(QStringLiteral("未命名 1"), 1600, 980, QColor(QStringLiteral("#ffffff")));
}

QString CanvasWidget::documentName() const {
    return document_.name;
}

QSize CanvasWidget::documentSize() const {
    return QSize(document_.width, document_.height);
}

QColor CanvasWidget::backgroundColor() const {
    return document_.backgroundColor;
}

CanvasWidget::ToolId CanvasWidget::activeTool() const {
    return activeTool_;
}

QString CanvasWidget::activeToolLabel() const {
    switch (activeTool_) {
    case ToolId::Select: return QStringLiteral("选择");
    case ToolId::Brush: return QStringLiteral("画笔");
    case ToolId::Pencil: return QStringLiteral("铅笔");
    case ToolId::Ink: return QStringLiteral("毛笔");
    case ToolId::Pen: return QStringLiteral("钢笔");
    case ToolId::Eraser: return QStringLiteral("橡皮");
    case ToolId::Eyedropper: return QStringLiteral("拾色器");
    case ToolId::Lasso: return QStringLiteral("套索");
    case ToolId::Fill: return QStringLiteral("填充");
    case ToolId::Shape: return QStringLiteral("形状");
    case ToolId::Text: return QStringLiteral("文字");
    }
    return QStringLiteral("画笔");
}

QString CanvasWidget::zoomLabel() const {
    return QStringLiteral("%1%").arg(static_cast<int>(std::round(fitScale_ * zoom_ * 100.0)));
}

qreal CanvasWidget::zoomFactor() const {
    return fitScale_ * zoom_;
}

bool CanvasWidget::canUndo() const {
    return historyIndex_ > 0;
}

bool CanvasWidget::canRedo() const {
    return historyIndex_ >= 0 && historyIndex_ < history_.size() - 1;
}

bool CanvasWidget::hasFloatingSelection() const {
    return floatingSelection_.active;
}

bool CanvasWidget::canMergeActiveLayerDown() const {
    if (document_.activeLayerIndex <= 0 || document_.activeLayerIndex >= document_.layers.size()) {
        return false;
    }

    const LayerState& upper = document_.layers.at(document_.activeLayerIndex);
    const LayerState& lower = document_.layers.at(document_.activeLayerIndex - 1);
    return !upper.locked && !lower.locked;
}

bool CanvasWidget::hasEditableActiveLayer() const {
    const LayerState* layer = activeLayer();
    return layer && !layer->locked;
}

QColor CanvasWidget::brushColor() const {
    return brushColor_;
}

QString CanvasWidget::brushName() const {
    return brushName_;
}

int CanvasWidget::brushSize() const {
    return brushSize_;
}

int CanvasWidget::brushOpacity() const {
    return brushOpacity_;
}

bool CanvasWidget::pressureEnabled() const {
    return pressureEnabled_;
}

CanvasWidget::BrushStyleState CanvasWidget::brushStyle() const {
    return brushStyle_;
}

CanvasWidget::BrushPanelCopy CanvasWidget::brushPanelCopy() const {
    if (activeTool_ == ToolId::Pencil) {
        return {QStringLiteral("铅笔设置"), QStringLiteral("笔刷名称"), QStringLiteral("笔锋角度"), QStringLiteral("线芯圆度"), QStringLiteral("颗粒密度"), QStringLiteral("纸面摩擦"), QStringLiteral("上色浓度"), QStringLiteral("线宽控制"), QStringLiteral("颗粒扰动"), QStringLiteral("铅笔保持细线和半透明，颗粒感主要由间距与纸面摩擦共同影响。")};
    }
    if (activeTool_ == ToolId::Ink) {
        return {QStringLiteral("毛笔设置"), QStringLiteral("笔刷名称"), QStringLiteral("笔锋角度"), QStringLiteral("笔腹饱满度"), QStringLiteral("落笔密度"), QStringLiteral("墨边凝聚"), QStringLiteral("出墨量"), QStringLiteral("笔锋控制"), QStringLiteral("飞白扰动"), QStringLiteral("毛笔会随速度显著变细，快速拖动时会带一点轻微枯笔和飞白感。")};
    }
    if (activeTool_ == ToolId::Pen) {
        return {QStringLiteral("钢笔设置"), QStringLiteral("笔刷名称"), QStringLiteral("笔尖角度"), QStringLiteral("笔尖圆润"), QStringLiteral("走墨密度"), QStringLiteral("硬边强度"), QStringLiteral("出墨稳定度"), QStringLiteral("压力映射"), QStringLiteral("笔锋扰动"), QStringLiteral("钢笔保持利落硬边，速度只做轻微粗细变化，收笔会略微加重。")};
    }
    return {QStringLiteral("画笔设置"), QStringLiteral("笔刷名称"), QStringLiteral("笔触角度"), QStringLiteral("软刷圆度"), QStringLiteral("叠色密度"), QStringLiteral("边缘柔化"), QStringLiteral("颜料流量"), QStringLiteral("粗细控制"), QStringLiteral("边缘扰动"), QStringLiteral("画笔笔触更软、羽化更重，慢速会更厚实，快速会更轻盈。")};
}

CanvasWidget::EraserMode CanvasWidget::eraserMode() const {
    return eraserMode_;
}

CanvasWidget::ShapeType CanvasWidget::shapeType() const {
    return shapeType_;
}

CanvasWidget::TextStyleState CanvasWidget::textStyle() const {
    return textStyle_;
}

int CanvasWidget::filterIntensity() const {
    return filterIntensity_;
}

QVector<QString> CanvasWidget::colorPresets() const {
    QVector<QString> values;
    values.reserve(colorPresets_.size());
    for (const QColor& color : colorPresets_) {
        values.append(color.name(QColor::HexRgb));
    }
    return values;
}

QVector<CanvasWidget::LayerSummary> CanvasWidget::layerSummaries() const {
    QVector<LayerSummary> summaries;
    summaries.reserve(document_.layers.size());
    for (int index = document_.layers.size() - 1; index >= 0; --index) {
        const LayerState& layer = document_.layers.at(index);
        summaries.append({layer.name, layer.visible, layer.locked, layer.opacity, layer.blendMode, index == document_.activeLayerIndex, thumbnailForLayer(layer)});
    }
    return summaries;
}

int CanvasWidget::activeLayerIndex() const {
    return document_.activeLayerIndex;
}

void CanvasWidget::createDocument(const QString& name, int width, int height, const QColor& backgroundColor) {
    document_.name = name.trimmed().isEmpty() ? QStringLiteral("未命名 1") : name.trimmed();
    document_.width = std::clamp(width, 320, 6000);
    document_.height = std::clamp(height, 240, 6000);
    document_.backgroundColor = backgroundColor.isValid() ? backgroundColor : QColor(QStringLiteral("#ffffff"));
    document_.layers.clear();
    LayerState baseLayer;
    baseLayer.name = QStringLiteral("背景");
    baseLayer.raster = QImage(document_.width, document_.height, QImage::Format_ARGB32_Premultiplied);
    baseLayer.raster.fill(Qt::transparent);
    document_.layers.append(baseLayer);
    document_.activeLayerIndex = 0;
    resetTransientState();
    fitToViewport();
    history_.clear();
    historyIndex_ = -1;
    pushHistorySnapshot();
    emitAllStateSignals();
    update();
}

bool CanvasWidget::openProjectFile(const QString& filePath, QString* errorMessage) {
    const QFileInfo info(filePath);
    const QString suffix = info.suffix().toLower();
    if (suffix == QStringLiteral("png") || suffix == QStringLiteral("jpg") || suffix == QStringLiteral("jpeg") || suffix == QStringLiteral("bmp") || suffix == QStringLiteral("gif") || suffix == QStringLiteral("webp") || suffix == QStringLiteral("svg")) {
        return importImageFile(filePath, errorMessage);
    }

    if (!CanvasFileCodec::loadDocument(filePath, &document_, errorMessage)) {
        return false;
    }

    resetTransientState();
    history_.clear();
    historyIndex_ = -1;
    pushHistorySnapshot();
    emitAllStateSignals();
    update();
    return true;
}

bool CanvasWidget::saveProjectFile(const QString& filePath, QString* errorMessage) const {
    return CanvasFileCodec::saveDocument(document_, [](const LayerState& layer) {
        return layer.raster;
    }, filePath, errorMessage);
}

bool CanvasWidget::exportPng(const QString& filePath, QString* errorMessage) const {
    const QImage image = compositeImage(true);
    if (!image.save(filePath, "PNG")) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("导出 PNG 失败");
        }
        return false;
    }
    return true;
}

bool CanvasWidget::exportSvg(const QString& filePath, QString* errorMessage) const {
    return CanvasFileCodec::exportSvg(document_, [this](const LayerState& layer) {
        return renderLayerImage(layer);
    }, filePath, errorMessage);
}

bool CanvasWidget::importImageFile(const QString& filePath, QString* errorMessage) {
    QImageReader reader(filePath);
    reader.setAutoTransform(true);
    const QImage source = reader.read().convertToFormat(QImage::Format_ARGB32_Premultiplied);
    if (source.isNull()) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("无法读取图片文件");
        }
        return false;
    }

    QImage transparent(document_.width, document_.height, QImage::Format_ARGB32_Premultiplied);
    transparent.fill(Qt::transparent);
    if (document_.layers.size() == 1 && document_.layers.first().texts.isEmpty() && document_.layers.first().raster == transparent) {
        createDocument(QFileInfo(filePath).completeBaseName(), std::max(source.width(), 320), std::max(source.height(), 240), QColor(QStringLiteral("#ffffff")));
    }

    LayerState layer;
    layer.name = QFileInfo(filePath).completeBaseName();
    layer.raster = QImage(document_.width, document_.height, QImage::Format_ARGB32_Premultiplied);
    layer.raster.fill(Qt::transparent);
    QPainter painter(&layer.raster);
    const qreal scale = std::min(document_.width * 0.9 / static_cast<qreal>(source.width()), document_.height * 0.9 / static_cast<qreal>(source.height()));
    const QSizeF drawSize(source.width() * std::min(scale, 1.0), source.height() * std::min(scale, 1.0));
    const QRectF target((document_.width - drawSize.width()) * 0.5, (document_.height - drawSize.height()) * 0.5, drawSize.width(), drawSize.height());
    painter.drawImage(target, source);
    document_.layers.append(layer);
    document_.activeLayerIndex = document_.layers.size() - 1;
    pushHistorySnapshot();
    emitAllStateSignals();
    update();
    return true;
}

void CanvasWidget::setActiveTool(ToolId tool) {
    if (activeTool_ == tool) {
        return;
    }

    activeTool_ = tool;
    if (isPaintTool(tool) || tool == ToolId::Eraser) {
        lastPaintTool_ = tool;
    }

    if (tool == ToolId::Brush) {
        brushName_ = QStringLiteral("画笔");
        brushSize_ = 12;
        brushOpacity_ = 60;
        brushStyle_ = {0, 100, 12, 55, 80, SizeMode::Pressure, 8};
    } else if (tool == ToolId::Pencil) {
        brushName_ = QStringLiteral("铅笔");
        brushSize_ = 6;
        brushOpacity_ = 40;
        brushStyle_ = {8, 56, 30, 78, 100, SizeMode::Pressure, 8};
    } else if (tool == ToolId::Ink) {
        brushName_ = QStringLiteral("毛笔");
        brushSize_ = 14;
        brushOpacity_ = 100;
        brushStyle_ = {18, 88, 8, 88, 100, SizeMode::Pressure, 0};
    } else if (tool == ToolId::Pen) {
        brushName_ = QStringLiteral("钢笔");
        brushSize_ = 4;
        brushOpacity_ = 100;
        brushStyle_ = {0, 100, 7, 100, 100, SizeMode::Pressure, 0};
    }

    emit toolStateChanged();
    update();
}

void CanvasWidget::setBrushColor(const QColor& color) {
    if (!color.isValid()) {
        return;
    }
    brushColor_ = color;
    emit toolStateChanged();
    update();
}

void CanvasWidget::setBrushName(const QString& name) {
    brushName_ = name.trimmed().isEmpty() ? brushName_ : name.trimmed();
    emit toolStateChanged();
}

void CanvasWidget::setBrushSize(int size) {
    brushSize_ = std::clamp(size, 1, 240);
    emit toolStateChanged();
}

void CanvasWidget::setBrushOpacity(int opacity) {
    brushOpacity_ = std::clamp(opacity, 1, 100);
    emit toolStateChanged();
}

void CanvasWidget::setPressureEnabled(bool enabled) {
    pressureEnabled_ = enabled;
    emit toolStateChanged();
}

void CanvasWidget::setBrushStyle(const BrushStyleState& style) {
    brushStyle_.angle = std::clamp(style.angle, 0, 180);
    brushStyle_.roundness = std::clamp(style.roundness, 10, 100);
    brushStyle_.spacing = std::clamp(style.spacing, 1, 80);
    brushStyle_.hardness = std::clamp(style.hardness, 1, 100);
    brushStyle_.flow = std::clamp(style.flow, 1, 100);
    brushStyle_.sizeMode = style.sizeMode;
    brushStyle_.sizeJitter = std::clamp(style.sizeJitter, 0, 80);
    emit toolStateChanged();
}

void CanvasWidget::setEraserMode(EraserMode mode) {
    eraserMode_ = mode;
    emit toolStateChanged();
}

void CanvasWidget::setShapeType(ShapeType shapeType) {
    shapeType_ = shapeType;
    emit toolStateChanged();
}

void CanvasWidget::setTextStyle(const TextStyleState& style) {
    textStyle_ = style;
    emit toolStateChanged();
}

void CanvasWidget::setFilterIntensity(int intensity) {
    filterIntensity_ = std::clamp(intensity, 0, 100);
    emit toolStateChanged();
}

void CanvasWidget::addLayer() {
    LayerState layer;
    layer.name = QStringLiteral("图层 %1").arg(document_.layers.size() + 1);
    layer.raster = QImage(document_.width, document_.height, QImage::Format_ARGB32_Premultiplied);
    layer.raster.fill(Qt::transparent);
    document_.layers.append(layer);
    document_.activeLayerIndex = document_.layers.size() - 1;
    pushHistorySnapshot();
    emitAllStateSignals();
    update();
}

void CanvasWidget::duplicateActiveLayer() {
    const LayerState* source = activeLayer();
    if (!source) {
        return;
    }
    LayerState layer = *source;
    layer.name += QStringLiteral(" 副本");
    document_.layers.insert(document_.activeLayerIndex + 1, layer);
    document_.activeLayerIndex += 1;
    pushHistorySnapshot();
    emitAllStateSignals();
    update();
}

void CanvasWidget::removeActiveLayer() {
    if (document_.layers.size() <= 1 || document_.activeLayerIndex < 0) {
        return;
    }
    document_.layers.removeAt(document_.activeLayerIndex);
    document_.activeLayerIndex = std::clamp(document_.activeLayerIndex, 0, static_cast<int>(document_.layers.size()) - 1);
    pushHistorySnapshot();
    emitAllStateSignals();
    update();
}

void CanvasWidget::moveActiveLayerUp() {
    if (document_.activeLayerIndex < 0 || document_.activeLayerIndex >= document_.layers.size() - 1) {
        return;
    }
    document_.layers.swapItemsAt(document_.activeLayerIndex, document_.activeLayerIndex + 1);
    document_.activeLayerIndex += 1;
    pushHistorySnapshot();
    emitAllStateSignals();
    update();
}

void CanvasWidget::moveActiveLayerDown() {
    if (document_.activeLayerIndex <= 0 || document_.activeLayerIndex >= document_.layers.size()) {
        return;
    }
    document_.layers.swapItemsAt(document_.activeLayerIndex, document_.activeLayerIndex - 1);
    document_.activeLayerIndex -= 1;
    pushHistorySnapshot();
    emitAllStateSignals();
    update();
}

void CanvasWidget::setActiveLayer(int index) {
    if (index < 0 || index >= document_.layers.size()) {
        return;
    }
    if (floatingSelection_.active && index != floatingSelection_.layerIndex) {
        applyFloatingSelection();
    }
    document_.activeLayerIndex = index;
    emit layerStateChanged();
    update();
}

void CanvasWidget::setLayerVisible(int index, bool visible) {
    LayerState* layer = layerAt(index);
    if (!layer) {
        return;
    }
    layer->visible = visible;
    pushHistorySnapshot();
    emit layerStateChanged();
    update();
}

void CanvasWidget::setLayerLocked(int index, bool locked) {
    LayerState* layer = layerAt(index);
    if (!layer) {
        return;
    }

    if (locked && floatingSelection_.active && floatingSelection_.layerIndex == index) {
        applyFloatingSelection();
    }

    layer->locked = locked;
    pushHistorySnapshot();
    emit layerStateChanged();
    update();
}

void CanvasWidget::setLayerOpacity(int index, qreal opacity, bool commitHistory) {
    LayerState* layer = layerAt(index);
    if (!layer) {
        return;
    }
    layer->opacity = std::clamp(opacity, 0.0, 1.0);
    if (commitHistory) {
        pushHistorySnapshot();
    }
    emit layerStateChanged();
    update();
}

void CanvasWidget::setLayerBlendMode(int index, LayerBlendMode blendMode) {
    LayerState* layer = layerAt(index);
    if (!layer) {
        return;
    }
    layer->blendMode = blendMode;
    pushHistorySnapshot();
    emit layerStateChanged();
    update();
}

void CanvasWidget::renameLayer(int index, const QString& name) {
    LayerState* layer = layerAt(index);
    if (!layer || name.trimmed().isEmpty()) {
        return;
    }
    layer->name = name.trimmed();
    pushHistorySnapshot();
    emit layerStateChanged();
}

void CanvasWidget::clearActiveLayer() {
    LayerState* layer = activeLayer();
    if (!layer || layer->locked) {
        return;
    }
    layer->raster.fill(Qt::transparent);
    layer->texts.clear();
    pushHistorySnapshot();
    emit layerStateChanged();
    update();
}

void CanvasWidget::mergeActiveLayerDown() {
    if (!canMergeActiveLayerDown()) {
        return;
    }
    rasterizeTextsIntoLayer(document_.activeLayerIndex);
    rasterizeTextsIntoLayer(document_.activeLayerIndex - 1);

    LayerState& upper = document_.layers[document_.activeLayerIndex];
    LayerState& lower = document_.layers[document_.activeLayerIndex - 1];
    QPainter painter(&lower.raster);
    painter.setOpacity(upper.opacity);
    painter.setCompositionMode(compositionModeForBlendMode(upper.blendMode));
    painter.drawImage(0, 0, upper.raster);
    document_.layers.removeAt(document_.activeLayerIndex);
    document_.activeLayerIndex -= 1;
    pushHistorySnapshot();
    emitAllStateSignals();
    update();
}

void CanvasWidget::mergeVisibleLayers() {
    QVector<int> visibleIndexes;
    for (int index = 0; index < document_.layers.size(); ++index) {
        if (document_.layers.at(index).visible) {
            if (document_.layers.at(index).locked) {
                emit statusMessageRequested(QStringLiteral("存在锁定图层，无法合并可见图层"), 2200);
                return;
            }
            visibleIndexes.append(index);
        }
    }
    if (visibleIndexes.size() < 2) {
        return;
    }

    LayerState merged;
    merged.name = QStringLiteral("合并图层");
    merged.raster = QImage(document_.width, document_.height, QImage::Format_ARGB32_Premultiplied);
    merged.raster.fill(Qt::transparent);
    QPainter painter(&merged.raster);
    for (int index : visibleIndexes) {
        LayerState layer = document_.layers.at(index);
        rasterizeTextsIntoLayer(index);
        painter.setOpacity(layer.opacity);
        painter.setCompositionMode(compositionModeForBlendMode(layer.blendMode));
        painter.drawImage(0, 0, document_.layers.at(index).raster);
    }

    for (int i = visibleIndexes.size() - 1; i >= 0; --i) {
        document_.layers.removeAt(visibleIndexes.at(i));
    }
    document_.layers.append(merged);
    document_.activeLayerIndex = document_.layers.size() - 1;
    pushHistorySnapshot();
    emitAllStateSignals();
    update();
}

void CanvasWidget::undo() {
    if (!canUndo()) {
        return;
    }
    historyIndex_ -= 1;
    restoreSnapshot(history_.at(historyIndex_));
}

void CanvasWidget::redo() {
    if (!canRedo()) {
        return;
    }
    historyIndex_ += 1;
    restoreSnapshot(history_.at(historyIndex_));
}

void CanvasWidget::zoomIn() {
    zoom_ = std::min(zoom_ * 1.1, 8.0);
    emit viewStateChanged();
    update();
}

void CanvasWidget::zoomOut() {
    zoom_ = std::max(zoom_ / 1.1, 0.2);
    emit viewStateChanged();
    update();
}

void CanvasWidget::fitToViewport() {
    const qreal widthScale = std::max(0.2, (width() - kMargin * 2) / std::max(1.0, static_cast<qreal>(document_.width)));
    const qreal heightScale = std::max(0.2, (height() - kMargin * 2) / std::max(1.0, static_cast<qreal>(document_.height)));
    fitScale_ = std::min(widthScale, heightScale);
    panOffset_ = QPointF();
    zoom_ = 1.0;
    emit viewStateChanged();
    update();
}

void CanvasWidget::resetView() {
    fitToViewport();
}

void CanvasWidget::applyFilter(FilterType filterType) {
    LayerState* layer = activeLayer();
    if (!layer || layer->locked) {
        return;
    }

    rasterizeTextsIntoLayer(document_.activeLayerIndex);
    applyPixelFilter([filterType, this](QImage& image) {
        CanvasFilters::apply(&image, filterType, filterIntensity_);
    });
}

void CanvasWidget::applyFloatingSelection() {
    if (!floatingSelection_.active) {
        return;
    }
    LayerState* layer = layerAt(floatingSelection_.layerIndex);
    if (!layer || layer->locked) {
        floatingSelection_ = FloatingSelectionState();
        return;
    }
    QPainter painter(&layer->raster);
    painter.drawImage(floatingSelection_.currentTopLeft, floatingSelection_.image);
    floatingSelection_ = FloatingSelectionState();
    pushHistorySnapshot();
    emit layerStateChanged();
    update();
}

void CanvasWidget::cancelFloatingSelection() {
    if (!floatingSelection_.active) {
        return;
    }
    LayerState* layer = layerAt(floatingSelection_.layerIndex);
    if (layer && !layer->locked) {
        QPainter painter(&layer->raster);
        painter.drawImage(floatingSelection_.originalTopLeft, floatingSelection_.image);
    }
    floatingSelection_ = FloatingSelectionState();
    emit layerStateChanged();
    update();
}

void CanvasWidget::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    drawBackground(painter);
    drawCanvas(painter);
    drawOverlays(painter);
}

void CanvasWidget::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);
    fitToViewport();
}

void CanvasWidget::mousePressEvent(QMouseEvent* event) {
    setFocus();
    const bool wantsPan = event->button() == Qt::MiddleButton || (spacePressed_ && event->button() == Qt::LeftButton);
    if (wantsPan) {
        panning_ = true;
        panStartPoint_ = event->pos();
        panStartOffset_ = panOffset_;
        return;
    }
    if (event->button() != Qt::LeftButton) {
        return;
    }

    const QPointF canvasPointF = mapToCanvas(event->position());
    if (!pointInCanvas(canvasPointF)) {
        return;
    }
    const QPoint canvasPoint = canvasPointF.toPoint();

    if (activeTool_ == ToolId::Select && floatingSelection_.active && QRect(floatingSelection_.currentTopLeft, floatingSelection_.image.size()).contains(canvasPoint)) {
        startFloatingSelectionDrag(canvasPoint);
        return;
    }

    if (activeTool_ == ToolId::Select) {
        startTextDrag(canvasPointF);
        if (textDragState_.active) {
            return;
        }
    }

    switch (activeTool_) {
    case ToolId::Brush:
    case ToolId::Pencil:
    case ToolId::Ink:
    case ToolId::Pen:
    case ToolId::Eraser:
        if (activeTool_ == ToolId::Eraser && eraserMode_ == EraserMode::Stroke) {
            clearWithStrokeEraser(canvasPoint);
        } else {
            beginStroke(canvasPointF, currentPressure_);
        }
        break;
    case ToolId::Eyedropper:
        sampleColor(canvasPoint);
        break;
    case ToolId::Fill:
        floodFill(canvasPoint);
        break;
    case ToolId::Shape:
        beginShape(canvasPoint);
        break;
    case ToolId::Text:
        createOrEditTextAt(canvasPointF);
        break;
    case ToolId::Select:
        beginSelection(canvasPoint, false);
        break;
    case ToolId::Lasso:
        beginSelection(canvasPoint, true);
        break;
    }
}

void CanvasWidget::mouseMoveEvent(QMouseEvent* event) {
    if (panning_) {
        panOffset_ = panStartOffset_ + (event->pos() - panStartPoint_);
        emit viewStateChanged();
        update();
        return;
    }

    const QPointF canvasPointF = mapToCanvas(event->position());
    const QPoint canvasPoint = canvasPointF.toPoint();
    if (strokePreview_.active) {
        continueStroke(canvasPointF, currentPressure_);
    } else if (shapePreview_.active) {
        updateShape(canvasPoint);
    } else if (selectionPreview_.active) {
        updateSelection(canvasPoint);
    } else if (floatingSelection_.dragging) {
        updateFloatingSelectionDrag(canvasPoint);
    } else if (textDragState_.active) {
        updateTextDrag(canvasPointF);
    }
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent* event) {
    if (panning_ && (event->button() == Qt::MiddleButton || event->button() == Qt::LeftButton)) {
        panning_ = false;
        return;
    }
    if (event->button() != Qt::LeftButton) {
        return;
    }

    if (strokePreview_.active) {
        endStroke();
    } else if (shapePreview_.active) {
        commitShape();
    } else if (selectionPreview_.active) {
        completeSelection();
    } else if (floatingSelection_.dragging) {
        finishFloatingSelectionDrag();
    } else if (textDragState_.active) {
        finishTextDrag();
    }
}

void CanvasWidget::mouseDoubleClickEvent(QMouseEvent* event) {
    if (event->button() != Qt::LeftButton) {
        return;
    }
    const QPointF canvasPoint = mapToCanvas(event->position());
    if (!pointInCanvas(canvasPoint)) {
        return;
    }
    createOrEditTextAt(canvasPoint);
}

void CanvasWidget::wheelEvent(QWheelEvent* event) {
    if (event->angleDelta().y() > 0) {
        zoomIn();
    } else {
        zoomOut();
    }
    event->accept();
}

void CanvasWidget::tabletEvent(QTabletEvent* event) {
    currentPressure_ = std::clamp(static_cast<qreal>(event->pressure()), 0.05, 1.0);
    event->accept();
}

void CanvasWidget::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Space) {
        spacePressed_ = true;
    }
    if (event->key() == Qt::Key_Escape) {
        cancelFloatingSelection();
    }
    QWidget::keyPressEvent(event);
}

void CanvasWidget::keyReleaseEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Space) {
        spacePressed_ = false;
    }
    QWidget::keyReleaseEvent(event);
}

bool CanvasWidget::isPaintTool(ToolId tool) const {
    return tool == ToolId::Brush || tool == ToolId::Pencil || tool == ToolId::Ink || tool == ToolId::Pen;
}

bool CanvasWidget::isBrushTool(ToolId tool) const {
    return isPaintTool(tool) || tool == ToolId::Eraser;
}

bool CanvasWidget::isShapeTool(ToolId tool) const {
    return tool == ToolId::Shape;
}

void CanvasWidget::initializeDefaults() {
    colorPresets_ = {
        QColor(QStringLiteral("#101114")),
        QColor(QStringLiteral("#f97316")),
        QColor(QStringLiteral("#ef4444")),
        QColor(QStringLiteral("#f59e0b")),
        QColor(QStringLiteral("#16a34a")),
        QColor(QStringLiteral("#06b6d4")),
        QColor(QStringLiteral("#2563eb")),
        QColor(QStringLiteral("#7c3aed")),
        QColor(QStringLiteral("#f8fafc"))
    };
    brushStyle_ = {0, 100, 12, 55, 80, SizeMode::Pressure, 8};
}

void CanvasWidget::resetTransientState() {
    floatingSelection_ = FloatingSelectionState();
    selectionPreview_ = SelectionPreview();
    shapePreview_ = ShapePreview();
    strokePreview_ = StrokePreview();
    textDragState_ = TextDragState();
}

void CanvasWidget::emitAllStateSignals() {
    emit documentStateChanged();
    emit toolStateChanged();
    emit layerStateChanged();
    emit historyStateChanged();
    emit viewStateChanged();
}

void CanvasWidget::pushHistorySnapshot() {
    if (historyIndex_ < history_.size() - 1) {
        history_.resize(historyIndex_ + 1);
    }
    history_.append({document_});
    historyIndex_ = history_.size() - 1;
    emit historyStateChanged();
}

void CanvasWidget::restoreSnapshot(const DocumentSnapshot& snapshot) {
    document_ = snapshot.document;
    floatingSelection_ = FloatingSelectionState();
    emitAllStateSignals();
    update();
}

CanvasWidget::LayerState* CanvasWidget::activeLayer() {
    return layerAt(document_.activeLayerIndex);
}

const CanvasWidget::LayerState* CanvasWidget::activeLayer() const {
    return layerAt(document_.activeLayerIndex);
}

CanvasWidget::LayerState* CanvasWidget::layerAt(int index) {
    if (index < 0 || index >= document_.layers.size()) {
        return nullptr;
    }
    return &document_.layers[index];
}

const CanvasWidget::LayerState* CanvasWidget::layerAt(int index) const {
    if (index < 0 || index >= document_.layers.size()) {
        return nullptr;
    }
    return &document_.layers[index];
}

QRectF CanvasWidget::canvasRectF() const {
    const qreal scale = zoomFactor();
    const QSizeF size(document_.width * scale, document_.height * scale);
    QPointF topLeft((width() - size.width()) * 0.5, (height() - size.height()) * 0.5);
    topLeft += panOffset_;
    return QRectF(topLeft, size);
}

QPointF CanvasWidget::mapToCanvas(const QPointF& widgetPoint) const {
    const QRectF rect = canvasRectF();
    const qreal scale = zoomFactor();
    return QPointF((widgetPoint.x() - rect.left()) / scale, (widgetPoint.y() - rect.top()) / scale);
}

QPointF CanvasWidget::mapFromCanvas(const QPointF& canvasPoint) const {
    const QRectF rect = canvasRectF();
    const qreal scale = zoomFactor();
    return QPointF(rect.left() + canvasPoint.x() * scale, rect.top() + canvasPoint.y() * scale);
}

bool CanvasWidget::pointInCanvas(const QPointF& canvasPoint) const {
    return canvasPoint.x() >= 0 && canvasPoint.y() >= 0 && canvasPoint.x() < document_.width && canvasPoint.y() < document_.height;
}

void CanvasWidget::drawBackground(QPainter& painter) {
    painter.fillRect(rect(), QColor(QStringLiteral("#1f2937")));
}

void CanvasWidget::drawCanvas(QPainter& painter) {
    const QRectF rect = canvasRectF();
    painter.fillRect(rect.adjusted(-1, -1, 1, 1), QColor(QStringLiteral("#111827")));
    painter.drawImage(rect, compositeImage(true));
    painter.setPen(QPen(QColor(QStringLiteral("#94a3b8")), 1));
    painter.drawRect(rect);
}

void CanvasWidget::drawOverlays(QPainter& painter) {
    const qreal scale = zoomFactor();
    painter.save();
    painter.translate(canvasRectF().topLeft());
    painter.scale(scale, scale);
    painter.setRenderHint(QPainter::Antialiasing, true);

    if (shapePreview_.active) {
        QPainterPath path = buildShapePath(shapeType_, QRectF(shapePreview_.start, shapePreview_.current).normalized());
        painter.setPen(QPen(QColor(QStringLiteral("#38bdf8")), 1.0 / scale, Qt::DashLine));
        painter.drawPath(path);
    }

    if (selectionPreview_.active) {
        painter.setPen(QPen(QColor(QStringLiteral("#fbbf24")), 1.0 / scale, Qt::DashLine));
        if (selectionPreview_.lasso) {
            painter.drawPath(selectionPreview_.path);
        } else {
            painter.drawRect(QRect(selectionPreview_.start, selectionPreview_.current).normalized());
        }
    }

    if (floatingSelection_.active) {
        painter.setPen(QPen(QColor(QStringLiteral("#f59e0b")), 1.0 / scale, Qt::DashLine));
        painter.drawRect(QRect(floatingSelection_.currentTopLeft, floatingSelection_.image.size()));
    }

    const LayerState* layer = activeLayer();
    if (layer) {
        painter.setPen(QPen(QColor(QStringLiteral("#38bdf8")), 1.0 / scale, Qt::DashLine));
        for (int index = 0; index < layer->texts.size(); ++index) {
            painter.drawRect(layer->texts.at(index).rect);
        }
    }

    painter.restore();
}

QImage CanvasWidget::renderLayerImage(const LayerState& layer) const {
    QImage result = layer.raster;
    QPainter painter(&result);
    painter.setRenderHint(QPainter::Antialiasing, true);
    for (const TextElement& text : layer.texts) {
        drawWrappedText(&painter, text);
    }
    return result;
}

QImage CanvasWidget::compositeImage(bool includeFloatingSelection) const {
    QImage composite(document_.width, document_.height, QImage::Format_ARGB32_Premultiplied);
    composite.fill(document_.backgroundColor);
    QPainter painter(&composite);
    painter.setRenderHint(QPainter::Antialiasing, true);
    for (int index = 0; index < document_.layers.size(); ++index) {
        const LayerState& layer = document_.layers.at(index);
        if (!layer.visible) {
            continue;
        }
        painter.setOpacity(layer.opacity);
        painter.setCompositionMode(compositionModeForBlendMode(layer.blendMode));
        painter.drawImage(0, 0, renderLayerImage(layer));
    }
    if (includeFloatingSelection && floatingSelection_.active) {
        painter.setOpacity(1.0);
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
        painter.drawImage(floatingSelection_.currentTopLeft, floatingSelection_.image);
    }
    return composite;
}

QImage CanvasWidget::thumbnailForLayer(const LayerState& layer) const {
    return renderLayerImage(layer).scaled(64, 48, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

QPainter::CompositionMode CanvasWidget::compositionModeForBlendMode(LayerBlendMode blendMode) const {
    switch (blendMode) {
    case LayerBlendMode::Multiply: return QPainter::CompositionMode_Multiply;
    case LayerBlendMode::Screen: return QPainter::CompositionMode_Screen;
    case LayerBlendMode::Overlay: return QPainter::CompositionMode_Overlay;
    case LayerBlendMode::Darken: return QPainter::CompositionMode_Darken;
    case LayerBlendMode::Lighten: return QPainter::CompositionMode_Lighten;
    case LayerBlendMode::SourceOver: return QPainter::CompositionMode_SourceOver;
    }
    return QPainter::CompositionMode_SourceOver;
}

void CanvasWidget::beginStroke(const QPointF& canvasPoint, qreal pressure) {
    LayerState* layer = activeLayer();
    if (!layer || layer->locked) {
        return;
    }
    if (floatingSelection_.active) {
        applyFloatingSelection();
    }
    strokePreview_.active = true;
    strokePreview_.lastPoint = canvasPoint;
    paintStrokeSegment(layer->raster, canvasPoint, canvasPoint, pressure, activeTool_ == ToolId::Eraser);
    update();
}

void CanvasWidget::continueStroke(const QPointF& canvasPoint, qreal pressure) {
    LayerState* layer = activeLayer();
    if (!strokePreview_.active || !layer || layer->locked) {
        return;
    }
    paintStrokeSegment(layer->raster, strokePreview_.lastPoint, canvasPoint, pressure, activeTool_ == ToolId::Eraser);
    strokePreview_.lastPoint = canvasPoint;
    update();
}

void CanvasWidget::endStroke() {
    if (!strokePreview_.active) {
        return;
    }
    strokePreview_ = StrokePreview();
    pushHistorySnapshot();
    emit layerStateChanged();
    update();
}

void CanvasWidget::paintStrokeSegment(QImage& target, const QPointF& from, const QPointF& to, qreal pressure, bool clearMode) {
    QPainter painter(&target);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setOpacity((brushOpacity_ / 100.0) * (brushStyle_.flow / 100.0));
    painter.setCompositionMode(clearMode ? QPainter::CompositionMode_Clear : QPainter::CompositionMode_SourceOver);
    QPen pen(clearMode ? Qt::transparent : brushColor_);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setWidthF(effectiveBrushSize(pressure));
    painter.setPen(pen);
    painter.drawLine(from, to);
}

qreal CanvasWidget::effectiveBrushSize(qreal pressure) const {
    qreal size = brushSize_;
    if (pressureEnabled_ && brushStyle_.sizeMode == SizeMode::Pressure) {
        size *= std::clamp(pressure, 0.05, 1.0);
    }
    if (brushStyle_.sizeMode == SizeMode::Random && brushStyle_.sizeJitter > 0) {
        const qreal delta = QRandomGenerator::global()->bounded(-brushStyle_.sizeJitter, brushStyle_.sizeJitter + 1) / 100.0;
        size *= (1.0 + delta);
    }
    return std::max(size, 1.0);
}

QColor CanvasWidget::effectiveBrushColor() const {
    return withOpacity(brushColor_, brushOpacity_ / 100.0);
}

void CanvasWidget::clearWithStrokeEraser(const QPoint& canvasPoint) {
    LayerState* layer = activeLayer();
    if (!layer || layer->locked || !QRect(0, 0, document_.width, document_.height).contains(canvasPoint)) {
        return;
    }

    const QColor start = QColor::fromRgba(layer->raster.pixel(canvasPoint));
    if (start.alpha() == 0) {
        return;
    }

    const auto isSimilar = [&start](const QColor& color) {
        const int tolerance = 24;
        return std::abs(color.red() - start.red()) <= tolerance
            && std::abs(color.green() - start.green()) <= tolerance
            && std::abs(color.blue() - start.blue()) <= tolerance
            && std::abs(color.alpha() - start.alpha()) <= tolerance;
    };

    QQueue<QPoint> queue;
    QVector<QVector<bool>> visited(document_.height, QVector<bool>(document_.width, false));
    queue.enqueue(canvasPoint);
    visited[canvasPoint.y()][canvasPoint.x()] = true;

    while (!queue.isEmpty()) {
        const QPoint point = queue.dequeue();
        layer->raster.setPixelColor(point, QColor(0, 0, 0, 0));
        const QPoint neighbors[] = {QPoint(point.x() + 1, point.y()), QPoint(point.x() - 1, point.y()), QPoint(point.x(), point.y() + 1), QPoint(point.x(), point.y() - 1)};
        for (const QPoint& neighbor : neighbors) {
            if (!QRect(0, 0, document_.width, document_.height).contains(neighbor) || visited[neighbor.y()][neighbor.x()]) {
                continue;
        }
        visited[neighbor.y()][neighbor.x()] = true;
            if (isSimilar(QColor::fromRgba(layer->raster.pixel(neighbor)))) {
                queue.enqueue(neighbor);
            }
        }
    }

    pushHistorySnapshot();
    emit layerStateChanged();
    update();
}

void CanvasWidget::floodFill(const QPoint& canvasPoint) {
    LayerState* layer = activeLayer();
    if (!layer || layer->locked) {
        return;
    }
    rasterizeTextsIntoLayer(document_.activeLayerIndex);
    const QColor target = QColor::fromRgba(layer->raster.pixel(canvasPoint));
    const QColor replacement = effectiveBrushColor();
    if (target == replacement) {
        return;
    }

    QQueue<QPoint> queue;
    QVector<QVector<bool>> visited(document_.height, QVector<bool>(document_.width, false));
    queue.enqueue(canvasPoint);
    visited[canvasPoint.y()][canvasPoint.x()] = true;

    while (!queue.isEmpty()) {
        const QPoint point = queue.dequeue();
        if (QColor::fromRgba(layer->raster.pixel(point)) != target) {
            continue;
        }
        layer->raster.setPixelColor(point, replacement);
        const QPoint neighbors[] = {QPoint(point.x() + 1, point.y()), QPoint(point.x() - 1, point.y()), QPoint(point.x(), point.y() + 1), QPoint(point.x(), point.y() - 1)};
        for (const QPoint& neighbor : neighbors) {
            if (!QRect(0, 0, document_.width, document_.height).contains(neighbor) || visited[neighbor.y()][neighbor.x()]) {
                continue;
            }
            visited[neighbor.y()][neighbor.x()] = true;
            queue.enqueue(neighbor);
        }
    }

    pushHistorySnapshot();
    emit layerStateChanged();
    update();
}

void CanvasWidget::beginShape(const QPoint& canvasPoint) {
    LayerState* layer = activeLayer();
    if (!layer || layer->locked) {
        return;
    }
    shapePreview_.active = true;
    shapePreview_.start = canvasPoint;
    shapePreview_.current = canvasPoint;
    update();
}

void CanvasWidget::updateShape(const QPoint& canvasPoint) {
    shapePreview_.current = canvasPoint;
    update();
}

void CanvasWidget::commitShape() {
    LayerState* layer = activeLayer();
    if (!shapePreview_.active || !layer || layer->locked) {
        shapePreview_ = ShapePreview();
        return;
    }

    rasterizeTextsIntoLayer(document_.activeLayerIndex);
    QPainter painter(&layer->raster);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPen pen(brushColor_);
    pen.setWidthF(std::max(1.0, static_cast<qreal>(brushSize_)));
    painter.setOpacity(brushOpacity_ / 100.0);
    painter.setPen(pen);
    painter.drawPath(buildShapePath(shapeType_, QRectF(shapePreview_.start, shapePreview_.current).normalized()));
    shapePreview_ = ShapePreview();
    pushHistorySnapshot();
    emit layerStateChanged();
    update();
}

QPainterPath CanvasWidget::buildShapePath(ShapeType shapeType, const QRectF& rect) const {
    QPainterPath path;
    switch (shapeType) {
    case ShapeType::Line:
        path.moveTo(rect.topLeft());
        path.lineTo(rect.bottomRight());
        break;
    case ShapeType::Curve: {
        path.moveTo(rect.bottomLeft());
        path.quadTo(QPointF(rect.center().x(), rect.top()), rect.bottomRight());
        break;
    }
    case ShapeType::Ellipse:
        path.addEllipse(rect);
        break;
    case ShapeType::Rectangle:
        path.addRect(rect);
        break;
    case ShapeType::RoundedRectangle:
        path.addRoundedRect(rect, 18.0, 18.0);
        break;
    case ShapeType::Triangle:
        path.moveTo(rect.center().x(), rect.top());
        path.lineTo(rect.bottomRight());
        path.lineTo(rect.bottomLeft());
        path.closeSubpath();
        break;
    case ShapeType::Diamond:
        path.moveTo(rect.center().x(), rect.top());
        path.lineTo(rect.right(), rect.center().y());
        path.lineTo(rect.center().x(), rect.bottom());
        path.lineTo(rect.left(), rect.center().y());
        path.closeSubpath();
        break;
    case ShapeType::Pentagon:
        path = regularPolygonPath(rect, 5);
        break;
    case ShapeType::Hexagon:
        path = regularPolygonPath(rect, 6);
        break;
    case ShapeType::RightArrow:
    case ShapeType::LeftArrow:
    case ShapeType::UpArrow:
    case ShapeType::DownArrow: {
        const QRectF r = rect.normalized();
        if (shapeType == ShapeType::RightArrow) {
            path.moveTo(r.left(), r.top() + r.height() * 0.3);
            path.lineTo(r.left() + r.width() * 0.55, r.top() + r.height() * 0.3);
            path.lineTo(r.left() + r.width() * 0.55, r.top());
            path.lineTo(r.right(), r.center().y());
            path.lineTo(r.left() + r.width() * 0.55, r.bottom());
            path.lineTo(r.left() + r.width() * 0.55, r.top() + r.height() * 0.7);
            path.lineTo(r.left(), r.top() + r.height() * 0.7);
        } else if (shapeType == ShapeType::LeftArrow) {
            path.moveTo(r.right(), r.top() + r.height() * 0.3);
            path.lineTo(r.left() + r.width() * 0.45, r.top() + r.height() * 0.3);
            path.lineTo(r.left() + r.width() * 0.45, r.top());
            path.lineTo(r.left(), r.center().y());
            path.lineTo(r.left() + r.width() * 0.45, r.bottom());
            path.lineTo(r.left() + r.width() * 0.45, r.top() + r.height() * 0.7);
            path.lineTo(r.right(), r.top() + r.height() * 0.7);
        } else if (shapeType == ShapeType::UpArrow) {
            path.moveTo(r.left() + r.width() * 0.3, r.bottom());
            path.lineTo(r.left() + r.width() * 0.3, r.top() + r.height() * 0.45);
            path.lineTo(r.left(), r.top() + r.height() * 0.45);
            path.lineTo(r.center().x(), r.top());
            path.lineTo(r.right(), r.top() + r.height() * 0.45);
            path.lineTo(r.left() + r.width() * 0.7, r.top() + r.height() * 0.45);
            path.lineTo(r.left() + r.width() * 0.7, r.bottom());
        } else {
            path.moveTo(r.left() + r.width() * 0.3, r.top());
            path.lineTo(r.left() + r.width() * 0.3, r.top() + r.height() * 0.55);
            path.lineTo(r.left(), r.top() + r.height() * 0.55);
            path.lineTo(r.center().x(), r.bottom());
            path.lineTo(r.right(), r.top() + r.height() * 0.55);
            path.lineTo(r.left() + r.width() * 0.7, r.top() + r.height() * 0.55);
            path.lineTo(r.left() + r.width() * 0.7, r.top());
        }
        path.closeSubpath();
        break;
    }
    case ShapeType::Star4:
        path = starPath(rect, 4);
        break;
    case ShapeType::Star5:
        path = starPath(rect, 5);
        break;
    case ShapeType::ChatBubble:
        path.addRoundedRect(rect.adjusted(0, 0, 0, -rect.height() * 0.18), 18.0, 18.0);
        path.moveTo(rect.left() + rect.width() * 0.28, rect.bottom() - rect.height() * 0.18);
        path.lineTo(rect.left() + rect.width() * 0.42, rect.bottom());
        path.lineTo(rect.left() + rect.width() * 0.5, rect.bottom() - rect.height() * 0.18);
        break;
    case ShapeType::Heart: {
        const QPointF center = rect.center();
        path.moveTo(center.x(), rect.bottom());
        path.cubicTo(rect.right(), rect.top() + rect.height() * 0.68, rect.right(), rect.top() + rect.height() * 0.2, center.x(), rect.top() + rect.height() * 0.32);
        path.cubicTo(rect.left(), rect.top() + rect.height() * 0.2, rect.left(), rect.top() + rect.height() * 0.68, center.x(), rect.bottom());
        break;
    }
    }
    return path;
}

void CanvasWidget::beginSelection(const QPoint& canvasPoint, bool lasso) {
    LayerState* layer = activeLayer();
    if (!layer || layer->locked) {
        return;
    }
    selectionPreview_.active = true;
    selectionPreview_.lasso = lasso;
    selectionPreview_.start = canvasPoint;
    selectionPreview_.current = canvasPoint;
    selectionPreview_.path = QPainterPath(canvasPoint);
    update();
}

void CanvasWidget::updateSelection(const QPoint& canvasPoint) {
    if (!selectionPreview_.active) {
        return;
    }
    selectionPreview_.current = canvasPoint;
    if (selectionPreview_.lasso) {
        selectionPreview_.path.lineTo(canvasPoint);
    }
    update();
}

void CanvasWidget::completeSelection() {
    if (!selectionPreview_.active) {
        return;
    }
    QPainterPath path;
    if (selectionPreview_.lasso) {
        path = selectionPreview_.path;
        path.closeSubpath();
    } else {
        path.addRect(QRect(selectionPreview_.start, selectionPreview_.current).normalized());
    }
    selectionPreview_ = SelectionPreview();
    captureSelectionFromPath(path);
}

void CanvasWidget::captureSelectionFromPath(const QPainterPath& path) {
    LayerState* layer = activeLayer();
    if (!layer || layer->locked) {
        return;
    }
    rasterizeTextsIntoLayer(document_.activeLayerIndex);
    const QRect bounds = path.boundingRect().toAlignedRect().intersected(QRect(0, 0, document_.width, document_.height));
    if (bounds.width() < 2 || bounds.height() < 2) {
        update();
        return;
    }

    QImage extracted(bounds.size(), QImage::Format_ARGB32_Premultiplied);
    extracted.fill(Qt::transparent);
    {
        QPainter painter(&extracted);
        painter.setClipPath(path.translated(-bounds.topLeft()));
        painter.drawImage(-bounds.topLeft(), layer->raster);
    }
    {
        QPainter painter(&layer->raster);
        painter.setCompositionMode(QPainter::CompositionMode_Clear);
        painter.fillPath(path, Qt::transparent);
    }

    floatingSelection_.active = true;
    floatingSelection_.layerIndex = document_.activeLayerIndex;
    floatingSelection_.image = extracted;
    floatingSelection_.currentTopLeft = bounds.topLeft();
    floatingSelection_.originalTopLeft = bounds.topLeft();
    emit layerStateChanged();
    update();
}

void CanvasWidget::startFloatingSelectionDrag(const QPoint& canvasPoint) {
    floatingSelection_.dragging = true;
    floatingSelection_.dragOffset = canvasPoint - floatingSelection_.currentTopLeft;
}

void CanvasWidget::updateFloatingSelectionDrag(const QPoint& canvasPoint) {
    floatingSelection_.currentTopLeft = canvasPoint - floatingSelection_.dragOffset;
    update();
}

void CanvasWidget::finishFloatingSelectionDrag() {
    floatingSelection_.dragging = false;
    update();
}

int CanvasWidget::hitTextElement(const QPointF& canvasPoint, int* layerIndex) const {
    for (int currentLayer = document_.layers.size() - 1; currentLayer >= 0; --currentLayer) {
        const LayerState& layer = document_.layers.at(currentLayer);
        if (!layer.visible) {
            continue;
        }
        for (int textIndex = layer.texts.size() - 1; textIndex >= 0; --textIndex) {
            if (layer.texts.at(textIndex).rect.contains(canvasPoint)) {
                if (layerIndex) {
                    *layerIndex = currentLayer;
                }
                return textIndex;
            }
        }
    }
    return -1;
}

void CanvasWidget::createOrEditTextAt(const QPointF& canvasPoint) {
    int layerIndex = -1;
    const int textIndex = hitTextElement(canvasPoint, &layerIndex);
    if (textIndex >= 0 && layerIndex >= 0) {
        if (document_.layers[layerIndex].locked) {
            return;
        }
        TextElement& text = document_.layers[layerIndex].texts[textIndex];
        bool accepted = false;
        const QString value = QInputDialog::getMultiLineText(this, QStringLiteral("编辑文字"), QStringLiteral("内容"), text.text, &accepted);
        if (accepted) {
            text.text = value;
            pushHistorySnapshot();
            emit layerStateChanged();
            update();
        }
        return;
    }

    bool accepted = false;
    const QString value = QInputDialog::getMultiLineText(this, QStringLiteral("添加文字"), QStringLiteral("内容"), QString(), &accepted);
    if (!accepted || value.trimmed().isEmpty()) {
        return;
    }

    LayerState* layer = activeLayer();
    if (!layer || layer->locked) {
        return;
    }
    TextElement text;
    text.id = createId();
    text.rect = QRectF(canvasPoint, QSizeF(260, 120));
    text.text = value;
    text.style = textStyle_;
    layer->texts.append(text);
    pushHistorySnapshot();
    emit layerStateChanged();
    update();
}

void CanvasWidget::startTextDrag(const QPointF& canvasPoint) {
    int layerIndex = -1;
    const int textIndex = hitTextElement(canvasPoint, &layerIndex);
    if (textIndex < 0 || layerIndex < 0 || document_.layers[layerIndex].locked) {
        return;
    }
    textDragState_.active = true;
    textDragState_.layerIndex = layerIndex;
    textDragState_.textIndex = textIndex;
    textDragState_.offset = canvasPoint - document_.layers[layerIndex].texts[textIndex].rect.topLeft();
}

void CanvasWidget::updateTextDrag(const QPointF& canvasPoint) {
    if (!textDragState_.active) {
        return;
    }
    TextElement& text = document_.layers[textDragState_.layerIndex].texts[textDragState_.textIndex];
    text.rect.moveTopLeft(canvasPoint - textDragState_.offset);
    update();
}

void CanvasWidget::finishTextDrag() {
    if (!textDragState_.active) {
        return;
    }
    textDragState_ = TextDragState();
    pushHistorySnapshot();
    emit layerStateChanged();
    update();
}

void CanvasWidget::rasterizeTextsIntoLayer(int layerIndex) {
    LayerState* layer = layerAt(layerIndex);
    if (!layer || layer->texts.isEmpty()) {
        return;
    }
    layer->raster = renderLayerImage(*layer);
    layer->texts.clear();
}

void CanvasWidget::sampleColor(const QPoint& canvasPoint) {
    const QColor sampled = QColor::fromRgba(compositeImage(true).pixel(canvasPoint));
    setBrushColor(sampled);
    emit statusMessageRequested(QStringLiteral("已吸取颜色 %1").arg(sampled.name(QColor::HexRgb)), 1800);
}

void CanvasWidget::applyTransformToActiveLayer(const std::function<void(QPainter&, const QImage&)>& painterFn) {
    LayerState* layer = activeLayer();
    if (!layer || layer->locked) {
        return;
    }
    rasterizeTextsIntoLayer(document_.activeLayerIndex);
    QImage source = layer->raster;
    layer->raster.fill(Qt::transparent);
    QPainter painter(&layer->raster);
    painterFn(painter, source);
    pushHistorySnapshot();
    emit layerStateChanged();
    update();
}

void CanvasWidget::applyPixelFilter(const std::function<void(QImage&)>& filterFn) {
    LayerState* layer = activeLayer();
    if (!layer || layer->locked) {
        return;
    }
    filterFn(layer->raster);
    pushHistorySnapshot();
    emit layerStateChanged();
    update();
}
