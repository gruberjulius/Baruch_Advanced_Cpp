#include <iostream>
#include <memory>

int main()
{	
    // PART a 
	// creating weak pointer 
	std::weak_ptr<double> weak;

	// creating shared pointer 
	std::shared_ptr<double> commonValue(new double(3.));
	
	// getting counts of shared pointer 
	std::cout << "Ref count:" << commonValue.use_count() << std::endl;
	
	// set to weak pointer value 
	weak = commonValue;
	
    // getting counts of shared pointer 
	std::cout << "Ref count:" << commonValue.use_count() << std::endl;
    
	// getting count of shared pointer after weak pointer observes it
	std::cout << "Ref count after weak pointer observes shared pointer: " << commonValue.use_count() << std::endl;
    
    //Part b
    
    std::cout << weak.expired() << std::endl; //returns 0 as it is non empty

    //Part c

    std::weak_ptr<int> weak1;
    std::weak_ptr<int> weak2 = weak1;

    std::cout << "Use count: "<< weak1.use_count() << std::endl; //use count not expected

}
