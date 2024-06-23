#include "Shape.h"
#include "Point.h"
#include "NameDecorator.h"
#include <iostream>

int main() {

	NameDecorator O;
	O.SetName("Origin in Grid");
	O.SetShape(std::make_shared<Point>(0, 0));

	std::cout << O.GetName() << ": " << *O.GetShape() << std::endl;

	NameDecorator A(std::make_shared<Point>(2, 2), "A");

	std::cout << A.GetName() << ": " << *A.GetShape() << std::endl;
	//works as expected
}
