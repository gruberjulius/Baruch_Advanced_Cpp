#include<iostream>
#include <list>
#include<vector>

// Base class
class Base
{
private:
public:
    Base() { }
    virtual void print() const = 0;
protected:
    virtual ~Base() { std::cout << "Base destructor\n\n"; }
};

// Derived class
class Derived : public Base
{
private:
public:
    Derived() : Base() { }
    ~Derived() { std::cout << "Derived destructor\n"; }
    void print() const { std::cout << "derived object\n";}
};

//factory function to create instance
std::shared_ptr<Base> createDerived(){
    return std::make_shared<Derived>();
}


int main(){
	//Part A
    //list to shared ptrs, 
    //will not compile because the destructor is protected
    //std shared_ptr can handle the problem by getting the Derived function from the Derived Class
    //std unique_ptr can not handle it 
    std::list<std::shared_ptr<Base>> baseListShared_2;
//    std::list<std::unique_ptr<Base>> baseListShared_3(3);

    baseListShared_2.push_back(createDerived());
    baseListShared_2.push_back(createDerived());
    baseListShared_2.push_back(createDerived());
    for(auto & x: baseListShared_2){
        x->print();
    } 
    //no memory leaks
    return 0;
}
