#include<iostream>
#include<functional>


template <typename T>
    using FunctionType = std::function<T (const T& t)>;

template <typename T>
void print(const FunctionType<T>& f, T t)
{
    std::cout << f(t) << '\n';
}

// Part b

// free function

double CircleArea(const double radius){
    return 3.14 * radius * radius;
}

//function object

struct PerfectRectangleArea{
    double operator() (double side){
        return 1.618 * side * side;
    }
};


FunctionType<double> SquareArea = [](double side){return side* side;};

int main(){
	//Part B of the class
    double len = 3;

    FunctionType<double> circle = CircleArea;
    FunctionType<double> perf_rectangle = PerfectRectangleArea();
    FunctionType<double> square = SquareArea;

    print(circle, len);
    print(perf_rectangle, len);
    print(square, len);
    
    //works as expected

	return 0;
}
