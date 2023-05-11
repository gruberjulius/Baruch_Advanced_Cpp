#include<iostream>
#include<memory>

struct Base
{
	virtual void draw() { std::cout << "print a base\n"; }
	void print() {}
	~Base() { std::cout << "bye base\n"; }
};

//remove final keyword in the class
struct Derived  : public Base
{
	Derived() {}
	void draw() override
		{ std::cout << "print a derived\n"; }
	//repetitio of the command do not need to do that
	//void draw() const override {}
	//Same as in the base function
	//void print() override {}
	~Derived() { std::cout << "bye derived\n"; }
};

class Derived2 : public Derived
{

};

int main(){

	std::shared_ptr<Base> base_ptr{ new Base()};
	std::shared_ptr<Base> derived_ptr{ new Derived()};

	base_ptr->draw();
	derived_ptr->draw();
	return 0;
}
