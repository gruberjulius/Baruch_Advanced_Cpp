#include <boost/functional/hash.hpp>
#include <functional>
#include <iostream>
#include <string>
#include <limits>
#include <sstream>

//Part A
template <typename T>
std::size_t hashWithBoost(const T& data) {
    boost::hash<T> hasher;
    return hasher(data);
}


template <typename T>
std::size_t hashWithCpp11(const T& data) {
    std::hash<T> hasher;
    return hasher(data);
}


int main() {
    //Part B
    // Test integers
    int intValue = 42;
    std::size_t hashBoostInt = hashWithBoost(intValue);
    std::size_t hashCpp11Int = hashWithCpp11(intValue);
    std::cout << "Hash of integer " << intValue << " (Boost): " << hashBoostInt << std::endl;
    std::cout << "Hash of integer " << intValue << " (C++11): " << hashCpp11Int << std::endl;

    // Test strings
    std::string stringValue = "Hello, world!";
    std::size_t hashBoostString = hashWithBoost(stringValue);
    std::size_t hashCpp11String = hashWithCpp11(stringValue);
    std::cout << "Hash of string \"" << stringValue << "\" (Boost): " << hashBoostString << std::endl;
    std::cout << "Hash of string \"" << stringValue << "\" (C++11): " << hashCpp11String << std::endl;

    // Test pointers
    int* pointerValue = &intValue;
    std::size_t hashBoostPointer = hashWithBoost(pointerValue);
    std::size_t hashCpp11Pointer = hashWithCpp11(pointerValue);
    std::cout << "Hash of pointer " << pointerValue << " (Boost): " << hashBoostPointer << std::endl;
    std::cout << "Hash of pointer " << pointerValue << " (C++11): " << hashCpp11Pointer << std::endl;

    // Test std::numeric_limits<long>::max()
    long maxValue = std::numeric_limits<long>::max();
    std::size_t hashBoostMaxValue = hashWithBoost(maxValue);
    std::size_t hashCpp11MaxValue = hashWithCpp11(maxValue);
    std::cout << "Hash of max value " << maxValue << " (Boost): " << hashBoostMaxValue << std::endl;
    std::cout << "Hash of max value " << maxValue << " (C++11): " << hashCpp11MaxValue << std::endl;


    std::string str1 = "Hello";
    std::string str2 = "World";

    std::size_t h1 = hashWithBoost(str1);
    std::size_t h2 = hashWithBoost(str2);
    std::size_t result = h1 ^ (h2 << 1);

    std::cout << "Hash of \"" << str1 << "\": " << h1 << std::endl;
    std::cout << "Hash of \"" << str2 << "\": " << h2 << std::endl;
    std::cout << "Result of h1 ^ (h2 << 1): " << result << std::endl;

    return 0;
}




