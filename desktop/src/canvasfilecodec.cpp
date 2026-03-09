#include "canvasfilecodec.h"

#include <QBuffer>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPainter>
#include <QSaveFile>

#include <algorithm>

QString CanvasFileCodec::imageToBase64(const QImage& image) {
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG");
    return QString::fromLatin1(bytes.toBase64());
}

QImage CanvasFileCodec::imageFromBase64(const QString& base64) {
    const QByteArray bytes = QByteArray::fromBase64(base64.toLatin1());
    QImage image;
    image.loadFromData(bytes, "PNG");
    return image;
}

QString CanvasFileCodec::escapeXml(const QString& text) {
    QString escaped = text;
    escaped.replace('&', QStringLiteral("&amp;"));
    escaped.replace('<', QStringLiteral("&lt;"));
    escaped.replace('>', QStringLiteral("&gt;"));
    escaped.replace('"', QStringLiteral("&quot;"));
    escaped.replace('\'', QStringLiteral("&apos;"));
    return escaped;
}

QString CanvasFileCodec::blendModeToString(CanvasTypes::LayerBlendMode blendMode) {
    switch (blendMode) {
    case CanvasTypes::LayerBlendMode::Multiply: return QStringLiteral("multiply");
    case CanvasTypes::LayerBlendMode::Screen: return QStringLiteral("screen");
    case CanvasTypes::LayerBlendMode::Overlay: return QStringLiteral("overlay");
    case CanvasTypes::LayerBlendMode::Darken: return QStringLiteral("darken");
    case CanvasTypes::LayerBlendMode::Lighten: return QStringLiteral("lighten");
    case CanvasTypes::LayerBlendMode::SourceOver: return QStringLiteral("source-over");
    }
    return QStringLiteral("source-over");
}

CanvasTypes::LayerBlendMode CanvasFileCodec::blendModeFromString(const QString& blendMode) {
    if (blendMode == QStringLiteral("multiply")) {
        return CanvasTypes::LayerBlendMode::Multiply;
    }
    if (blendMode == QStringLiteral("screen")) {
        return CanvasTypes::LayerBlendMode::Screen;
    }
    if (blendMode == QStringLiteral("overlay")) {
        return CanvasTypes::LayerBlendMode::Overlay;
    }
    if (blendMode == QStringLiteral("darken")) {
        return CanvasTypes::LayerBlendMode::Darken;
    }
    if (blendMode == QStringLiteral("lighten")) {
        return CanvasTypes::LayerBlendMode::Lighten;
    }
    return CanvasTypes::LayerBlendMode::SourceOver;
}

Qt::Alignment CanvasFileCodec::alignmentFromString(const QString& alignment) {
    if (alignment == QStringLiteral("center")) {
        return Qt::AlignHCenter;
    }
    if (alignment == QStringLiteral("right")) {
        return Qt::AlignRight;
    }
    return Qt::AlignLeft;
}

QString CanvasFileCodec::alignmentToString(Qt::Alignment alignment) {
    if (alignment.testFlag(Qt::AlignHCenter)) {
        return QStringLiteral("center");
    }
    if (alignment.testFlag(Qt::AlignRight)) {
        return QStringLiteral("right");
    }
    return QStringLiteral("left");
}

