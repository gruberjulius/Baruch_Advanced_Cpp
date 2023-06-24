#include <ratio>
#include <iostream>


int main() {

	// Part a

	typedef std::ratio<1, 4> r1;
	std::cout << r1::num << "/" << r1::den << std::endl;
	typedef std::ratio<3, 5> r2;
	std::cout << r2::num << "/" << r2::den << std::endl;
	typedef std::ratio<1, 1> r3;
	std::cout << r3::num << "/" << r3::den << std::endl;
    //works as expected

	// Part b

	typedef std::ratio_add<r1, r2> sum;
	std::cout << sum::num << "/" << sum::den << std::endl;

	typedef std::ratio_subtract<r1, r2> difference;
	std::cout << difference::num << "/" << difference::den << std::endl;

	typedef std::ratio_multiply<r1, r2> product;
	std::cout << product::num << "/" << product::den << std::endl;

	typedef std::ratio_divide<r1, r2> quotient;
	std::cout << quotient::num << "/" << quotient::den << std::endl;
	//works as expected
}
