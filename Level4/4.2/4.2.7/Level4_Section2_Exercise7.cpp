#include <iostream>
#include <vector>
#include <algorithm>


// Recursive function to compute the power set
void computePowerSet(const std::vector<int>& S, std::vector<std::vector<int>>& powerSet, std::vector<int>& subset, int index) {
    // Add the current subset to the power set
    powerSet.push_back(subset);

    // Generate subsets for remaining elements
    for (int i = index; i < S.size(); ++i) {
        // Include the current element in the subset
        subset.push_back(S[i]);

        // Recursively generate subsets for remaining elements
        computePowerSet(S, powerSet, subset, i + 1);

        // Exclude the current element from the subset (backtracking)
        subset.pop_back();
    }
}

// Function to compute the power set of S
std::vector<std::vector<int>> getPowerSet(const std::vector<int>& S) {
    std::vector<std::vector<int>> powerSet;
    std::vector<int> subset;

    // Compute the power set recursively
    computePowerSet(S, powerSet, subset, 0);

    return powerSet;
}


// Function to remove an element from each subset in the power set
void removeElementFromPowerSet(std::vector<std::vector<int>>& powerSet, std::vector<int> elementToRemove) {
    for (auto& subset : powerSet) {
        subset.erase(std::remove(subset.begin(), subset.end(), elementToRemove), subset.end());
    }
}

int main() {
    //Part A
    std::vector<int> S = {1, -1, 7, 8, 9, 10};
    std::vector<int> S_reversed;

    // Reverse S and copy to S_reversed
    std::reverse_copy(S.begin(), S.end(), std::back_inserter(S_reversed));

    // Print the original S
    std::cout << "Original S: ";
    for (const auto& element : S) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Print the reversed S
    std::cout << "Reversed S: ";
    for (const auto& element : S_reversed) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    //Part B
    // Find the iterator pointing to the element with value 8
    auto rotationPoint = std::find(S.begin(), S.end(), 8);

    // Rotate the container so that the rotation point becomes the beginning
    std::rotate(S.begin(), rotationPoint, S.end());

    // Print the rotated S
    std::cout << "Rotated S: ";
    for (const auto& element : S) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    //Part C
    // Compute the power set of S
    std::vector<std::vector<int>> powerSet = getPowerSet(S);

    // Print the power set
    for (const auto& subset : powerSet) {
        std::cout << "{ ";
        for (const auto& element : subset) {
            std::cout << element << " ";
        }
        std::cout << "}" << std::endl;
    }

    //Part D

//    removeElementFromPowerSet(powerSet, {8,9,10});
    powerSet.insert(powerSet.begin(), {8,9,10});

    powerSet.remove({8,9,10});

    // Print the power set
    for (const auto& subset : powerSet) {
        std::cout << "{ ";
        for (const auto& element : subset) {
            std::cout << element << " ";
        }
        std::cout << "}" << std::endl;
    }


    return 0;
}

