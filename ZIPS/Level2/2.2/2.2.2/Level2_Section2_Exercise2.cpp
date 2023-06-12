#include <iostream>
#include<complex>
#include<vector>
#include <type_traits>

class sample{};

int main() {
    std::cout << " Part A " << std::endl;
    // Fundamental types int, float, char
    std::cout << "int is array? " << std::is_array<int>::value << std::endl;
    std::cout << "float is array? " << std::is_array<float>::value << std::endl;
    std::cout << "char is array? " << std::is_array<char>::value << std::endl;

    // Scalar types bool and double 
    std::cout << "bool is array? " << std::is_array<bool>::value << std::endl;
    std::cout << "double is array? " << std::is_array<double>::value << std::endl;

    // Object types string and vector
    sample a{};  
    //std::cout << "class is array? " << std::is_array<decltype(sample)>::value << std::endl;
    std::cout << "class is array? " << std::is_array<decltype(a)>::value << std::endl;
    std::cout << "std::string is array? " << std::is_array<std::string>::value << std::endl;
    std::cout << "std::vector<int> is array? " << std::is_array<std::vector<int>>::value << std::endl;

    // Arithmetic types 
    std::cout << "std::complex<double> is array? " << std::is_array<std::complex<double>>::value << std::endl;

    // Compound types
    int arr[5];

    std::cout << "int[] is array? " << std::is_array<decltype(arr)>::value << std::endl; //true
    std::cout << "std::array<int, 5> is array? " << std::is_array<std::array<int, 3>>::value << std::endl;
    std::cout << "std::vector<int> is array? " << std::is_array<std::vector<int>>::value << std::endl;
    //works as expected


    std::cout << " Part B " << std::endl;
    int b[][3][4][5] ={0};
    std::cout << "Check rank :" << std::rank<decltype(b)>::value <<std::endl;
    std::cout << "Check for extent without input:" << std::extent<decltype(b), 0>::value <<std::endl;
    std::cout << "Check for extent 0 " << std::extent<decltype(b), 0>::value <<std::endl;
    std::cout << "Check for extent 1 " << std::extent<decltype(b), 1>::value <<std::endl;
    std::cout << "Check for extent 2 " << std::extent<decltype(b), 2>::value <<std::endl;
    std::cout << "Check for extent 3 " << std::extent<decltype(b), 3>::value <<std::endl;

    using b1 = std::remove_extent<decltype(b)>::type;
    std::cout << "Rank after remove " << std::rank<b1>::value << std::endl;


    using b2 = std::remove_all_extents<decltype(b)>::type;
    std::cout << "Rank after remove " << std::rank<b2>::value << std::endl;

    return 0;


}

