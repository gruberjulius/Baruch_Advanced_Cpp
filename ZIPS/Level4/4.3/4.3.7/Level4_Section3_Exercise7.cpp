
#include <random>
#include <vector>
#include <numeric>
#include <iostream>

// Part a
// Function that computes the chi-squared statistic with given parameters
double chi_squared(const std::vector<int>& observations, const std::vector<double>& freqs) {
    // Getting total number of observations
    int N = std::accumulate(observations.begin(), observations.end(), 0);
    double chi = 0.0;

    for (size_t i = 0; i < observations.size(); ++i) {
        double expected = N * freqs[i];
        double deviation = static_cast<double>(observations[i]) - expected;
        chi += (deviation * deviation) / expected;
    }

    return chi;
}

int main(){

	// Part B 
	std::vector<int> observations{ 4,4,8 };
	std::vector<double> freqs{ 0.25, 0.25, 0.5 };
	std::cout << chi_squared(observations, freqs) << std::endl;
    //observations match frequency, should return 0
	
	observations = { 1,0 };
	freqs = { 0.03, 0.97 };
	std::cout << chi_squared(observations, freqs) << std::endl;
    //very high as expected, as it is not matching at all

	// Part C
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, 10);

	observations = {};
    freqs = {};
    int k = 9;
	for (int i = 0 ; i < k + 1 ; ++i) {
		observations.push_back(dist(gen));
        freqs.push_back(1./(k +1));
	}

	std::cout << chi_squared(observations, freqs) << std::endl;
    
    //not to big
}