bool CanvasFileCodec::loadDocument(const QString& filePath, CanvasTypes::DocumentState* document, QString* errorMessage) {
    if (!document) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("无效的文档目标");
        }
        return false;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("无法打开文件：%1").arg(file.errorString());
        }
        return false;
    }

    QJsonParseError parseError;
    const QJsonDocument json = QJsonDocument::fromJson(file.readAll(), &parseError);
    if (parseError.error != QJsonParseError::NoError || !json.isObject()) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("项目文件格式无效");
        }
        return false;
    }

    const QJsonObject root = json.object();
    const int version = root.value(QStringLiteral("version")).toInt(1);
    if (version < 1 || version > 4) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("不支持的项目文件版本：%1").arg(version);
        }
        return false;
    }

    CanvasTypes::DocumentState parsed;
    parsed.name = root.value(QStringLiteral("documentName")).toString(QStringLiteral("未命名 1"));
    parsed.width = std::clamp(root.value(QStringLiteral("width")).toInt(1600), 320, 6000);
    parsed.height = std::clamp(root.value(QStringLiteral("height")).toInt(980), 240, 6000);
    parsed.backgroundColor = QColor(root.value(QStringLiteral("backgroundColor")).toString(QStringLiteral("#ffffff")));

    const QJsonArray layers = root.value(QStringLiteral("layers")).toArray();
    for (const QJsonValue& value : layers) {
        if (!value.isObject()) {
            continue;
        }

        const QJsonObject layerObject = value.toObject();
        CanvasTypes::LayerState layer;
        layer.name = layerObject.value(QStringLiteral("name")).toString(QStringLiteral("图层"));
        layer.visible = layerObject.value(QStringLiteral("visible")).toBool(true);
        layer.locked = layerObject.value(QStringLiteral("locked")).toBool(false);
        layer.opacity = std::clamp(layerObject.value(QStringLiteral("opacity")).toDouble(1.0), 0.0, 1.0);
        layer.blendMode = blendModeFromString(layerObject.value(QStringLiteral("blendMode")).toString(QStringLiteral("source-over")));
        layer.raster = QImage(parsed.width, parsed.height, QImage::Format_ARGB32_Premultiplied);
        layer.raster.fill(Qt::transparent);
        const QImage stored = imageFromBase64(layerObject.value(QStringLiteral("image")).toString());
        if (!stored.isNull()) {
            QPainter painter(&layer.raster);
            painter.drawImage(QRect(0, 0, parsed.width, parsed.height), stored);
        }

        const QJsonArray texts = layerObject.value(QStringLiteral("textElements")).toArray();
        for (const QJsonValue& textValue : texts) {
            if (!textValue.isObject()) {
                continue;
            }
            const QJsonObject textObject = textValue.toObject();
            CanvasTypes::TextElement text;
            text.id = textObject.value(QStringLiteral("id")).toString();
            text.rect = QRectF(textObject.value(QStringLiteral("x")).toDouble(), textObject.value(QStringLiteral("y")).toDouble(), textObject.value(QStringLiteral("width")).toDouble(240.0), textObject.value(QStringLiteral("height")).toDouble(96.0));
            text.text = textObject.value(QStringLiteral("text")).toString();
            const QJsonObject styleObject = textObject.value(QStringLiteral("style")).toObject();
            text.style.fontFamily = styleObject.value(QStringLiteral("fontFamily")).toString(QStringLiteral("MiSans"));
            text.style.size = styleObject.value(QStringLiteral("size")).toInt(48);
            text.style.color = QColor(styleObject.value(QStringLiteral("color")).toString(QStringLiteral("#101114")));
            text.style.bold = styleObject.value(QStringLiteral("bold")).toBool(false);
            text.style.italic = styleObject.value(QStringLiteral("italic")).toBool(false);
            text.style.alignment = alignmentFromString(styleObject.value(QStringLiteral("align")).toString(QStringLiteral("left")));
            text.style.lineHeight = styleObject.value(QStringLiteral("lineHeight")).toDouble(1.35);
            text.style.letterSpacing = styleObject.value(QStringLiteral("letterSpacing")).toDouble(0.0);
            layer.texts.append(text);
        }

        parsed.layers.append(layer);
    }

    if (parsed.layers.isEmpty()) {
        CanvasTypes::LayerState baseLayer;
        baseLayer.name = QStringLiteral("背景");
        baseLayer.raster = QImage(parsed.width, parsed.height, QImage::Format_ARGB32_Premultiplied);
        baseLayer.raster.fill(Qt::transparent);
        parsed.layers.append(baseLayer);
    }

    parsed.activeLayerIndex = std::clamp(root.value(QStringLiteral("activeLayerIndex")).toInt(static_cast<int>(parsed.layers.size()) - 1), 0, static_cast<int>(parsed.layers.size()) - 1);
    *document = parsed;
    return true;
}

