#include <vector>
#include <random>
#include <iostream>
#include <string>
#include <functional>


// function to print vector of int
std::string print(const std::vector<int>& vec) {
	std::string out{ "[" };
	for (int i{ 0 }; i < vec.size(); ++i) {
		out += std::to_string(vec[i]);
		if (i != vec.size() - 1) { out += ", "; };
	}
	return out + "]\n";
}


// standard rand function
int standard(int size) {
	return std::rand() % size;
}

// user defined random number generator
int user_random(int size) {
	return (3*std::rand() + 1) % size;
}

// part C for function
// function for all other random engines
template <class Gen>
int dist( int size) {
	return std::uniform_int_distribution<>(0, size)(Gen);
}


int main() {
	// Part a
	std::vector<int> vec;
	for (int i = 0; i < 100; ++i){ 
        vec.push_back(i); 
    }
	std::cout << print(vec);
	std::vector<int> copy(vec);

	std::mt19937 gen;
	std::default_random_engine gen2;
	std::linear_congruential_engine<std::uint_fast32_t, 48271, 0, 2147483647> gen3;

	std::random_shuffle(copy.begin(), copy.end());
	std::cout << print(copy);
	copy = vec;

	std::random_shuffle(copy.begin(), copy.end(), standard);
	std::cout << print(copy);
	copy = vec;

	std::random_shuffle(copy.begin(), copy.end(), user_random);
	std::cout << print(copy);
	copy = vec;

	
	// Part c

	std::shuffle(copy.begin(), copy.end(), gen);
	std::cout << print(copy);
	copy = vec;

	std::shuffle(copy.begin(), copy.end(), gen2);
	std::cout << print(copy);
	copy = vec;

	std::shuffle(copy.begin(), copy.end(), gen3);
	std::cout << print(copy);

    return 0;
}
