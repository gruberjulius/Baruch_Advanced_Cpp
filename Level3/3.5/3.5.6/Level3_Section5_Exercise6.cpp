#include "watch.hpp"
#include <thread>

#include <iostream>
#include <random>

// settting random seeds
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distribution(1, 500);

int main() {

	watch watch;
	
	for (int i{ 0 }; i < 10; ++i) {
		int theoriticalWaitTime{ distribution(gen) };
		watch.Startwatch();
		std::this_thread::sleep_for(std::chrono::milliseconds(theoriticalWaitTime));
		watch.Stopwatch();
		std::cout << "calculated time by watch: " << watch.GetTime() << ", waiting time from random: " 
			<< theoriticalWaitTime / 500.0 << std::endl;

	}
    //matches the expected waiting time

	watch.Reset();
	std::cout << "time by watch after reset: " << watch.GetTime() << std::endl;
    //at 0 as expected
	
    return 0;
}
