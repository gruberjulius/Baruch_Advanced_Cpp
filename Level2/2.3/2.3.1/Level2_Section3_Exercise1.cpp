#include<iostream>

[[deprecated("Deprecated global variable")]]
void deprecatedFunction(){
    std::cout << " depreceated function called" << std::endl;
}
// deprecated global variable
[[deprecated("Deprecated global variable")]]
int deprecatedGlobal = 0;

//deprecated class
class [[deprecated("Deprecated class")]] DeprecatedClass{
public: 
    DeprecatedClass(){
        std::cout << "Called the Default Constructor of the Deprecated Class" << std::endl;
    }
};

//deprecated Default constructor
class  SampleClass{
public: 
    SampleClass() {}
    [[deprecated("Deprecated Member Function")]] void DeprecatedMemberFunction(){
        std::cout << "Called the Default Constructor of the Deprecated Class" << std::endl;
    };
};


template <typename T> class sample{};

template <> class [[deprecated("non abstract template specifiction")]] sample<int> {};

enum [[deprecated("Deprecated global variable")]] literal { a, b, c};   
 
enum class[[deprecated("Deprecated Member Function")]] more_literal{d, e, f};

int main(){
    deprecatedFunction();
    std::cout << deprecatedGlobal << std::endl;
    DeprecatedClass();


    //DeprecatedEnum();
    SampleClass a;
    a.DeprecatedMemberFunction();

    //literal sample1 = a;
    //more_literal sample2 = d;
    //deprecated lambda function
    [[deprecated("Deprecated Lambda")]] auto func = [](){
        std::cout << "Called Depreceated Lambda" << std::endl;
    };

    func();

    //deprecated template
   
    sample<int> A;

    return 0;
}
