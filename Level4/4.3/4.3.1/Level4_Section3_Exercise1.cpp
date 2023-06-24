#include <random>
#include <iostream>
#include <vector>

// Part c

// Template function to generate a list of random numbers with a generic distribution and generic engine
template <typename T, class Engine, class Dist>
std::vector<T> rand(Engine gen, Dist dist, int size = 10) {
    std::vector<T> out;
    for (int i{0}; i < size; ++i) {
        out.push_back(dist(gen));
    }
    return out;
}

int main() {
    // Part a
    std::linear_congruential_engine<std::uint_fast32_t, 48271, 0, 2147483647> LCG_eng;
    // mt19937 engines
    std::mt19937 mt_eng;
    std::mt19937_64 mt64_eng;

    double A = 0.0;
    double B = 1.0;
    std::uniform_real_distribution<double> dist(A, B);
    int nTrials = 30;

    std::cout << "LCG: ";
    for (int i = 1; i <= nTrials; ++i) {
        std::cout << dist(LCG_eng) << ", ";
    }
    std::cout << "end\n\n";

    std::cout << "mt19937: ";
    for (int i = 1; i <= nTrials; ++i) {
        std::cout << dist(mt_eng) << ", ";
    }
    std::cout << "end\n\n";

    std::cout << "mt19937_64: ";
    for (int i = 1; i <= nTrials; ++i) {
        std::cout << dist(mt64_eng) << ", ";
    }
    std::cout << "end\n\n";

    // Part b

    std::chi_squared_distribution<double> chi2_dist(0.5);
    std::normal_distribution<double> normal_dist(A, B);
    std::bernoulli_distribution ber_dist(0.5);
    std::cauchy_distribution<double> cauchy_dist(A, B);

    std::cout << "chi2: ";
    for (int i = 1; i <= nTrials; ++i) {
        std::cout << chi2_dist(mt64_eng) << ", ";
    }
    std::cout << "end\n\n";

    std::cout << "normal: ";
    for (int i = 1; i <= nTrials; ++i) {
        std::cout << normal_dist(mt64_eng) << ", ";
    }
    std::cout << "end\n\n";

    std::cout << "bernoulli: ";
    for (int i = 1; i <= nTrials; ++i) {
        std::cout << ber_dist(mt64_eng) << ", ";
    }
    std::cout << "end\n\n";

    std::cout << "cauchy: ";
    for (int i = 1; i <= nTrials; ++i) {
        std::cout << cauchy_dist(mt64_eng) << ", ";
    }
    std::cout << "end\n\n";

    // Part c
    // Possible way to wrap the code

    std::vector<double> list = rand<double>(mt_eng, normal_dist);
    for (const auto& elem : list) {
        std::cout << elem << ", ";
    }
}

