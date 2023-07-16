#pragma once
#include <memory>

// forward declaration 
class Point;
class Line;
class Circle;


class ShapeFactory
{
public:
    //pure virtual functions 
	virtual std::shared_ptr<Point> CreatePoint() = 0;
	virtual std::shared_ptr<Line> CreateLine() = 0;
	virtual std::shared_ptr<Circle> CreateCircle() = 0;

   
    //abstract CreateShapes function 
	virtual std::tuple<std::shared_ptr<Point>, std::shared_ptr<Line>, std::shared_ptr<Circle>> CreateShapes() = 0;
};
