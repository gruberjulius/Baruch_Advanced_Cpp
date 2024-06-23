#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>

int main() {

	// Part A

	boost::numeric::ublas::matrix<double> m1(3, 3, 0);
	boost::numeric::ublas::matrix<double, boost::numeric::ublas::column_major> m2(3, 3, 0);

	// Part B

	m1(0, 0) = 1; m1(1, 0) = 2; m1(2, 0) = 3;
	m2(0, 0) = 1; m2(1, 0) = 2; m2(2, 0) = 3;
	std::cout << m1 << std::endl;
	std::cout << m2 << std::endl;

	// Part C

	auto m3 = m1 + m2;
	std::cout << m3 << std::endl;
	auto m4 = m1 - m2;
	std::cout << m4 << std::endl;

	// Part D

	m1.resize(2, 3);
	std::cout << m1 << std::endl;

	// Part E

	boost::numeric::ublas::zero_matrix<double> zero(2, 2);
	std::cout << zero << std::endl;
	boost::numeric::ublas::identity_matrix<double> identity(2);
	std::cout << identity << std::endl;


}
