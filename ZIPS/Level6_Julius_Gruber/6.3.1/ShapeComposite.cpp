#pragma once

#include"ShapeComposite.h"



 // Part B: private std::list data members 
std::list<std::shared_ptr<Shape>>
      shapeList;
  
//Part D  
/*void ShapeComposite::AddShape(std::shared_ptr<Shape> s){
    shapeList.emplace_back(s);
}
*/

//Part F
ShapeComposite::it ShapeComposite::end(){return shapeList.end();}
ShapeComposite::it ShapeComposite::begin(){return shapeList.begin();}

//Part G
unsigned int ShapeComposite::count(){return shapeList.size();}
