#pragma once

#include "Shape.h"
#include "Point.h"

#include <vector>

class PolyLine final : public Shape{

    private:
        std::vector<Point> points;

    public:
        PolyLine();
        PolyLine(std::vector<Point>);
        PolyLine(const PolyLine& pl);
        PolyLine& operator=(const PolyLine& pl);

        std::string print() const;



};
