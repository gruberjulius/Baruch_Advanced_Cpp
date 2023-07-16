#pragma once

#include "ShapeVisitor.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"


#include <iostream>
class PrintVisitor :
    public ShapeVisitor
{
public:
	void Visit(Point& p) {
		std::cout << p << std::endl;
	};
	void Visit(Line& l) {
		std::cout << l << std::endl;
	};
	void Visit(Circle& c) {
		std::cout << c << std::endl;
	};
};
