#pragma once

#include <QColor>
#include <QFont>
#include <QImage>
#include <QPainterPath>
#include <QPainter>
#include <QPoint>
#include <QSize>
#include <QString>
#include <QVector>
#include <QWidget>

#include <functional>

#include "canvassharedtypes.h"

class CanvasWidget : public QWidget {
    Q_OBJECT

public:
    using ToolId = CanvasTypes::ToolId;
    using ShapeType = CanvasTypes::ShapeType;
    using LayerBlendMode = CanvasTypes::LayerBlendMode;
    using SizeMode = CanvasTypes::SizeMode;
    using EraserMode = CanvasTypes::EraserMode;
    using FilterType = CanvasTypes::FilterType;
    using BrushStyleState = CanvasTypes::BrushStyleState;
    using TextStyleState = CanvasTypes::TextStyleState;
    using BrushPanelCopy = CanvasTypes::BrushPanelCopy;
    using LayerSummary = CanvasTypes::LayerSummary;
    using TextElement = CanvasTypes::TextElement;
    using LayerState = CanvasTypes::LayerState;
    using DocumentState = CanvasTypes::DocumentState;

    explicit CanvasWidget(QWidget* parent = nullptr);

    QString documentName() const;
    QSize documentSize() const;
    QColor backgroundColor() const;
    ToolId activeTool() const;
    QString activeToolLabel() const;
    QString zoomLabel() const;
    qreal zoomFactor() const;
    bool canUndo() const;
    bool canRedo() const;
    bool hasFloatingSelection() const;
    bool canMergeActiveLayerDown() const;
    bool hasEditableActiveLayer() const;

    QColor brushColor() const;
    QString brushName() const;
    int brushSize() const;
    int brushOpacity() const;
    bool pressureEnabled() const;
    BrushStyleState brushStyle() const;
    BrushPanelCopy brushPanelCopy() const;
    EraserMode eraserMode() const;
    ShapeType shapeType() const;
    TextStyleState textStyle() const;
    int filterIntensity() const;

    QVector<QString> colorPresets() const;
    QVector<LayerSummary> layerSummaries() const;
    int activeLayerIndex() const;

    void createDocument(const QString& name, int width, int height, const QColor& backgroundColor);
    bool openProjectFile(const QString& filePath, QString* errorMessage = nullptr);
    bool saveProjectFile(const QString& filePath, QString* errorMessage = nullptr) const;
    bool exportPng(const QString& filePath, QString* errorMessage = nullptr) const;
    bool exportSvg(const QString& filePath, QString* errorMessage = nullptr) const;
    bool importImageFile(const QString& filePath, QString* errorMessage = nullptr);

    void setActiveTool(ToolId tool);
    void setBrushColor(const QColor& color);
    void setBrushName(const QString& name);
    void setBrushSize(int size);
    void setBrushOpacity(int opacity);
    void setPressureEnabled(bool enabled);
    void setBrushStyle(const BrushStyleState& style);
    void setEraserMode(EraserMode mode);
    void setShapeType(ShapeType shapeType);
    void setTextStyle(const TextStyleState& style);
    void setFilterIntensity(int intensity);

    void addLayer();
    void duplicateActiveLayer();
    void removeActiveLayer();
    void moveActiveLayerUp();
    void moveActiveLayerDown();
    void setActiveLayer(int index);
    void setLayerVisible(int index, bool visible);
    void setLayerLocked(int index, bool locked);
    void setLayerOpacity(int index, qreal opacity, bool commitHistory = true);
    void setLayerBlendMode(int index, LayerBlendMode blendMode);
    void renameLayer(int index, const QString& name);
    void clearActiveLayer();
    void mergeActiveLayerDown();
    void mergeVisibleLayers();

    void undo();
    void redo();
    void zoomIn();
    void zoomOut();
    void fitToViewport();
    void resetView();

