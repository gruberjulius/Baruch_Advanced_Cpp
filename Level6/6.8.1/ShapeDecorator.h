#pragma once
#include "Shape.h"
class ShapeDecorator :  public Shape
{
private:
    // Part B

    std::shared_ptr<Shape> _decoratedShape;

public:
    // Part C
    
    // default contructor
    ShapeDecorator() : _decoratedShape{ nullptr } {};
        
    // Part D
    // value constructor
    ShapeDecorator(std::shared_ptr<Shape> pt) : _decoratedShape{ pt } {};

    // Part E

    // returns the decorated shape member element
    std::shared_ptr<Shape> GetShape() {
        return _decoratedShape;
    };

    // set the decorated shape
    void SetShape(std::shared_ptr<Shape> pt) {
        _decoratedShape = pt;
    };

	//pure abstract clone function
    virtual std::shared_ptr<Shape> Clone() = 0;

};

