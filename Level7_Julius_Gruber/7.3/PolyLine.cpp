#include "PolyLine.h"

#include "Point.h"

PolyLine::PolyLine() {};// Default constructor

PolyLine::PolyLine(const std::vector<Point> n_points):
	points(n_points){};

Polyline::Polyline(const PolyLine& pt) { // Copy constructor
	this->points = pt.points;
}

Polyline& Polyline::operator=(const Polyline& pt) {  // Assignment operator
	Polyline pl(pt);
	return pl;
};

//creating a print function for polyline
std::string Polyline::print() const {
    std::string out_string{ "Polyline( " };
    for (auto point : this->points) {
        out_string += (*point).print() + ", ";
    }
    return out_string + " )";
};










