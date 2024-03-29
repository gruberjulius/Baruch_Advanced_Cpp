#pragma once

#include "Shape.h"
#include "Point.h"

class Line :
    public Shape
{
private:
    // attributes are set as pointers so that deep copy
    Point* _pt1;
    Point* _pt2;


public: 

    Line();  // Default constructor
    Line(const Point& pt1s, const Point& pt2s);  // Constructor with points
    Line(const Line& pt);  // Copy constructor
    Line& operator=(const Line& pt);  // Assignment operator
    Point p1() const;  // Return point 1
    Point p2() const;  // Return point 2
    void p1(const Point& ps);  // Set point 1
    void p2(const Point& ps);  // Set point 2

    // overriding the printing function of shape abstract class
    std::string print() const;

    //Part D
    //returns the lenght between the two points
    double Length();

	void Accept(ShapeVisitor& visitor);

};

