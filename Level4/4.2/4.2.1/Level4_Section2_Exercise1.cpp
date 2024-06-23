#include <tuple>
#include <vector>
#include <algorithm>
#include <iostream>

using Range = std::tuple<std::size_t, std::size_t>;
using Result = std::tuple<Range, bool>;

template <typename T>
Result find_sequential_greater(const std::vector<T>& v, T x)
{
    for (std::size_t j = 0; j < v.size() - 1; ++j)
    {
        if (v[j] <= x && v[j + 1] > x)
        {
            return { {j, j + 1}, true };
        }
    }
    return { {999, 999}, false };
}

template <typename T>
Result find_sequential_greater_find_if(const std::vector<T>& v, T x)
{
    int idx = 0;
    auto inbetween = [x, &v, &idx](T data) {
        if (v[idx] <= x && v[idx + 1] > x) {
            ++idx;
            return true;
        }
        ++idx;
        return false;
    };
    auto res = std::find_if(v.begin(), v.end(), inbetween);
    if (res != v.end()) {
        int resIdx = std::distance(v.begin(), res);
        return { {resIdx, resIdx + 1}, true };
    }
    return { {999, 999}, false };
}

template <typename T>
Result find_matching_index(const std::vector<T>& v, T x)
{
    auto res = std::find(v.begin(), v.end(), x);
    if (res != v.end()) {
        int resIdx = std::distance(v.begin(), res);
        return { {resIdx, resIdx}, true };
    }
    return { {999, 999}, false };
}

template <typename T>
Result find_sequential_greater_lower_bound(const std::vector<T>& v, T x)
{
    auto res = std::lower_bound(v.begin(), v.end(), x);
    if (res != v.end()) {
        int resIdx = std::distance(v.begin(), res);
        return { {resIdx - 1, resIdx}, true };
    }
    return { {999, 999}, false };
}

template <typename T>
Result find_sequential_greater_upper_bound(const std::vector<T>& v, T x)
{
    auto res = std::upper_bound(v.begin(), v.end(), x);
    if (res != v.end()) {
        int resIdx = std::distance(v.begin(), res);
        return { {resIdx - 1, resIdx}, true };
    }
    return { {999, 999}, false };
}

template <typename T>
Result find_sequential_greater_equal_range(const std::vector<T>& v, T x)
{
    auto res = std::lower_bound(v.begin(), v.end(), x);
    if (res != v.end()) {
        int resIdx = std::distance(v.begin(), res);
        return { {resIdx - 1, resIdx}, true };
    }
    return { {999, 999}, false };
}

void printResult(const Result& res)
{
    if (std::get<1>(res)) {
        auto indexes = std::get<0>(res);
        std::cout << "found element at index number: " << std::get<0>(indexes) << std::endl;
    }
    else {
        std::cout << "nothing found" << std::endl;
    }
}



int main(){

    // Part A, B, C

    // checking that all three algorithms give the same

    std::vector<int> vec{ 1,2,3,4,6,7 };
    int x{ 5 };

    std::cout << "standard: ";
    printResult(find_sequential_greater(vec, x));

    std::cout << "find_if: ";
    printResult(find_sequential_greater_find_if(vec, x));

    std::cout << "lower_bound: ";
    printResult(find_sequential_greater_lower_bound(vec, x));

    std::cout << "upper_bound: ";
    printResult(find_sequential_greater_upper_bound(vec, x));

    std::cout << "equal range: ";
    printResult(find_sequential_greater_equal_range(vec, x));

    // all algos work as expected

    // Part d

    auto iseven = [](int val) {
        return val % 2 == 0;
    };

    std::vector<int> vec2 = { 2,4,6,8,9,10 };

    auto res = std::find_if_not(vec2.begin(), vec2.end(), iseven);

    if (res != vec2.end()) {
        std::cout << "not even value: " << *res << std::endl;
    }

    return 0;
}

