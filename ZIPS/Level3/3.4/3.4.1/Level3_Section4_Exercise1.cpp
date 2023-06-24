#include<iostream>
#include <future>


//Part a
void func1()
{
    std::cout << "Hello World" << std::endl;
}

double func2(double a, double b)
{
    return a + b;
}

 int main(){
    //Part b
    std::future<void> futureResult1 = std::async(func1);
    std::future<double> futureResult2 = std::async(func2, 5., 10.);
    
    int result2 = futureResult2.get();

    std::cout << "Result of future calculation " <<  result2 << std::endl;
    //Part c
    //I get a segmentation fault if I try to access it a third time

    //int result3 = futureResult2.get();
    
    // Part d
    // Still segmentation fault

    std::future<double> futureResult3 = std::async(std::launch::async,func2, 5., 10.);
    
    int result3 = futureResult3.get();

    // Still segmentation fault
    //int result4 = futureResult3.get();

    //Part e

    std::future<double> futureResult4 = std::async(std::launch::deferred,func2, 5., 10.);
    //Code is only calculated now

    int result5 = futureResult4.get();

    return 0;
 }
