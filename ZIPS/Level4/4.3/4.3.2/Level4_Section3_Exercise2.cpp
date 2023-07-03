#include <map>
#include <random>
#include <string>
#include <iostream>

// Part a

// Template function to iterate and print a map
template <typename Map>
void print(const Map& map) {
    std::cout << "{";
    for (const auto& elem : map) {
        std::cout << elem.first << ':' << elem.second << ", ";
    }
    std::cout << "}" << std::endl;
}

// Template function to generate random numbers
template <typename Dist, typename Eng>
void generateRandomNumbers(Dist d, Eng eng, int nTrials, const std::string& s) {
    std::map<long long, int> counter;
    for (int i = 0; i < nTrials; ++i) {
        ++counter[d(eng)];
    }
    std::cout << s << std::endl;
    print(counter);
}

int main() {

    // Part b

    std::mt19937 gen;

    std::geometric_distribution<> d1;
    std::uniform_real_distribution<double> d2(0, 1);
    std::poisson_distribution<> d3(1);

    generateRandomNumbers(d1, gen, 100, "geometric");
    generateRandomNumbers(d2, gen, 100, "uniform");
    generateRandomNumbers(d3, gen, 100, "poisson");

    // Part c
    // Distributions look like expected


    return 0;
}

