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

    ShapeFactory* console{ new ConsoleShapeFactory };

	auto p{ console->CreatePoint()};
	std::cout << "created: " << *p << std::endl;

	auto l{ console->CreateLine() };
	std::cout << "created: " << *l << std::endl;

	auto c{ console->CreateCircle() };
	std::cout << "created: " << *c << std::endl;
}
