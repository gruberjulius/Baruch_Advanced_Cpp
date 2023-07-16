#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"

#include <iostream>



int main(){

    //Define two points
	Point p1{};
	Point p2{1.0, 1.0};
	std::cout << p2 << std::endl;
    //Create a line from two points
	Line l{ p1, p2 };
	std::cout << l << std::endl;
    //Print the Circle
	Circle c{ p1, 3.14 };
	std::cout << c << std::endl;

    //Part B
    std::cout << p1.Distance(p2) << std::endl;
    
    //Part C
    std::cout << p2.Distance() << std::endl;

    //Part D
    std::cout << l.Length() << std::endl;

    //Part F: workds as expected
    return 0;
}
