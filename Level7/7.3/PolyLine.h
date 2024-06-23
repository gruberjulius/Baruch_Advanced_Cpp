#pragma once
#include "Shape.h"
#include "Point.h"

#include <vector>

class PolyLine: public Shape
{
private:
    std::vector<std::shared_ptr<Point>> points;
public:

    PolyLine(){};  // default Cons
    PolyLine(std::vector<std::shared_ptr<Point>> new_points): points(new_points){};  //const with points
    PolyLine(const PolyLine& pt){this->points = pt.points;};  // copy
    PolyLine& operator=(const PolyLine& pt){PolyLine pl(pt); // assignment
    return pl;}; 

    // implement the virtual print function of Shape
    std::string print()  const{
        std::string out_string{ "Polyline( " };
        for (auto point : this->points) {
            out_string += (*point).print() + ", ";
        }
        return out_string + " )";
    };
};
