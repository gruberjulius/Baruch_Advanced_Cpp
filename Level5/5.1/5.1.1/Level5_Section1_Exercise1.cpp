#include<iostream>
#include<string>
#include <boost/algorithm/string.hpp>

int main(){
    
    std::string a = " ";
    std::string b = "a ";
    std::string c = " a";
    std::string d = " a ";
    std::string e = " 3a";
    std::string f = "3a ";
    std::string g = " 3a ";
    std::string h = " $3a";
    std::string i = "$3a ";
    std::string j = " $3a ";
    std::string k = "--$3a ";

    //Part A
    //inplace triming
    std::cout << b << std::endl;
    boost::trim(b);
    std::cout << b << std::endl;

    //triming with copy


    std::cout << c << std::endl;
    auto s2_trim {boost::trim_copy(c)};

    std::cout << c << " " << s2_trim << std::endl;

    //Part B

    auto checker = [](char c){return c=='-';};
   
    std::cout << k << std::endl;
    
    boost::trim_if(k, checker);

    std::cout << k << std::endl;

    //Part C

    //startin with
    std::cout << std::boolalpha << boost::istarts_with(g," 3") << std::endl;

    //end with
    std::cout << std::boolalpha << boost::ends_with(h,"a") << std::endl;

    //Part D

    //case sensitive
    std::cout << std::boolalpha << boost::contains(h,"a") << std::endl;

    //non case sensitive
    std::cout << std::boolalpha << boost::contains(h,"A") << std::endl;

    //works as expected
}
