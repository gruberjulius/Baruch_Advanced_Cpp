#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"

#include <iostream>

//Part a, b
#include "ShapeFactory.h"

//Part c, d
#include "ConsoleShapeFactory.h"

int main() {

	//define the shape factory object
    ShapeFactory* console{ new ConsoleShapeFactory };

	//call the CreateShapes function
    auto t{ console->CreateShapes()};
	std::cout << "created: " << *std::get<0>(t) << ", " << *std::get<1>(t) << ", " << *std::get<2>(t) << std::endl;
}
