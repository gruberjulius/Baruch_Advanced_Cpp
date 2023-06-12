#include<iostream>
#include<functional>

double freeFunction3(double x, double y, double z)
{
    return x+y+z;
}

int main(){

    auto fn1 = std::bind(freeFunction3, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    auto fn2 = std::bind(freeFunction3, std::placeholders::_1, std::placeholders::_2, 1003);
    auto fn3 = std::bind(freeFunction3, std::placeholders::_1, 1002, 1003);
    auto fn4 = std::bind(freeFunction3, 1001, 1002, 1003);

    std::cout << fn1(1, 2, 3) << std::endl;
    std::cout << fn2(1, 2) << std::endl;
    std::cout << fn3(1) << std::endl;
    std::cout << fn4() << std::endl;
    //works as expected

    return 0;
}
