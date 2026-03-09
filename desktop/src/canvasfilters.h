#pragma once

#include <QImage>

#include "canvassharedtypes.h"

class CanvasFilters {
public:
    static void apply(QImage* image, CanvasTypes::FilterType filterType, int intensity);
};
