#include <iostream>
#include <chrono>
#include <numeric>
#include <vector>

int main() {
    const int SIZE = 100000000; // Size of the numeric array

    // Create a huge numeric array
    std::vector<int> array(SIZE);
    for (int i = 0; i < SIZE; i++) {
        array[i] = i + 1;
    }

    // Sum the elements using std::accumulate()
    auto startTime = std::chrono::high_resolution_clock::now();
    int sum = std::accumulate(array.begin(), array.end(), 0);
    auto endTime = std::chrono::high_resolution_clock::now();

    // Calculate the processing time
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Print the result and processing time
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Processing time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}

