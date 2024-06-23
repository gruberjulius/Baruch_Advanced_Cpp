#pragma once

#include "Shape.h"

#include <string>


class Point : public Shape
{
private:
	//attributes set as pointer 
	double * _x;
	double * _y;

public:
	Point();  // Default constructor
	Point(double xs, double ys);  // Constructor coordinates
	Point(const Point& pt);  // Copy constructor
	Point& operator=(const Point& pt);  // Assignment operator
	double x() const;  // Return x coordinate
	double y() const;  // Return y coordinate
	void x(double xs);  // Set x coordinate
	void y(double ys);  // Set y coordinate

	// overriding the printing function from abstract base class 
	std::string print() const;

	// Part a, b

	// function to compute the distance between this point and other point
	double Distance(const Point& p);

	// Part c

	// function to compute the distance between this point and origin
	double Distance();
};

