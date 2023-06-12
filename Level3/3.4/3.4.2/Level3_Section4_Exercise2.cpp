#include <iostream>
#include <future>
#include <chrono>
#include <condition_variable>

int calculateValue() {
    // Simulate some time-consuming calculation
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42;
}

std::mutex mutex;
std::condition_variable cv;
bool finished = false;

void infiniteLoop()
{
    // Simulate an infinite loop
    while (true)
    {
        std::cout << "Running infinite loop..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    // Notify when the loop finishes (which never happens in this example)
    std::lock_guard<std::mutex> lock(mutex);
    finished = true;
    cv.notify_all();
}

int main() {
    // Default shared future
    std::shared_future<int> defaultSharedFuture;

    // Create a future and then convert it to a shared future
    std::future<int> future1 = std::async(std::launch::async, calculateValue);
    std::shared_future<int> sharedFuture1(std::move(future1));

    // Transfer shared state from a normal future to a shared future
    std::future<int> future2 = std::async(std::launch::async, calculateValue);
    std::shared_future<int> sharedFuture2 = future2.share();

    // Transfer shared state from a shared future to another shared future
    std::shared_future<int> sharedFuture3(sharedFuture2);

    // Get the result from shared futures
    int result1 = sharedFuture1.get();
    int result2 = sharedFuture2.get();
    int result3 = sharedFuture3.get();

    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;
    std::cout << "Result 3: " << result3 << std::endl;

    //Part b
    //checking that the member functions also work

    sharedFuture1.valid();
    sharedFuture1.wait();
    sharedFuture1.get();

    //Part c
    //Calling a shared future for a second time

    int result4 = sharedFuture1.get();
    //no error message
    
    //Part d

    // Create a shared future for the infinite loop
    std::shared_future<void> sharedFuture;

    {
        // Start the infinite loop in a separate thread
        std::future<void> future = std::async(std::launch::async, infiniteLoop);

        // Assign the shared future to the future
        sharedFuture = future.share();
    }

    // Wait for the loop to finish or timeout
    {
        std::unique_lock<std::mutex> lock(mutex);
        if (cv.wait_for(lock, std::chrono::seconds(5), [&]{ return finished; }))
        {
            std::cout << "Infinite loop finished." << std::endl;
        }
        else
        {
            std::cout << "Timeout reached. Infinite loop is still running." << std::endl;
        }
    }

    // Wait indefinitely to keep the program running
    std::this_thread::sleep_for(std::chrono::seconds(10));

    return 0;

    return 0;
}

