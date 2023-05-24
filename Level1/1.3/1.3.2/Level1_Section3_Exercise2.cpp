#include<iostream>
#include<array>


//Solve this problem with the template variadic function

void rotate(double factor){}


 
// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template <typename T, typename... Types>
void rotate(double factor, T var1, Types... var2)
{
    //cout << var1 << endl;
    var1.rotate(factor);
 
    rotate(factor, var2...);
}

class Shape
{
public:
    virtual void rotate(double d) = 0;
};

class Circle : public Shape
{
public:
    void rotate(double d) override { std::cout << "c\n"; }
};

class Line : public Shape
{
public:
    void rotate(double d) override { std::cout << "l\n"; }
};

class Valve
{
public:
    void rotate(double d) { std::cout << "v\n"; }
};

int main(){


    Circle circle;
    Line line;
    Valve valve;

    double factor = 2.0;

    // We can in essence create compile-time aggregates/whole
    // part objects on the fly. We only need to write one function.
    rotate(factor, circle);
    rotate(factor, circle, line);
    rotate(factor, circle, valve);
    rotate(factor*2, circle, valve, line);

	//
	std::cout << " Iterate through the list of elements" << std::endl;
	std::array<Shape*, 5> shapeList
		{ &circle, &line, &circle, &circle, &line};

	double factor2 = 20.0;

	for(auto& elem : shapeList){
		elem->rotate(factor2);
	}

	// We can not iterate throuhg valve because it is not inhariting from the shape base class and the array 
	// is only based on elements of class type shape

	return 0;
}