    void applyFilter(FilterType filterType);
    void applyFloatingSelection();
    void cancelFloatingSelection();

signals:
    void documentStateChanged();
    void toolStateChanged();
    void layerStateChanged();
    void historyStateChanged();
    void viewStateChanged();
    void statusMessageRequested(const QString& message, int timeoutMs = 0);

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
    void tabletEvent(QTabletEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

private:
    struct FloatingSelectionState {
        bool active = false;
        int layerIndex = -1;
        QImage image;
        QPoint currentTopLeft;
        QPoint originalTopLeft;
        bool dragging = false;
        QPoint dragOffset;
    };

    struct DocumentSnapshot {
        DocumentState document;
    };

    struct ShapePreview {
        bool active = false;
        QPoint start;
        QPoint current;
    };

    struct StrokePreview {
        bool active = false;
        QPointF lastPoint;
    };

    struct SelectionPreview {
        bool active = false;
        bool lasso = false;
        QPoint start;
        QPoint current;
        QPainterPath path;
    };

    struct TextDragState {
        bool active = false;
        int layerIndex = -1;
        int textIndex = -1;
        QPointF offset;
    };

    bool isPaintTool(ToolId tool) const;
    bool isBrushTool(ToolId tool) const;
    bool isShapeTool(ToolId tool) const;

    void initializeDefaults();
    void resetTransientState();
    void emitAllStateSignals();
    void pushHistorySnapshot();
    void restoreSnapshot(const DocumentSnapshot& snapshot);

    LayerState* activeLayer();
    const LayerState* activeLayer() const;
    LayerState* layerAt(int index);
    const LayerState* layerAt(int index) const;

    QRectF canvasRectF() const;
    QPointF mapToCanvas(const QPointF& widgetPoint) const;
    QPointF mapFromCanvas(const QPointF& canvasPoint) const;
    bool pointInCanvas(const QPointF& canvasPoint) const;

    void drawBackground(QPainter& painter);
    void drawCanvas(QPainter& painter);
    void drawOverlays(QPainter& painter);
    QImage renderLayerImage(const LayerState& layer) const;
    QImage compositeImage(bool includeFloatingSelection) const;
    QImage thumbnailForLayer(const LayerState& layer) const;
    QPainter::CompositionMode compositionModeForBlendMode(LayerBlendMode blendMode) const;

    void beginStroke(const QPointF& canvasPoint, qreal pressure);
    void continueStroke(const QPointF& canvasPoint, qreal pressure);
    void endStroke();
    void paintStrokeSegment(QImage& target, const QPointF& from, const QPointF& to, qreal pressure, bool clearMode);
    qreal effectiveBrushSize(qreal pressure) const;
    QColor effectiveBrushColor() const;
    void clearWithStrokeEraser(const QPoint& canvasPoint);
    void floodFill(const QPoint& canvasPoint);

    void beginShape(const QPoint& canvasPoint);
    void updateShape(const QPoint& canvasPoint);
    void commitShape();
    QPainterPath buildShapePath(ShapeType shapeType, const QRectF& rect) const;

    void beginSelection(const QPoint& canvasPoint, bool lasso);
    void updateSelection(const QPoint& canvasPoint);
    void completeSelection();
    void captureSelectionFromPath(const QPainterPath& path);
    void startFloatingSelectionDrag(const QPoint& canvasPoint);
    void updateFloatingSelectionDrag(const QPoint& canvasPoint);
    void finishFloatingSelectionDrag();

    int hitTextElement(const QPointF& canvasPoint, int* layerIndex = nullptr) const;
    void createOrEditTextAt(const QPointF& canvasPoint);
    void startTextDrag(const QPointF& canvasPoint);
    void updateTextDrag(const QPointF& canvasPoint);
    void finishTextDrag();
    void rasterizeTextsIntoLayer(int layerIndex);

    void sampleColor(const QPoint& canvasPoint);
    void applyTransformToActiveLayer(const std::function<void(QPainter&, const QImage&)>& painterFn);
    void applyPixelFilter(const std::function<void(QImage&)>& filterFn);

    DocumentState document_;
    QVector<DocumentSnapshot> history_;
    int historyIndex_ = -1;

    ToolId activeTool_ = ToolId::Brush;
    ToolId lastPaintTool_ = ToolId::Brush;
    QColor brushColor_ = QColor(QStringLiteral("#000000"));
    QString brushName_ = QStringLiteral("画笔");
    int brushSize_ = 12;
    int brushOpacity_ = 60;
    bool pressureEnabled_ = true;
    qreal currentPressure_ = 1.0;
    BrushStyleState brushStyle_;
    EraserMode eraserMode_ = EraserMode::Normal;
    ShapeType shapeType_ = ShapeType::Line;
    TextStyleState textStyle_;
    int filterIntensity_ = 60;
    QVector<QColor> colorPresets_;

    qreal zoom_ = 1.0;
    QPointF panOffset_;
    bool spacePressed_ = false;
    bool panning_ = false;
    QPoint panStartPoint_;
    QPointF panStartOffset_;

    StrokePreview strokePreview_;
    ShapePreview shapePreview_;
    SelectionPreview selectionPreview_;
    FloatingSelectionState floatingSelection_;
    TextDragState textDragState_;

    qreal fitScale_ = 1.0;
};
