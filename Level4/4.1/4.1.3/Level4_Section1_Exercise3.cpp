#include "matrix.cpp"
#include <iostream>
#include <array>
#include <complex>

int main() {
    // Part B
    Matrix<int, 3, 2> m1(1);
    std::cout << "Matrix m1:" << std::endl << m1 << std::endl;

    Matrix<int, 3, 2> m2;
    m2[0][0] = 2;
    m2[0][1] = 3;
    m2[1][0] = 4;
    m2[1][1] = 5;
    m2[2][0] = 6;
    m2[2][1] = 7;
    std::cout << "Matrix m2:" << std::endl << m2 << std::endl;


    //Part C
    Matrix<int, 3, 2> m3 = m1 + m2;
    std::cout << "Matrix m3 (m1 + m2):" << std::endl << m3 << std::endl;

    Matrix<int, 3, 2> m4 = m2 - m1;
    std::cout << "Matrix m4 (m2 - m1):" << std::endl << m4 << std::endl;
    
    //Part D
    int scalar = 2;
    Matrix<int, 3, 2> m5 = scalar * m2;
    std::cout << "Matrix m5 (scalar * m2):" << std::endl << m5 << std::endl;

    //Part E
    std::function<int(int)> squared = [](int i) {return i*i; };
    std::cout << "Original matrix m2:" << std::endl << m2 << std::endl;
    m2.modify(squared);
    std::cout << "Modified matrix m2:" << std::endl << m2 << std::endl;

    return 0;
}

