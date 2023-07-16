#include "Shape.h"
#include "Point.h"
#include "ExactDistance.h"
#include "ApproximateDistance.h"

#include <iostream>

int main() {

	// Part F: testing the code

	Point p1{ 0,0 };
	Point p2{ 1,1 };
	
	std::cout << "points: " << p1 << ", " << p2 << std::endl;

	Point::setStrategy(new ExactDistance);

	std::cout << "exact distance: " << p1.Distance(p2) << std::endl;

	Point::setStrategy(new ApproximateDistance);

	std::cout << "approximate distance: " << p1.Distance(p2) << std::endl;
}
