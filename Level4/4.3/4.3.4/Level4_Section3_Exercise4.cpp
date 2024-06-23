#include <random>
#include <cmath>
#include <iostream>

int main() {

	// Part a

	// set engine and seed for the random generation
	std::random_device rd;
	std::mt19937 gen{ rd() };
	
	// Part b

	//two instances on the unit interval
	std::uniform_real_distribution<double> dist_x(0, 1);
	std::uniform_real_distribution<double> dist_y(0, 1);

	// Part c,d

	int N = 0;
	int counter = 0;
    //looping through different trial sizes
	for (int i  =0 ; i < 10; ++i) {
		N = std::pow( 10, i);
		counter = 0;
		// generating x and y randomly
		for (int j =  0 ; j < N; ++j) {
			double x{ dist_x(gen) };
			double y{ dist_y(gen) };
			// adding to counter if larger than 1
			if (std::sqrt(x * x + y * y) < 1) { ++counter; };
		}
        std::cout << "For size N = "<< N << " we get the following" <<
            " approximation " << 4*  counter/(double)N << std::endl;
	}
    //need about 10^9 to get the right approximation

}
