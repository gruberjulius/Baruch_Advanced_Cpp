#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "PolyLine.h"
#include <iostream>
#include "PolyLine.h"

//Part a, b
#include "ShapeFactory.h"

//Part c, d
#include "ConsoleShapeFactory.h"

int main() {

	//Create the ShapeFactory Object
    ShapeFactory* console{ new ConsoleShapeFactory };

	//Create a polyline object
    auto pl{ console->CreatePolyLine()};
	std::cout << "created: " << *pl << std::endl;
	//everything works as expected
}
