#include <random>
#include <boost/random.hpp>
#include <boost/random/generate_canonical.hpp>
#include <iostream>

int main() {
	
	// Part A
    boost::random::lagged_fibonacci607 eng;  // fibonacci engine
    boost::triangle_distribution<> triDis;   // triangle distribution
    boost::variate_generator<boost::random::lagged_fibonacci607,
                             boost::triangle_distribution<>>triRng(eng, triDis);
    std::cout << "variate generator output: " << triRng() << std::endl;

	// Part B
	
	std::cout << boost::random::generate_canonical<float, 4>(eng) << std::endl;
	std::cout << boost::random::generate_canonical<float, 8>(eng) << std::endl;
	std::cout << boost::random::generate_canonical<float, 16>(eng) << std::endl;
	std::cout << boost::random::generate_canonical<float, 32>(eng) << std::endl;
}
