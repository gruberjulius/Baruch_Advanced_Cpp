#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>  // std::this_thread::sleep_for
#include <vector>

std::mutex m_mutex;

struct X {
  double val;

  X() : val(0.0) {}
  void operator()() { std::cout << "An X " << val << std::endl; }
};

// C++11
template <typename T>
using GenericPointerType = std::shared_ptr<T>;
using PointerType = GenericPointerType<X>;



void modify(PointerType& p, double newVal){
    //Part a
    // get random number:
    // Generate a uniform random delay using C++ random library
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double delay = dis(gen);

    // Introduce latency by sleeping for the generated amount of time
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(delay * 1000)));

    // Update the state
    p->val = newVal;
}

int main(){
    PointerType x = std::make_shared<X>(); // Create an instance of PointerType
    x->val = 0.0; // Set initial value
    const int numThreads = 100;
    std::thread threads[numThreads];

    // Function to modify the shared pointer's value
    auto modifyValue = [&](double newVal) {
        modify(x, newVal);
    };

    // Create and start all the threads
    for (auto i = 0; i < numThreads; ++i) {
        double newValue = i + 1; // Set the new value for each thread
        threads[i] = std::thread(modifyValue, newValue);
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }
    
    // Print the final value of the shared pointer
    std::cout << "Final value: " << x->val << std::endl;
    
    //Part c
    //When running the program multiple times, the output may vary due 
    //to the non-deterministic nature of thread scheduling and the race
    //conditions introduced by the random delays in the Modify function.
    //Furthermore, the assigned value is different in most of the runs becausse of the included waiting time in the function.
    return 0;

}
