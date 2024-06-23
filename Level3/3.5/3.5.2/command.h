#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include<iostream>
#include <functional>


// GIVEN CODE

using FunctionType = std::function<double(double)>;

class Command
{
private:
    long ID; // priority of command
    FunctionType algo;
public:
    Command(const FunctionType& algorithm, long priority)
        : algo(algorithm), ID(priority) {}

    // adding const qualifer to execute directly
    void Execute(double x) const {
        // Introduce delay to simulate a heavy algorithm
        std::this_thread::sleep_for (std::chrono::seconds(1));
        std::cout << algo(x) << '\n';
    }

    int priority() const
    {
        return ID;
    }
};
