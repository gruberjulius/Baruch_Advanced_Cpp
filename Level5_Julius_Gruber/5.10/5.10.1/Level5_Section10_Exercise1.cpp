#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <algorithm>

int main(){
    //Part A

    boost::numeric::ublas::vector<double> v1(3, 1);
    v1[1] = 1;
    v1(2) = 2;
    std::cout << v1 << std::endl;

    //Part B
    boost::numeric::ublas::vector<double> v2(3, 3);

    std::cout << (v1 += v2) << std::endl;
    std::cout << (v1 *= 2.5) << std::endl;
    std::cout << (v1 -= v2) << std::endl;

    //Part C

    boost::numeric::ublas::vector<double> v3(3, 1);
    std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), std::multiplies<double>());
    std::cout << v3 << std::endl;

    //Part D

    boost::numeric::ublas::scalar_vector<double> v4(100, 42.0);

    std::cout << v4 << std::endl;

}

