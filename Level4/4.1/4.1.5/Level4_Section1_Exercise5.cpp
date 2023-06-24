#include "Vector.h"
#include "Matrix.h"

#include <array>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <complex>

// Part a

// function that computes inner product of two vectors using the STL
template <typename T, int N>
T inner_product(const Vector<T, N>& v1, const Vector<T, N>& v2, T initValue) {
	return std::inner_product(v1.begin(), v1.end(), v2.begin(), initValue);
};

// for complex numbers
template <typename T>using BinaryFunction = std::function < T(const T& t1, const T& t2)>;

template <typename T, int N>
T inner_product(const Vector<T, N>& v1, const Vector<T, N>& v2, T initValue, const BinaryFunction<T>& op1, const BinaryFunction<T>& op2) {
	return std::inner_product(v1.begin(), v1.end(), v2.begin(), initValue, op1, op2);
};

// Part d

// function that computes outer product of two vectors
template <typename T, int N>
Matrix<T, N, N> outer_product(const Vector<T, N>& v1, const Vector<T, N>& v2) {
	Matrix<T, N, N> res;
	int row = 0;
	// iterating over the first vector and its rows
	std::for_each(v1.begin(), v1.end(), [&](T value) {
		// storing ith row in res, by multiplying the second vector by the ith element of the first vector
		std::transform(v2.begin(), v2.end(), res[row].begin(), [value](T value2) {
			return std::multiplies<T>()(value, value2);
		});
			++row;
	});
	return res;
};


int main() {

	// Part a

	Vector<double, 4> vec = std::array<double, 4>{1, 2, 3, 4};
	std::cout << "Inner Product: " << inner_product(vec, vec, 0.0) << std::endl;

	// Part c

	// add binary function
	BinaryFunction<double> ADD = [](const double& t1, const double& t2) {return t1 + t2; };

	// subtract binary function
	BinaryFunction<double> SUB = [](const double& t1, const double& t2) {return t1 - t2; };

	std::cout << "Add, Add: " << inner_product(vec, vec, 0.0, ADD, ADD) << std::endl;
	std::cout << "Add, Subtract: " << inner_product(vec, vec, 0.0, ADD, SUB) << std::endl;
	std::cout << "Subtract, Add: " << inner_product(vec, vec, 0.0, SUB, ADD) << std::endl;
	std::cout << "Subtract, Subtract: " << inner_product(vec, vec, 0.0, SUB, SUB) << std::endl;

	// Part d

	Matrix<double, 4, 4> outer_productres{ outer_product(vec, vec) };
	std::cout << "Outer Product Matrix: " << std::endl;
    std::cout << outer_productres << std::endl;
	// Part e

    Vector<std::complex<double>, 3> complexVec = std::array<std::complex<double>, 3>{std::complex<double>(1, 0), std::complex<double>(0, 1), std::complex<double>(1, 1)};
	Matrix<std::complex<double>, 3, 3> opcomplexres{ outer_product(complexVec, complexVec) };
	std::cout << "Outer Product Matrix (Complex): " << std::endl;
    std::cout << opcomplexres << std::endl;
	return 0;
}

