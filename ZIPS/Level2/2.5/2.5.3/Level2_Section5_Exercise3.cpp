#include<iostream>

#include <boost/math/special_functions/next.hpp>
#include <boost/math/special_functions/ulp.hpp>

int main(){

    double a = 0.1;
    double b = a + std::numeric_limits<double>::min();
    std::cout << boost::math::float_distance(a, b) << std::endl;
    a = 1.0; b = 0.0;
    std::cout << boost::math::float_distance(a, b) << std::endl;
    float c = 1.0;

    std::cout << "Next representable value that is bigger than c " <<boost::math::float_next(c) << std::endl;
    
    std::cout << "Next representable value that is smaller than x " <<  boost::math::float_prior(c) << std::endl;

    float d = 0.0002;
    float e = 0.0003;

    std::cout << "Return the float distance for two different values " << boost::math::float_distance(d, e) << std::endl;
    float ulp_dist =  boost::math::ulp(e) -   boost::math::ulp(d);
//    std::cout << "Return the float distance for two different values" << ulp_dist << std::endl;

    float start = 0.0;
    std::cout << "Before float advance " << start << std::endl;
    std::cout << "After float advance " << boost::math::float_advance(start, 999) << std::endl;

    float f = 1.0;
    std::cout << "Next representable value after " << start << " in different directions " << f 
        << " is " << boost::math::nextafter(start, f) << std::endl;
    return 0;
}
