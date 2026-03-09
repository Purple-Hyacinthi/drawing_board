#include "canvasfilters.h"

#include <QColor>

#include <algorithm>

void CanvasFilters::apply(QImage* image, CanvasTypes::FilterType filterType, int intensity) {
    if (!image || image->isNull()) {
        return;
    }

    if (image->format() != QImage::Format_ARGB32) {
        *image = image->convertToFormat(QImage::Format_ARGB32);
    }

    const qreal factor = std::clamp(intensity, 0, 100) / 100.0;
    if (filterType == CanvasTypes::FilterType::Invert) {
        for (int y = 0; y < image->height(); ++y) {
            for (int x = 0; x < image->width(); ++x) {
                QColor color = image->pixelColor(x, y);
                color.setRedF(color.redF() * (1.0 - factor) + (1.0 - color.redF()) * factor);
                color.setGreenF(color.greenF() * (1.0 - factor) + (1.0 - color.greenF()) * factor);
                color.setBlueF(color.blueF() * (1.0 - factor) + (1.0 - color.blueF()) * factor);
                image->setPixelColor(x, y, color);
            }
        }
        return;
    }

    if (filterType == CanvasTypes::FilterType::Grayscale || filterType == CanvasTypes::FilterType::Sepia) {
        for (int y = 0; y < image->height(); ++y) {
            for (int x = 0; x < image->width(); ++x) {
                QColor color = image->pixelColor(x, y);
                const qreal gray = 0.299 * color.redF() + 0.587 * color.greenF() + 0.114 * color.blueF();
                QColor target = QColor::fromRgbF(gray, gray, gray, color.alphaF());
                if (filterType == CanvasTypes::FilterType::Sepia) {
                    target = QColor::fromRgbF(std::clamp(gray * 1.12, 0.0, 1.0), std::clamp(gray * 0.94, 0.0, 1.0), std::clamp(gray * 0.72, 0.0, 1.0), color.alphaF());
                }
                color.setRedF(color.redF() * (1.0 - factor) + target.redF() * factor);
                color.setGreenF(color.greenF() * (1.0 - factor) + target.greenF() * factor);
                color.setBlueF(color.blueF() * (1.0 - factor) + target.blueF() * factor);
                image->setPixelColor(x, y, color);
            }
        }
        return;
    }

    if (filterType != CanvasTypes::FilterType::Blur && filterType != CanvasTypes::FilterType::Sharpen) {
        return;
    }

    QImage source = *image;
    const int kernel[9] = {
        filterType == CanvasTypes::FilterType::Sharpen ? 0 : 1,
        filterType == CanvasTypes::FilterType::Sharpen ? -1 : 2,
        filterType == CanvasTypes::FilterType::Sharpen ? 0 : 1,
        filterType == CanvasTypes::FilterType::Sharpen ? -1 : 2,
        filterType == CanvasTypes::FilterType::Sharpen ? 5 : 4,
        filterType == CanvasTypes::FilterType::Sharpen ? -1 : 2,
        filterType == CanvasTypes::FilterType::Sharpen ? 0 : 1,
        filterType == CanvasTypes::FilterType::Sharpen ? -1 : 2,
        filterType == CanvasTypes::FilterType::Sharpen ? 0 : 1
    };
    const int divisor = filterType == CanvasTypes::FilterType::Sharpen ? 1 : 16;

    for (int y = 0; y < image->height(); ++y) {
        for (int x = 0; x < image->width(); ++x) {
            qreal red = 0.0;
            qreal green = 0.0;
            qreal blue = 0.0;
            for (int ky = -1; ky <= 1; ++ky) {
                const int sy = std::clamp(y + ky, 0, image->height() - 1);
                for (int kx = -1; kx <= 1; ++kx) {
                    const int sx = std::clamp(x + kx, 0, image->width() - 1);
                    const QColor sample = source.pixelColor(sx, sy);
                    const int weight = kernel[(ky + 1) * 3 + (kx + 1)];
                    red += sample.redF() * weight;
                    green += sample.greenF() * weight;
                    blue += sample.blueF() * weight;
                }
            }
            QColor original = source.pixelColor(x, y);
            QColor filtered = QColor::fromRgbF(std::clamp(red / divisor, 0.0, 1.0), std::clamp(green / divisor, 0.0, 1.0), std::clamp(blue / divisor, 0.0, 1.0), original.alphaF());
            original.setRedF(original.redF() * (1.0 - factor) + filtered.redF() * factor);
            original.setGreenF(original.greenF() * (1.0 - factor) + filtered.greenF() * factor);
            original.setBlueF(original.blueF() * (1.0 - factor) + filtered.blueF() * factor);
            image->setPixelColor(x, y, original);
        }
    }
}
