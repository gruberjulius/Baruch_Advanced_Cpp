
#pragma once
#include <list>
#include "Shape.h"

//I implement it with a shared shape ptr here instead of a shape pointer as asked
//in the question, but I read in the forum that most did it like this
class ShapeComposite : public Shape {
private:
    // Part B: private std::list data members 
    std::list<std::shared_ptr<Shape>> shapeList;
  

public:

    ShapeComposite(ShapeComposite& copy) {
        for (auto elem : copy) {
            this->AddShape(elem->Clone());
        }
    };

    ShapeComposite& operator=( ShapeComposite& copy) {
        ShapeComposite nonconstcopy(copy);
        return nonconstcopy;
    }

    //Default Constructor
    ShapeComposite(){}; 
    void AddShape(std::shared_ptr<Shape> s);  // Part D

    // Part E:
    typedef std::list<std::shared_ptr<Shape>>::iterator it;  // list iterator
    typedef std::list<std::shared_ptr<Shape>>::const_iterator constit;  // constant list iterator

    // Part F: 
    it begin();
    it end();

    //Part G
    unsigned int count();
    

	std::string print() const{
        for(auto elem :shapeList){
                std::cout << *elem << std::endl;
        }
    };

    std::shared_ptr<Shape> Clone() { 
        return std::make_shared<ShapeComposite>(*this); };
};
