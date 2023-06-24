#include <iostream>
#include <future>
#include <thread>

void threadFunction(std::future<double>& future) {
    double value = future.get();
    std::cout << "Thread Function: Received value from the future: " << value << std::endl;
}

int main() {
    //Part a
    std::promise<int> defaultPromise;
    std::promise<int> emptyPromise;
    std::future<int> future = emptyPromise.get_future();
    std::promise<int> destinationPromise(std::move(defaultPromise));
    
    //Part b
    std::promise<double> doublePromise;
    std::future<double> future1 = doublePromise.get_future();
    double value = 3.14159;
    doublePromise.set_value(value);
    double result = future1.get();
    std::cout << "Value from the future: " << result << std::endl;
    
    //Part c & d
    std::promise<double> doublePromise2;
    std::future<double> future2 = doublePromise2.get_future();
    std::thread threadObj(threadFunction, std::ref(future2));
    doublePromise2.set_value(value); // Update the promise to doublePromise2
    threadObj.join();



    return 0;
}

