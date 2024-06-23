#pragma once

#include "ShapeDecorator.h"

#include <string>

class NameDecorator :
    public ShapeDecorator
{
private:
    // Part G: set member function
    std::string _name;

public:
    // Part H

    NameDecorator() : ShapeDecorator(), _name{ "" }{};
        
    // Part I: Default constructor
    NameDecorator(std::shared_ptr<Shape> shape, std::string name) :
    ShapeDecorator(shape), _name{ name }{};

    NameDecorator(std::shared_ptr<Shape> shape) :
    ShapeDecorator(shape), _name{ ""}{};

    // Part J

	//returns the name of the class
    std::string GetName() {
        return _name;
    };

    // sets the name of the function 
    void SetName(std::string newname) {
        _name = newname;
    };

    // Part K
    
    // clone method
    std::shared_ptr<Shape> Clone() {
        return std::make_shared<NameDecorator>(*this);
    }
};

