#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cmath>

// Part A
// Template struct with a static method to find the best matching index where values are between x
template <typename T, typename X_t, typename Vec, std::size_t N>
struct Finder {
    static int best_index(const Vec& v, X_t x) {
        // Checking if the target value is in the range
        if (v.front() > x || v.back() < x) {
            std::cout << "Target value is not in the range of the vector" << std::endl;
            return -1;
        } else {
            // As the vector is sorted, we know that if the next value of the vector is bigger than x,
            // then we found the interval
            for (int i = 1; i < N; ++i) {
                if (v[i] > x) {
                    return i - 1;
                }
            }
        }
        // Return a value if no interval found
        return -1;
    }
};

// PART B
// Types of errors
enum class ErrorTypes {
    absoluteError,
    relativeError,
    absoluteRelativeError
};

template <typename T, typename Vec, std::size_t N>
struct CompareVector {
    static std::tuple<T, int> max_error(const Vec& v1, const Vec& v2, int i, int j, ErrorTypes errorType) {
        if (i < 0 || i > j || j > N) {
            std::cout << "i and j must be in range, with i smaller than or equal to j" << std::endl;
            return std::make_tuple(T(-1), -1);
        } else {
            std::vector<T> error;

            for (int k = i; k <= j; ++k) {
                // If the value is zero, then relative errors are undefined
                if (v1[k] != T(0)) {
                    // Computing errors based on the error type
                    switch (errorType) {
                        case ErrorTypes::absoluteError:
                            error.push_back(std::abs(v2[k] - v1[k]));
                            break;
                        case ErrorTypes::relativeError:
                            error.push_back((v2[k] - v1[k]) / v1[k]);
                            break;
                        case ErrorTypes::absoluteRelativeError:
                            error.push_back(std::abs(v2[k] - v1[k]) / v1[k]);
                            break;
                    }
                } else {
                    // Computing errors based on the error type
                    switch (errorType) {
                        case ErrorTypes::absoluteError:
                            error.push_back(std::abs(v2[k] - v1[k]));
                            break;
                        case ErrorTypes::relativeError:
                        case ErrorTypes::absoluteRelativeError:
                            error.push_back(T(-1));
                            break;
                    }
                }
            }
            // Finding the max element
            auto maxIdx = std::max_element(error.begin(), error.end());
            // Returning the max error and index in the whole vector (so + i)
            return std::make_tuple(*maxIdx, static_cast<int>(maxIdx - error.begin()) + i);
        }
    }
};

int main() {
    // Part a 
    std::vector<int> vec(10);
    for (int i = 0; i < 10; ++i) {
        vec[i] = i;
    }
    std::cout << "Vector: ";
    for (auto val : vec) {
        std::cout << val << ", ";
    }
   
    std::cout << std::endl;
	double x{3.5};
	std::cout << "Finding value: " << x << std::endl;
	std::cout << "Best Index: " << Finder<int, double, std::vector<int>, 10>::best_index(vec, x) << std::endl;

	// PART b 
	std::vector<double> vec2(10);
	for (int i{0}; i < 10; ++i)
	{
		vec2[i] = ((5 * i) % 12 - 4.7) * 2.5;
	};
	std::cout << "Vector 1: ";
	for (auto val : vec2)
	{
		std::cout << val << ", ";
	};
	std::cout << std::endl;
	std::vector<double> vec3(10);
	for (int i{0}; i < 10; ++i)
	{
		vec3[i] = ((5 * i) % 12 + 2.3) * 1.3;
	};
	std::cout << "Vector 2: ";
	for (auto val : vec3)
	{
		std::cout << val << ", ";
	};
	std::cout << std::endl;

	auto res1{CompareVector<double, std::vector<double>, 10>::max_error(vec2, vec3, 2, 8, ErrorTypes::absoluteError)};
	std::cout << "Absolute Error: index: " << std::get<1>(res1) << ", value: " << std::get<0>(res1) << std::endl;

	auto res2{CompareVector<double, std::vector<double>, 10>::max_error(vec2, vec3, 2, 8, ErrorTypes::relativeError)};
	std::cout << "Relative Error: index: " << std::get<1>(res2) << ", value: " << std::get<0>(res2) << std::endl;
    auto res3{CompareVector<double, std::vector<double>, 10>::max_error(vec2, vec3, 2, 8, ErrorTypes::absoluteRelativeError)};
	std::cout << "Relative Error: index: " << std::get<1>(res2) << ", value: " << std::get<0>(res2) << std::endl;

	// the relative and the absolute error are different
	return 0;
}


