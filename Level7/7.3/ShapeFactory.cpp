#include "ShapeFactory.h"
#include "Line.h"
#include "Point.h"
#include "PolyLine.h"


std::shared_ptr<Line> ShapeFactory::CreateLine()
{
    auto p1 = CreatePoint();
    auto p2 = CreatePoint();
	return std::make_shared<Line>(*p1, *p2);
}


std::shared_ptr<PolyLine> ShapeFactory::CreatePolyLine() 
{
	int size;
	std::cout << "Input size: ";
	std::cin >> size;
	std::vector<std::shared_ptr<Point>> vec;
	for (int i = 0; i < size; ++i){ 
        vec.push_back(CreatePoint());  // pushing points into the vector
        };
	return std::make_shared<PolyLine>(PolyLine(vec)); // contstructor with vector
};
