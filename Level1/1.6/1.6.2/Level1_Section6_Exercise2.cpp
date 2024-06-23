#include<iostream>
#include <vector>
#include <functional>
#include <algorithm>


using InputFunction = std::function<double()>;
using OutputFunction = std::function<void(const std::vector<double>&)>;

class TMPClass final
{
// Part a

private:
	std::vector<double> vec;
	InputFunction in_function;
	OutputFunction out_function;

public:
// Part b
	// constructor with the size of vector, the value of each element and the functions
	TMPClass(std::size_t n, double startValue, InputFunction iFunction, OutputFunction oFunction) {
		in_function = iFunction;
		out_function = oFunction;
		for (int i{ 0 }; i < n; ++i) { vec.push_back(startValue); };
	};
	// applying both in and out functions
	void out() {
		std::transform(vec.begin(), vec.end(), vec.begin(), [this](double i) {return i * in_function(); });
		return out_function(vec);
	}
};


//create a function 
using InputFunction = std::function<double()>;
//create a function object 
using OutputFunction = std::function<void(const std::vector<double>&)>;

int main() {
	std::vector<double> vec(10);
	double startValue{1.0};
	
	// Setting input and output functions
	// in function is just returning a constant value
	double inValue{ 1 };
	InputFunction in_function = [=]() {return inValue; };
	// out function is just printing each element of the vector
	OutputFunction out_function = [](const std::vector<double>& in_vec) { 
		for (auto elem : in_vec) { std::cout << elem << ", "; }; 
		std::cout << std::endl;
	};

	std::size_t n{ 5 };
	//define an algo by including the in_function, out_function a starting value and the number of elements
	TMPClass algo(n, startValue, in_function, out_function);
	algo.out();
	// we got indeed 3 for a vector of 10 values, works proprely as expected
	return 0;
}

