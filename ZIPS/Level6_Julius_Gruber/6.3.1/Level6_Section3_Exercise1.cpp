#include <iostream>
#include "Shape.h"
#include "Circle.cpp"
#include "Line.cpp"
#include "Point.cpp"
#include "OriginPoint.h"
#include "ShapeComposite.cpp"

void Print(ShapeComposite& sc){
    for(std::shared_ptr<Shape> elem: sc){
        std::cout << *elem;
    }
}

int main()
{
    Point point1(1, 1);
    Point point2 = point1;
    Point point3(2, 5);

    Line line1(point1, point2);
    Line line2(point1, point3);
    Line line3(point2, point3);

    Circle circle1(point1, 1.0);
    Circle circle2(point2, 2.0);
    Circle circle3(point3, 3.0);


    //merging them all together
    ShapeComposite sc;
    Print(sc);
    std::shared_ptr<Point> sp1 = std::make_shared<Point>(point1);
    std::shared_ptr<Point> sp2 = std::make_shared<Point>(point3);
    std::shared_ptr<Line> sp3 = std::make_shared<Line>(line1);
    std::shared_ptr<Line> sp4 = std::make_shared<Line>(line2);
    std::shared_ptr<Line> sp5 = std::make_shared<Line>(line3);
    std::shared_ptr<Circle> sp6 = std::make_shared<Circle>(circle1);
    std::shared_ptr<Circle> sp7 = std::make_shared<Circle>(circle2);
    std::shared_ptr<Circle> sp8 = std::make_shared<Circle>(circle3);

    sc.AddShape(sp1);
    sc.AddShape(sp2);
    sc.AddShape(sp3);
    sc.AddShape(sp4);
    sc.AddShape(sp5);
    sc.AddShape(sp6);
    sc.AddShape(sp7);
    sc.AddShape(sp8);

    Print(sc);
  
    std::shared_ptr<ShapeComposite> sc1 (new ShapeComposite());  // make a composite pointer

    //sc.AddShape(sc1);  // add composite to composite, gives illigale hardware access error
    Print(sc);

}
