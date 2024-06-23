#pragma once

#include "DistanceStrategy.h"
#include "Point.h"

#include <cmath>

class ExactDistance :
    public DistanceStrategy
{
public:
    double Distance(const Point& p1, const Point& p2) {
        double d_x = p1.x() - p2.x();
        double d_y = p1.y() - p2.y();
        return std::sqrt(d_x * d_x + d_y * d_y);
    }
};
