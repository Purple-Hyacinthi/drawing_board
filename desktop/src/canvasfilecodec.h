#pragma once

#include <QImage>
#include <QString>

#include <functional>

#include "canvassharedtypes.h"

class CanvasFileCodec {
public:
    using LayerRenderer = std::function<QImage(const CanvasTypes::LayerState&)>;

    static bool loadDocument(const QString& filePath, CanvasTypes::DocumentState* document, QString* errorMessage = nullptr);
    static bool saveDocument(const CanvasTypes::DocumentState& document, const LayerRenderer& renderLayerImage, const QString& filePath, QString* errorMessage = nullptr);
    static bool exportSvg(const CanvasTypes::DocumentState& document, const LayerRenderer& renderLayerImage, const QString& filePath, QString* errorMessage = nullptr);

private:
    static QString imageToBase64(const QImage& image);
    static QImage imageFromBase64(const QString& base64);
    static QString escapeXml(const QString& text);
    static QString blendModeToString(CanvasTypes::LayerBlendMode blendMode);
    static CanvasTypes::LayerBlendMode blendModeFromString(const QString& blendMode);
    static Qt::Alignment alignmentFromString(const QString& alignment);
    static QString alignmentToString(Qt::Alignment alignment);
};
