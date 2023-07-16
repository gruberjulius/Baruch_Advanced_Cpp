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
	//repetition of the command do not need to do that
	//void draw() const override {}
	//Same as in the base function
	//void print() override {}
	~Derived() { std::cout << "bye derived\n"; }
};

class Derived2 final: public Derived
{

};

int main(){
	//check 
	std::shared_ptr<Base> base_ptr{ new Base()};
	std::shared_ptr<Base> derived_ptr{ new Derived()};
	std::shared_ptr<Base> derived_2_ptr{ new Derived2()};
	
	std::shared_ptr<Derived> derived_3_ptr{ new Derived()};
	std::shared_ptr<Derived> derived_4_ptr{ new Derived2()};

	std::shared_ptr<Derived2> derived_5_ptr{ new Derived2()};
	base_ptr->draw();
	derived_ptr->draw();
	derived_2_ptr->draw();
	derived_3_ptr->draw();
	derived_4_ptr->draw();
	derived_5_ptr->draw();
	//works as expected in all abstractions
	return 0;
}
