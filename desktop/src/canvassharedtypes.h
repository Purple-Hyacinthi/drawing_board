#pragma once

#include <QColor>
#include <QImage>
#include <QRectF>
#include <QString>
#include <QVector>

namespace CanvasTypes {

enum class ToolId {
    Select,
    Brush,
    Pencil,
    Ink,
    Pen,
    Eraser,
    Eyedropper,
    Lasso,
    Fill,
    Shape,
    Text
};

enum class ShapeType {
    Line,
    Curve,
    Ellipse,
    Rectangle,
    RoundedRectangle,
    Triangle,
    Diamond,
    Pentagon,
    Hexagon,
    RightArrow,
    LeftArrow,
    UpArrow,
    DownArrow,
    Star4,
    Star5,
    ChatBubble,
    Heart
};

enum class LayerBlendMode {
    SourceOver,
    Multiply,
    Screen,
    Overlay,
    Darken,
    Lighten
};

enum class SizeMode {
    Fixed,
    Random,
    Pressure
};

enum class EraserMode {
    Normal,
    Stroke
};

enum class FilterType {
    Grayscale,
    Sepia,
    Invert,
    Blur,
    Sharpen
};

struct BrushStyleState {
    int angle = 0;
    int roundness = 100;
    int spacing = 8;
    int hardness = 100;
    int flow = 100;
    SizeMode sizeMode = SizeMode::Pressure;
    int sizeJitter = 0;
};

struct TextStyleState {
    QString fontFamily = QStringLiteral("MiSans");
    int size = 48;
    QColor color = QColor(QStringLiteral("#101114"));
    bool bold = false;
    bool italic = false;
    Qt::Alignment alignment = Qt::AlignLeft;
    qreal lineHeight = 1.35;
    qreal letterSpacing = 0.0;
};

struct BrushPanelCopy {
    QString title;
    QString nameLabel;
    QString angleLabel;
    QString roundnessLabel;
    QString spacingLabel;
    QString hardnessLabel;
    QString flowLabel;
    QString sizeModeLabel;
    QString jitterLabel;
    QString tip;
};

struct LayerSummary {
    QString name;
    bool visible = true;
    bool locked = false;
    qreal opacity = 1.0;
    LayerBlendMode blendMode = LayerBlendMode::SourceOver;
    bool active = false;
    QImage thumbnail;
};

struct TextElement {
    QString id;
    QRectF rect;
    QString text;
    TextStyleState style;
};

struct LayerState {
    QString name;
    bool visible = true;
    bool locked = false;
    qreal opacity = 1.0;
    LayerBlendMode blendMode = LayerBlendMode::SourceOver;
    QImage raster;
    QVector<TextElement> texts;
};

struct DocumentState {
    QString name;
    int width = 1600;
    int height = 980;
    QColor backgroundColor = QColor(QStringLiteral("#ffffff"));
    QVector<LayerState> layers;
    int activeLayerIndex = -1;
};

}  // namespace CanvasTypes
