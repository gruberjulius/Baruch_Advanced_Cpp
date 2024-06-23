#include "Point.h"

#include "OriginPoint.h"

#include "DistanceStrategy.h"

#include <string>
#include <cmath>

Point::Point() : // Default constructor
    _x{ new double(0) }, _y{ new double(0) }{};

Point::Point(double xs, double ys) :  // Constructor with coordinates
    _x{ new double(xs) }, _y{ new double(ys) }{};

Point::Point(const Point& pt) :  // Copy constructor
    _x{ new double(*pt._x) }, _y{ new double(*pt._y) }{};

Point& Point::operator=(const Point& pt) {  // Assignment operator
    Point p(pt);
    return p;
}

double Point::x() const { return *this->_x; };  // Return x coordinate
double Point::y() const { return *this->_y; };  // Return y coordinate

void Point::x(double xs) {  // Set x coordinate
    delete _x;
    _x = new double(xs);
};
void Point::y(double ys) { // Set y coordinate
    delete _y;
    _y = new double(ys);
};

// overriding the printing function of shape abstract class
std::string Point::print() const {
    return "Point(" + std::to_string(this->x()) + ", " + std::to_string(this->y()) + ")";
};

//cloning 
std::shared_ptr<Shape> Point::Clone() {
    return std::make_shared<Point>(*this);
}

// Part D
DistanceStrategy* Point::_strategy;

// setting strategy
void Point::setStrategy(DistanceStrategy* strategy) { _strategy = strategy; };

// Part E
// distance from other point for specific strategy
double Point::Distance(const Point& p) {
    return _strategy->Distance(std::ref(*this), std::ref(p));
}

// distance from origin for specific strategy
double Point::Distance() {
    return _strategy->Distance(std::ref(*this), std::ref(*OriginPoint::instance()));
}
