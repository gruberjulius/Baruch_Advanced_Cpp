#pragma once
#include "Shape.h"
#include "Point.h"

class Circle :
    public Shape
{
private:
    // attributes are set as pointers so that deep copy
    Point* _c;
    double* _r;


public:
    Circle();  // Default constructor
    Circle(const Point& c, double r);  // Constructor point and radius
    Circle(const Circle& pt);  // Copy constructor
    Circle& operator=(const Circle& pt);  // Assignment operator
    Point CenterPoint() const;  // Return center point
    double Radius() const;  // Return radius
    void CenterPoint(Point centre);  // Set center point
    void Radius(double radius);  // Set radius

    // overriding the printing function of shape abstract class
    std::string print() const;

    std::shared_ptr<Shape> Clone();
};

