#pragma once

#include "Shape.h"
#include "DistanceStrategy.h"
#include <string>

class DistanceStrategy;

class Point : public Shape
{
private:
	// attributes are set as pointers so that deep copy
	double* _x;
	double* _y;

   	static DistanceStrategy* _strategy;

public:
	Point();  // Default constructor
	Point(double xs, double ys);  // Constructor with coordinates
	Point(const Point& pt);  // Copy constructor
	Point& operator=(const Point& pt);  // Assignment operator
	double x() const;  // Return x coordinate
	double y() const;  // Return y coordinate
	void x(double xs);  // Set x coordinate
	void y(double ys);  // Set y coordinate

	// overriding the printing function of shape abstract class
	std::string print() const;


    //clone
    std::shared_ptr<Shape> Clone();

    // static function for calculation strategy
	static void setStrategy(DistanceStrategy* strategy);

    //Part E
    double Distance(const Point& p, DistanceStrategy& strat);
	double Distance(const Point& p);  
	double Distance();

};

