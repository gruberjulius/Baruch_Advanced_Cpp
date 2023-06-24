#include<iostream>

//Given Code

struct X {
    double val;
    X() :  val(0.0) {}
    void operator () ()
    {
        std::cout << "An X " << val << std::endl;
    }
}; 

//C++11
template <typename T>
using GenericPointerType = std::shared_ptr<T>;
using PointerType = GenericPointerType<X>;

int main(){
    //Part a
    PointerType x  = std::make_shared<X>(); // Create an instance of PointerType

    // Give it a value
    x->val = 3.14;

    //Part b
    PointerType x1 = std::make_shared<X>(); // Create an instance of PointerType

    // Give x a value
    x1->val = 3.14;

    PointerType x2 = std::make_shared<X>(); // Create a second instance of PointerType

    // Give x2 a value
    x2->val = 4.56;
    std::atomic_store(&x1, x2);
    /*
    {
        std::lock_guard<std::mutex> lock(std::mutex); // Acquire the lock

        // Atomically store x2's value in x
        x1 = x2;
    }
    */
    std::cout << "x1->val = " << x1->val << std::endl; // Print the value of x1
    std::cout << "x2->val = " << x2->val << std::endl; // Print the value of x2
    
    PointerType x3 = std::make_shared<X>(); // Create a third instance of PointerType
    x3->val = 1.0;
    PointerType oldx3 = std::atomic_exchange(&x3, x);
    std::cout << "new value of x3" << x3->val << ", old value of x3:" << oldx3->val << std::endl;
    
    PointerType oldx2 = std::atomic_exchange(&x2, x);

    std::cout << "new value of x2" << x2->val << ", old value of x2:" << oldx2->val << std::endl;
    //works as expected
    
    //Part d 
    
    //number of shared pointers is for every element:

    // use counts of each shared_pointer is:
    std::cout << "number of shared pointer instances for x: " << x.use_count() << std::endl;
    std::cout << "number of shared pointer instances for x1: " << x1.use_count() << std::endl;
    std::cout << "number of shared pointer instances for x2: " << x2.use_count() << std::endl;
    std::cout << "number of shared pointer instances for x3: " << x3.use_count() << std::endl;
    // Part e    
    //std::shared_ptr involves non-trivial operations, such as reference
    //couning and memeory deallocatio, which cannot be guaranteed to be atomic
    //Types must be trivally copyable, which is not true for std::shared_ptr

    //Part f
    //No, they are not look free. The reference counting mechanism by 
    //std::shared_ptr requires atomic operations to increment and decrement
    //the reference count. These atomic operations typically involve locks
    //or other synchronoization methods.
}
