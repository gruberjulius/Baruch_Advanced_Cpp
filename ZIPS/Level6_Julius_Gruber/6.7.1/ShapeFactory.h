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
};
