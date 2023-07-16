#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"

#include <iostream>
#include "PolyLine.h"

//Part a, b
#include "ShapeFactory.h"

//Part c, d
#include "ConsoleShapeFactory.h"

int main() {

    ShapeFactory* console{ new ConsoleShapeFactory };

    auto pl{ console->CreatePolyline()};
	std::cout << "created: " << *pl << std::endl;
	//everything works as expected
}
