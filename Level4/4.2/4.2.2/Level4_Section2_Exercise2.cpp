
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>

using Vector = std::vector<double>;

int main() {

    // Part A, B

    std::chrono::steady_clock::time_point start, end;
    bool isSorted = true;

    Vector vec = { 1.0, 2.0, 3.0, -4.0, 10.0 }; // Not ordered

    // is_sorted_until standard
    start = std::chrono::steady_clock::now();
    isSorted = std::is_sorted_until(vec.begin(), vec.end()) == vec.end();
    end = std::chrono::steady_clock::now();
    std::cout << "is_sorted_until standard: is sorted? " << std::boolalpha << isSorted
              << ", took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << std::endl;

    // is_sorted_until with custom compare operator (descending order)
    start = std::chrono::steady_clock::now();
    isSorted = std::is_sorted_until(vec.begin(), vec.end(), [](double a, double b) { return a > b; }) == vec.end();
    end = std::chrono::steady_clock::now();
    std::cout << "is_sorted_until descending order: is sorted? " << std::boolalpha << isSorted
              << ", took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << std::endl;

    // is_sorted standard function from STL
    start = std::chrono::steady_clock::now();
    isSorted = std::is_sorted(vec.begin(), vec.end());
    end = std::chrono::steady_clock::now();
    std::cout << "is_sorted standard: is sorted? " << std::boolalpha << isSorted
              << ", took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << std::endl;

    // is_sorted with custom comparator (descending order)
    start = std::chrono::steady_clock::now();
    isSorted = std::is_sorted(vec.begin(), vec.end(), [](double a, double b) { return a > b; });
    end = std::chrono::steady_clock::now();
    std::cout << "is_sorted descending order: is sorted? " << std::boolalpha << isSorted
              << ", took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << std::endl;


    // fastest is the is_sorted
    // slowest the is_sorted with custom operator

    return 0;
}

