#include <iostream>
#include <boost/numeric/ublas/vector.hpp>
#include <algorithm>

namespace ublas = boost::numeric::ublas;

using Vector = ublas::vector<double>;
using Range = std::tuple<std::size_t, std::size_t>;
using Result = std::tuple<Range, bool>;

std::size_t find_index(const Vector& v, double value)
{
    auto it = std::find(v.begin(), v.end(), value);
    if (it != v.end())
    {
        return std::distance(v.begin(), it);
    }
    return std::numeric_limits<std::size_t>::max();
}

Result find_sequential_greater(const Vector& v, double x)
{
    auto it = std::find_if(v.begin(), v.end() - 1,
        [x](double a) { return a <= x && *(std::next(&a)) > x; });

    if (it != v.end() - 1)
    {
        std::size_t j = std::distance(v.begin(), it);
        return std::make_tuple(std::make_tuple(j, j + 1), true);
    }

    return std::make_tuple(std::make_tuple(42, 42), false);
}

Result find_sequential_greater_2(const Vector& v, double x)
{
    auto lower = std::lower_bound(v.begin(), v.end(), x);
    auto upper = std::upper_bound(v.begin(), v.end(), x);

    if (lower != upper && upper != v.end())
    {
        std::size_t j = std::distance(v.begin(), lower);
        return std::make_tuple(std::make_tuple(j, j + 1), true);
    }

    return std::make_tuple(std::make_tuple(999, 999), false);
}

std::size_t find_index_3(const Vector& v, double value)
{
    auto it = std::lower_bound(v.begin(), v.end(), value);
    if (it != v.end() && *it == value)
    {
        return std::distance(v.begin(), it);
    }
    return std::numeric_limits<std::size_t>::max();
}

Result find_sequential_greater_3(const Vector& v, double x)
{
    auto range = std::equal_range(v.begin(), v.end(), x);

    if (range.first != range.second && range.second != v.end())
    {
        std::size_t j = std::distance(v.begin(), range.first);
        return std::make_tuple(std::make_tuple(j, j + 1), true);
    }

    return std::make_tuple(std::make_tuple(999, 999), false);
}

bool is_negative(double value)
{
    return value < 0;
}


int main()
{

    //Part A

    Vector v(5);
    v(0) = 1.0;
    v(1) = 2.0;
    v(2) = 3.0;
    v(3) = 4.0;
    v(4) = 5.0;

    double x = 2.5;

    Result result = find_sequential_greater(v, x);

    if (std::get<1>(result))
    {
        Range range = std::get<0>(result);
        std::cout << "Found at range [" << std::get<0>(range) << ", " << std::get<1>(range) << "]\n";
    }
    else
    {
        std::cout << "Not found\n";
    }

    std::size_t index = find_index(v, 3.0);
    if (index != std::numeric_limits<std::size_t>::max())
    {
        std::cout << "Value found at index: " << index << std::endl;
    }
    else
    {
        std::cout << "Value not found\n";
    }

    //Part B
    
    Result result2 = find_sequential_greater_2(v, x);

    if (std::get<1>(result))
    {
        Range range = std::get<0>(result2);
        std::cout << "Found at range [" << std::get<0>(range) << ", " << std::get<1>(range) << "] with lower and upper bound \n";
    }
    else
    {
        std::cout << "Not found\n";
    }

    std::size_t index_2 = find_index(v, 3.0);
    if (index != std::numeric_limits<std::size_t>::max())
    {
        std::cout << "Value found at index with upper and lower bound: " << index << std::endl;
    }
    else
    {
        std::cout << "Value not found\n";
    }

    //Part C

    Result result3 = find_sequential_greater_3(v, x);

    if (std::get<1>(result))
    {
        Range range = std::get<0>(result2);
        std::cout << "Found at range [" << std::get<0>(range) << ", " << std::get<1>(range) << "] with equal range \n";
    }
    else
    {
        std::cout << "Not found\n";
    }

    std::size_t index_3 = find_index_3(v, 3.0);
    if (index_3 != std::numeric_limits<std::size_t>::max())
    {
        std::cout << "Value found at index with equal range: " << index << std::endl;
    }
    else
    {
        std::cout << "Value not found\n";
    }

    //Part D

    auto it = std::find_if_not(v.begin(), v.end(), is_negative);

    if (it != v.end())
    {
        std::cout << "First non-negative value found: " << *it << std::endl;
    }
    else
    {
        std::cout << "No non-negative values found" << std::endl;
    }

    return 0;
}

