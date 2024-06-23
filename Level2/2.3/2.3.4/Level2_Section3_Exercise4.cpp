#include<iostream>
#include<functional>
template <typename R, typename D>
using FunctionType = std::function<R (const D x)>;

using ScalarFunction = FunctionType<double, double>;


template <typename T>
std::function<T (const T&)> bind1st
(const std::function<T (const T& x, const T& y)>& f,const T& x_)
{

    return std::bind(f, x_, std::placeholders::_1);
}
template <typename T>
std::function<T(const T&)> bind2nd
(const std::function<T(const T& x, const T& y)>& f, const T& y_)
{
    // Bind to the second param y of f(x,y)
    // TBD
    return std::bind(f, std::placeholders::_1, y_);
}

int main(){
    auto fxy = []( double  x, double y)  {return x / y;};
    double yval = 10.0;
    ScalarFunction fx = bind2nd<double>(fxy, yval);
    std::cout << fx(3.0)<< std::endl;
    // Test new bind code on STL algorithms
    std::vector<double> vec1(10, 2.0);
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), fx);
    for (auto i = 0; i < vec1.size(); ++i)
    {
        std::cout << vec1[i]<<",";
    }

    double xval = 0.5;
    ScalarFunction fy = bind1st<double>(fxy, xval);
    std::cout << fy(3.0)<< std::endl;
    // Test new bind code on STL algorithms
    std::vector<double> vec2(10, 2.0);
    std::transform(vec2.begin(), vec2.end(), vec2.begin(), fy);
    for (auto i = 0; i < vec2.size(); ++i)
    {
        std::cout << vec2[i]<<",";
    }


}
