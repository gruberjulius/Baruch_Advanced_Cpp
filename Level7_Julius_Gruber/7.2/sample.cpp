#include<iostream>
#include "ExplicitShapeFactory.h"
#include "Point.h"
#include "Circle.h"
#include "Line.h"

// using namespaces from explicitFactory
struct FuncLine
{ 
    std::shared_ptr<Line> operator()()
    {   
        return std::make_shared<Line>(Point(0, 0), Point(1, 1)); // defaul cons called
    }
};


int main()
{
    // declaring functions
    PF lambda_func_point = [](){return std::make_shared<Point>(Point(10, 10));};
    CF lambda_func_circle = [](){return std::make_shared<Circle>(Point(10, 10), 1);};
    LF func_obj_line = FuncLine();

    ExplicitShapeFactory factory(lambda_func_point, func_obj_line, lambda_func_circle);
    auto l = factory.CreateLine();
    auto p = factory.CreatePoint();
    auto c = factory.CreateCircle();

    l->print();
    p->print();
    c->print();

    //c).
    // the explicit composition of factory methods allows you to create different objects
    // with specific behaviors. It provides flexibility and modularity to the design.

    //d).
    double x = 1;
    double y = 2;
    auto lineFromFixedPoint = [&x, &y, &factory]() {
        auto p1 = factory.CreatePoint(); // first fixed point from factory
        Point p(x, y); // create second point
        auto p2 = std::make_shared<Point>(p);
        return std::make_shared<Line>(*p1, p);
    };
    std::cout << "Line from a fixed point" << std::endl;
    lineFromFixedPoint()->print();
    // i could use this approach with lambda functions and bind to create shapes that follow certain rules.

    return 0;
}
