
#pragma once
#include <list>
#include "Shape.h"

// I know in the instructions it said to use Shape* s but in the
// forum questions it says to use shared_ptr and so going with that

class ShapeComposite : public Shape {
private:
    // Part B: private std::list data members 
    std::list<std::shared_ptr<Shape>> shapeList;
  

public:
    // Part C: copy & assignment operators 
    ShapeComposite(const ShapeComposite& s);  
    ShapeComposite& operator=(const ShapeComposite& pt);  

    //Default Constructor
    ShapeComposite(){}; 
    // I know in the instructions it said to use Shape* s but in the 
    // forum questions it says to use shared_ptr and so going with that 
    void AddShape(std::shared_ptr<Shape> s){ shapeList.emplace_back(s); };;  // Part D

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
};
