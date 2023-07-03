#include <iostream>
#include "vector.h"

int main() {
    // Part B: 

    Vector<int, 3> v1;
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;

    int a[3] = {4, 5, 6};

    Vector<int, 3> v2 = a;

    Vector<int, 3> v3 = v1 + v2;

    std::cout << "Vector v1: ";
    v1.print();
    std::cout << "Vector v2: ";
    v2.print();
    std::cout << "Vector v3 (v1 + v2): ";
    v3.print();

    //Part C
    v2 = v2 + v1;
    std::cout << "Modified v1: ";
    v1.print();
    std::cout << "Modified v2: ";
    v2.print();

    //Part D
    v1 = 3 * v1 ;
    v2 = 2* v2 ;

    std::cout << "Multiplied v1 by 3: ";
    v1.print();
    std::cout << "v2 - v1: ";
	v2 = v2 - v1;
    v2.print();

    //Part E
    std::function<double(double)> squared = [](double i) {return i * i; };
    v1.print();
    v1.modify(squared);
    std::cout << "Code after squaring" << std::endl;
    v1.print();
    //works as expected


    return 0;
}

