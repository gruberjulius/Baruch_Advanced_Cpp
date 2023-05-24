#include<iostream>
#include <tuple>
#include <complex>


template <typename T, typename Tuple, std::size_t N>
struct Calculator
{
	static T max(const Tuple& tuple)
	{
		if(std::get<N - 1>(tuple) > Calculator<T, Tuple, N - 1>::max(tuple))
		{
			T max_value = std::get<N - 1>(tuple);
			return max_value;
		}
		else
		{
			T max_value = Calculator<T, Tuple, N - 1>::max(tuple);
			return max_value;
		}
	}

	static T sum(const Tuple& tuple){
		T total = std::get< N - 1>(tuple) + Calculator<T, Tuple, N- 1>::sum(tuple);
		return total;
	}

	static T average(const Tuple& tuple){
		T total = sum(tuple);
		T average = total/(static_cast<T>(N));
		return average;
	}
};

//Ending recursive function
template <typename T, typename Tuple>
struct  Calculator<T, Tuple, 1>
{
	static T max(const Tuple& tuple){
		T max_value = std::get<0>(tuple);
		return max_value;
	}


	static T sum(const Tuple& tuple){
		T total = std::get<0>(tuple);
		return total;
	}
};

using Complex_Tuple =  std::tuple<std::complex<float>, std::complex<float>,std::complex<float>>;


int main(){
	std::tuple<double, double, double> tuple1 = std::make_tuple(30.0, 31.0, 32.0);

	std::tuple<double, double> tuple2 = std::make_tuple(10.0, 11.0);

	std::cout << Calculator<double, std::tuple<double, double, double> , 3>::max(tuple1) << std::endl;
	std::cout << Calculator<double, std::tuple<double, double, double> , 3>::sum(tuple1) << std::endl;
	std::cout << Calculator<double, std::tuple<double, double, double> , 3>::average(tuple1) << std::endl;

	std::cout << Calculator<double, std::tuple<double, double> , 2>::max(tuple2) << std::endl;
	std::cout << Calculator<double, std::tuple<double, double> , 2>::sum(tuple2) << std::endl;
	std::cout << Calculator<double, std::tuple<double, double> , 2>::average(tuple2) << std::endl;
	//works as expected


	Complex_Tuple  complex_elem = std::make_tuple(std::complex<float>{10, -2}, std::complex<float>{11, -3}, std::complex<float>{12, -4});


	//code breaks totally: we did not define a comparison operator for complex so it does not work
	//std::cout << Calculator<std::complex<float>, Complex_Tuple , 3>::max(complex_elem) << std::endl; 
	std::cout << Calculator<std::complex<float>, Complex_Tuple , 3>::sum(complex_elem) << std::endl;
	std::cout << Calculator< std::complex<float> , Complex_Tuple , 3>::average(complex_elem) << std::endl;

	return 0;
}