bool CanvasFileCodec::saveDocument(const CanvasTypes::DocumentState& document, const LayerRenderer& renderLayerImage, const QString& filePath, QString* errorMessage) {
    QJsonObject root;
    root.insert(QStringLiteral("version"), 4);
    root.insert(QStringLiteral("width"), document.width);
    root.insert(QStringLiteral("height"), document.height);
    root.insert(QStringLiteral("documentName"), document.name);
    root.insert(QStringLiteral("backgroundColor"), document.backgroundColor.name(QColor::HexRgb));
    root.insert(QStringLiteral("activeLayerIndex"), document.activeLayerIndex);

    QJsonArray layers;
    for (const CanvasTypes::LayerState& layer : document.layers) {
        QJsonObject layerObject;
        layerObject.insert(QStringLiteral("name"), layer.name);
        layerObject.insert(QStringLiteral("visible"), layer.visible);
        layerObject.insert(QStringLiteral("locked"), layer.locked);
        layerObject.insert(QStringLiteral("opacity"), layer.opacity);
        layerObject.insert(QStringLiteral("blendMode"), blendModeToString(layer.blendMode));
        layerObject.insert(QStringLiteral("image"), imageToBase64(renderLayerImage ? renderLayerImage(layer) : layer.raster));
        QJsonArray texts;
        for (const CanvasTypes::TextElement& text : layer.texts) {
            QJsonObject styleObject;
            styleObject.insert(QStringLiteral("fontFamily"), text.style.fontFamily);
            styleObject.insert(QStringLiteral("size"), text.style.size);
            styleObject.insert(QStringLiteral("color"), text.style.color.name(QColor::HexRgb));
            styleObject.insert(QStringLiteral("bold"), text.style.bold);
            styleObject.insert(QStringLiteral("italic"), text.style.italic);
            styleObject.insert(QStringLiteral("align"), alignmentToString(text.style.alignment));
            styleObject.insert(QStringLiteral("lineHeight"), text.style.lineHeight);
            styleObject.insert(QStringLiteral("letterSpacing"), text.style.letterSpacing);

            QJsonObject textObject;
            textObject.insert(QStringLiteral("id"), text.id);
            textObject.insert(QStringLiteral("x"), text.rect.x());
            textObject.insert(QStringLiteral("y"), text.rect.y());
            textObject.insert(QStringLiteral("width"), text.rect.width());
            textObject.insert(QStringLiteral("height"), text.rect.height());
            textObject.insert(QStringLiteral("text"), text.text);
            textObject.insert(QStringLiteral("style"), styleObject);
            texts.append(textObject);
        }
        layerObject.insert(QStringLiteral("textElements"), texts);
        layers.append(layerObject);
    }
    root.insert(QStringLiteral("layers"), layers);

    QSaveFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("无法写入文件：%1").arg(file.errorString());
        }
        return false;
    }
    const QByteArray payload = QJsonDocument(root).toJson(QJsonDocument::Indented);
    const qint64 writtenBytes = file.write(payload);
    if (writtenBytes != payload.size() || !file.commit()) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("写入项目文件失败：%1").arg(file.errorString());
        }
        return false;
    }

    return true;
}

bool CanvasFileCodec::exportSvg(const CanvasTypes::DocumentState& document, const LayerRenderer& renderLayerImage, const QString& filePath, QString* errorMessage) {
    QStringList lines;
    lines << QStringLiteral("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
    lines << QStringLiteral("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%1\" height=\"%2\" viewBox=\"0 0 %1 %2\">").arg(document.width).arg(document.height);
    lines << QStringLiteral("<rect x=\"0\" y=\"0\" width=\"%1\" height=\"%2\" fill=\"%3\"/>").arg(document.width).arg(document.height).arg(escapeXml(document.backgroundColor.name(QColor::HexRgb)));
    for (const CanvasTypes::LayerState& layer : document.layers) {
        if (!layer.visible) {
            continue;
        }
        const QString encoded = imageToBase64(renderLayerImage ? renderLayerImage(layer) : layer.raster);
        lines << QStringLiteral("<g opacity=\"%1\" style=\"mix-blend-mode:%2\">").arg(layer.opacity, 0, 'f', 4).arg(blendModeToString(layer.blendMode));
        lines << QStringLiteral("<image href=\"data:image/png;base64,%1\" x=\"0\" y=\"0\" width=\"%2\" height=\"%3\" preserveAspectRatio=\"none\"/>").arg(escapeXml(encoded)).arg(document.width).arg(document.height);
        lines << QStringLiteral("</g>");
    }
    lines << QStringLiteral("</svg>");

    QSaveFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("无法写入 SVG 文件：%1").arg(file.errorString());
        }
        return false;
    }
    const QByteArray payload = lines.join('\n').toUtf8();
    const qint64 writtenBytes = file.write(payload);
    if (writtenBytes != payload.size() || !file.commit()) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("写入 SVG 文件失败：%1").arg(file.errorString());
        }
        return false;
    }

    return true;
}
