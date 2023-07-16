#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"

// Part A
#include "NewShapeFactory.h"

#include "ConsoleShapeFactory.h"

#include <iostream>

int main() {

	//Part b, d

	// lambda function for factory creation of point 
	creator<Point> lambda_point = []() {return std::make_shared<Point>(Point(2, 2)); };

    //function object for factory creation
	struct FO {
		std::shared_ptr<Line> operator()() {
			return std::make_shared<Line>(Line(Point(0, 0), Point(1, 1)));
		}
	};
    //create a function line object
	creator<Line> function_object_line = FO();

    //binder for the original code
	ConsoleShapeFactory* old_console_factory = new ConsoleShapeFactory;

    //use the bind for the circle
	creator<Circle> bind_circle = std::bind(&ConsoleShapeFactory::CreateCircle, old_console_factory);

	NewShapeFactory* factory = new NewShapeFactory(lambda_point, function_object_line, bind_circle);

	// testing the methods
	
	std::cout << "point created:" << *(factory->CreatePoint()) << std::endl;
	std::cout << "line created:" << *(factory->CreateLine()) << std::endl;
	factory->CreateCircle();
    //methods are working 

	factory->AssignPointCreator(std::bind(&ConsoleShapeFactory::CreatePoint, old_console_factory));
	factory->CreatePoint();
    //assignments work as well

	// Part c

    //For the new types, only the factory class needs to be updated (instead of all the other derived classes like console shape factory)
    //this version seems easier to maintain.
}
