#include <iostream>
#include <boost/signals2.hpp>
#include<boost/optional/optional_io.hpp>

// Define a slot that multiplies two values
double multiply(double x, double y)
{
    return x * y;
}

// Define a template combiner that sums the values
template <typename T>
struct SumCombiner
{
    using result_type = T;

    template <typename InputIterator>
    T operator()(InputIterator first, InputIterator last) const
    {
        T sum = 0;
        while (first != last)
        {
            sum += *first;
            ++first;
        }
        return sum;
    }
};

int main()
{
    //Part A
    // Create a signal with custom combiner
    boost::signals2::signal<double(double, double)> sig1;

    // Connect the slots to the signal
    sig1.connect(multiply);
    sig1.connect(multiply);
    sig1.connect(multiply);

    // Invoke the signal with input values
    boost::optional<double> result1 = sig1(2.5, 3.0);

    //Part C
    std::cout << "Result: " << result1 << std::endl;


    //Part B
    // Create a signal with custom combiner
    boost::signals2::signal<double(double, double), SumCombiner<double>> sig2;

    // Connect the slots to the signal
    sig2.connect([](double x, double y) { return x + y; });
    sig2.connect([](double x, double y) { return x * y; });
    sig2.connect([](double x, double y) { return x - y; });

    // Invoke the signal with input values
    double result2 = sig2(2.5, 3.0);

    std::cout << "Result: " << result2 << std::endl;


    return 0;
}



