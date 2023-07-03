#include <iostream>
#include<tuple>
#include <vector>
#include <unordered_map>
#include<numeric>

//Part A
std::vector<std::pair<int, int>> countFrequency(const std::vector<int>& vec) {
    std::unordered_map<int, int> frequencyMap;

    // Count the frequency of each value
    for (int value : vec) {
        frequencyMap[value]++;
    }

    // Convert the map to a vector of pairs
    std::vector<std::pair<int, int>> frequencyPairs;
    for (const auto& pair : frequencyMap) {
        frequencyPairs.emplace_back(pair.first, pair.second);
    }

    return frequencyPairs;
}

std::tuple<double, double, double, double> compute(std::vector<int> numbers){
    double min = *std::min_element(numbers.begin(), numbers.end());
    double max = *std::max_element(numbers.begin(), numbers.end());
    double sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    double avg = sum/numbers.size();
    return std::make_tuple(min, max,sum, avg);
}




int main() {
    std::vector<int> numbers { 1, 2, 4, 5, 4, 1 };

    std::vector<std::pair<int, int>> frequencyPairs = countFrequency(numbers);
    std::tuple<double, double, double, double> result = compute(numbers);

    // Print the frequency pairs
    for (const auto& pair : frequencyPairs) {
        std::cout << "{" << pair.first << ", " << pair.second << "} ";
    }
    std::cout << std::endl;
    //Part B
    // Print the result tuple
    std::cout << "{" <<  std::get<0>(result) << "  " << std::get<1>(result) <<  "  " << std::get<2>(result) <<  "  " << std::get<3>(result) << "} ";

    //Part C

    std::vector<int> S = {1, 2, -3, 4, 5, 5, 5, 6};

    // Using std::find
    auto it = std::find(S.begin(), S.end(), 5);

    if (it != S.end()) {
        std::cout << "Found first occurrence of 5 at index with find: " << std::distance(S.begin(), it) << std::endl;
    } else {
        std::cout << "5 not found in the container." << std::endl;
    }

    // Using std::bind2nd
    auto it1 = std::find_if(S.begin(), S.end(), std::bind2nd(std::equal_to<int>(), 5));

    if (it1 != S.end()) {
        std::cout << "Found first occurrence of 5 at index with bind2nd: " << std::distance(S.begin(), it1) << std::endl;
    } else {
        std::cout << "5 not found in the container." << std::endl;
    }

    // Using std::bind
    auto it2 = std::find_if(S.begin(), S.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, 5));

    if (it2 != S.end()) {
        std::cout << "Found first occurrence of 5 at index with bind : " << std::distance(S.begin(), it2) << std::endl;
    } else {
        std::cout << "5 not found in the container." << std::endl;
    }

    // Using lambda expression
    auto it3 = std::find_if(S.begin(), S.end(), [](int num) { return num == 5; });

    if (it3 != S.end()) {
        std::cout << "Found first occurrence of 5 at index with lambda: " << std::distance(S.begin(), it3) << std::endl;
    } else {
        std::cout << "5 not found in the container." << std::endl;
    }

}
