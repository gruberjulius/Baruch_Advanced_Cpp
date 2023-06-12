#include<iostream>

template<typename T>
T epsilon(T a){

    T epsilon = 1.0;
    while ((1.0 + 0.5*epsilon) != 1.0)
    {
        epsilon *= 0.5;
    }
    std::cout << epsilon<< std::endl;
    return epsilon;
}

int main(){
    double a = 1;
    std::cout << epsilon(a) << std::endl; 
    std::cout << std::numeric_limits<double>::epsilon() << std::endl;

    float b = 1;
    std::cout << epsilon(b) << std::endl; 
    std::cout << std::numeric_limits<float>::epsilon() << std::endl;

    int c = 1;
    std::cout << epsilon(c) << std::endl; 
    std::cout << std::numeric_limits<float>::epsilon() << std::endl;

}
