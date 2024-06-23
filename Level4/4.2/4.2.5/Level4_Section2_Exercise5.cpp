#include <vector>
#include <numeric>
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <unordered_set>

// Part a

//multiplication function
int multiply(const std::vector<int> vec) {
	int product = 1;
	for (int elem : vec) { 
        product *= elem; 
    };
	return product;
}

// Part b

// function that filters out elements whose absolute value are below a threshold
std::vector<int> abs_threshold(const std::vector<int> vec, int threshold) {
	std::vector<int> out;
	for (int elem : vec) {
		if ((std::abs(elem) > threshold) && (std::find(out.begin(), out.end(), elem) == out.end()))
		{ out.push_back(elem); };
	};
	return out;
}

// function to print vector
void print(const std::vector<int>& vec) {
	std::cout << "[" ;
	for (int i =  0 ; i < vec.size(); ++i) {
		if (vec[i] != -1) { 
            std::cout << vec[i];

			//out += std::to_string(vec[i]); 
            if (i != vec.size() - 1) { 
                std::cout << ", "; 
            }
		}
	}
    std::cout << "]";
}

bool less_than(const int& elem1, const int& elem2) {
    if (elem1 <= elem2) {
        return true; 
    }
    return false; 
}

int main() {

	// Part a

	std::vector<int> vec{ 1,2,3,4};

	// user-defined function
	std::cout << multiply(vec) << std::endl;

	// predefined stl
	std::cout << std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>()) << std::endl;

	// lambda function definition
	std::cout << std::accumulate(vec.begin(), vec.end(), 1, [](const int elem, const int total) {return elem * total; }) << std::endl;

	// user defined is more readable, but less maintanable as seperate function was defined
	// the lambda function is extra complex
    // STL seems to be the best option
	
	// Part b

	vec = { 1,2,1,4,5,5,-1 };
	int threshold = 2;

	// user-defined
	print(abs_threshold(vec, threshold));

    std::vector<int>::iterator pos3 = remove_if(
        vec.begin(), vec.end(),
        std::bind2nd(std::less_equal<int>(), threshold));  // STL built in function
    vec.erase(pos3, vec.end());

	print(vec);
	vec = { 1,2,1,4,5,5,-1 };

	// lambda 
	vec.erase(std::remove_if(vec.begin(), vec.end(), [threshold](int x) {return std::abs(x) <= threshold; }));
	print(vec);
    // most compact and maintanable one is the STL again
    // the lambda function is also useful


}
