#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"

#include <iostream>


#include "PrintVisitor.h"

#include "ShapeVisitor.h"

#include <iostream>

int main() {

	PrintVisitor printer;

	Point p{ 1.0, 1.0 };
	printer.Visit(p);

	Line l{ Point(), p };
	printer.Visit(l);

	Circle c{ p, 1.0 };
	printer.Visit(c);
    
    return 0;
}


