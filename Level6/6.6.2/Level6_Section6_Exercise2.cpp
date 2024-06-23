#include "Shape.h"
#include "Point.h"
#include "ExactDistance.h"
#include "ApproximateDistance.h"

#include <iostream>

int main() {

	// Part F: testing the code

	Point p1{ 0,0 };
	Point p2{ 2,2 };
	
	std::cout << "points: " << p1 << ", " << p2 << std::endl;

	std::cout << "points: " << p1 << ", " << p2 << std::endl;

	std::cout << "exact distance: " << p1.Distance(p2, new ExactDistance) << std::endl;

	std::cout << "approximate distance: " << p1.Distance(p2, new ApproximateDistance) << std::endl;	
    //worksa as expected
}
