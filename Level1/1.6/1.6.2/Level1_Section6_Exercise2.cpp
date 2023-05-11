#include<iostream>
#include <vector>
#include <functional>
#include <algorithm>


using InputFunction = std::function<double()>;
using OutputFunction = std::function<void(const std::vector<double>&)>;

class TMPClass final
{
// PART A)

private:
	std::vector<double> vec;
	InputFunction in_function;
	OutputFunction out_function;

public:
// PART B)
	// consttructor with the size of vector, the value of each element and the functions
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



using InputFunction = std::function<double()>;
using OutputFunction = std::function<void(const std::vector<double>&)>;

int main() {
	std::vector<double> vec(10);
	double startValue{1.0};
	
	// Setting input and output functions
	// in function is just a constant value
	double inValue{ 3.14 };
	InputFunction in_function = [=]() {return inValue; };
	// out function is just printing each element of the vector
	OutputFunction out_function = [](const std::vector<double>& in_vec) { 
		for (auto elem : in_vec) { std::cout << elem << ", "; }; 
		std::cout << std::endl;
	};

	std::size_t n{ 10 };
	TMPClass algo(n, startValue, in_function, out_function);
	algo.out();
	// we got indeed 3.14 for a vector of 10 values, works proprely
}




/*#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>

using InputFunction = std::function<double ()>;
using OutputFunction = std::function<void (const std::vector<double>&)>;

class TMPClass 
{
private:
	std::size_t _n;
	double _start_value;
	std::vector<double> _content;
	InputFunction _iFunction;
	OutputFunction _oFunction;

public:
	TMPClass(std::size_t n, double startValue, InputFunction iFunction, OutputFunction oFunction): 
		_n(n), _start_value(startValue), _iFunction(iFunction), _oFunction(oFunction)
	{
		for(int i = 0; i  < n; i++){
			_content.push_back(startValue);
		}
	}
	void out (){
		auto infunction = [this](double i ){return i* _iFunction();}; 
		std::transform(_content.begin(), _content.cend(), _content.begin(), infunction ) ;
		return _oFunction(  _content);
	}
	
};

int main(){
	std::vector<double> vec(10);
	double startValue{1.0};
	double inValue{2.0};

	InputFunction in_function = [=](){return inValue;};

	OutputFunction out_function = [](const std::vector<double>& in_vec){
		for(auto elem: in_vec){
			std::cout << elem << ", ";
		}
		std::cout << std::endl;
	};

	std::size_t n{10};
	TMPClass algo(n, startValue, in_function, out_function);
	algo.out();


	return 0;
}*/