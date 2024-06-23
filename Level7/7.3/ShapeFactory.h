#pragma once
#include <memory>
#include "PolyLine.h"
#include "Circle.h"
#include "Line.h"
#include "Point.h"
// forward declaration 
class Point;
class Line;
class Circle;


class ShapeFactory
{
public:
    //pure virtual functions 
	virtual std::shared_ptr<Point> CreatePoint() = 0;
	virtual std::shared_ptr<Line> CreateLine();
	virtual std::shared_ptr<Circle> CreateCircle() = 0;

    virtual std::shared_ptr<PolyLine> CreatePolyLine() final;
   
    //abstract CreateShapes function 
	virtual std::tuple<std::shared_ptr<Point>, std::shared_ptr<Line>, std::shared_ptr<Circle>> CreateShapes() = 0;
};
