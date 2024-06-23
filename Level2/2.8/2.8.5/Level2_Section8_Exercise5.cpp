#include <iostream>
#include "BitMatrix.cpp"
#include <bitset>

int main()
{
    // Testing Constructors
    BitMatrix<3, 4> bitmatrix1;
    std::cout << "Default constructor: \n";
    bitmatrix1.print();

    BitMatrix<3, 4> bitmatrix2(10);
    std::cout << "Constructor with value input: \n";
    bitmatrix2.print();

    BitMatrix<3, 4> bitmatrix3(bitmatrix2);
    std::cout << "Copy constructor: \n";
    bitmatrix3.print();

    BitMatrix<3, 4> bitmatrix4(std::move(bitmatrix3));
    std::cout << "Move constructor: \n";
    bitmatrix4.print();

    // Checking if bits are set
    std::cout << "Checking if bits are set: " << bitmatrix4.all() << std::endl;
    std::cout << "Checking if no bits are set: " << bitmatrix4.none() << std::endl;
    std::cout << "Checking if any bits are set: " << bitmatrix4.any() << std::endl;

    // Accessing elements
    std::size_t row = 1;
    std::size_t col = 2;
    std::cout << "Accessing element at (1, 2): " << bitmatrix4(row, col) << std::endl;
    std::cout << "Counting number of elements in row 0: " << bitmatrix4.count(0) << std::endl;
    std::cout << "Counting total elements: " << bitmatrix4.count() << std::endl;

    // Testing bitwise operations
    std::cout << "Testing bitwise operation XOR:\n";
    BitMatrix<3, 4> bitmatrix5 = bitmatrix4 ^ bitmatrix2;
    bitmatrix5.print();

    std::cout << "Testing bitwise operation OR:\n";
    BitMatrix<3, 4> bitmatrix6 = bitmatrix5 | bitmatrix2;
    bitmatrix6.print();

    std::cout << "Testing bitwise operation AND:\n";
    BitMatrix<3, 4> bitmatrix7 = bitmatrix5 & bitmatrix2;
    bitmatrix7.print();

    return 0;
}

