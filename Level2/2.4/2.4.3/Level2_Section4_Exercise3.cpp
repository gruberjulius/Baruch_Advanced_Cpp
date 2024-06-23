#include <memory>
#include<iostream>

int main(){

    // Define auto_ptr pointers instead of raw pointers
    // std::auto_ptr <double> d(new double (1.0));

    // Dereference
    // *d = 2.0;

    // Change ownership of auto_ptr
    // (after assignment, d is undefined)
    // std::auto_ptr <double> d2 = d;
    // *d2 = 3.0;

    // std::cout <<"Auto values: "<< *d.get() <<", "<< *d2.get();
	
	//Part A:
    // Code does not compile because auto_ptr is depreceated or removed in newer c++ versionS
    //Part B:
    std::cout << "Using shared_ptr instead" << std::endl;
    std::unique_ptr <double> d(new double (1.0));

    // Dereference
    *d = 2.0;

    // Change ownership of auto_ptr
    // (after assignment, d is undefined)
    std::unique_ptr <double> d2 = d;
    *d2 = 3.0;

    std::cout <<"Auto values: "<< *d.get() <<", "<< *d2.get();
    //error: call to implicitly-deleted copy constructor of 
    //'std::unique_ptr<double>'

    return 0;
}
