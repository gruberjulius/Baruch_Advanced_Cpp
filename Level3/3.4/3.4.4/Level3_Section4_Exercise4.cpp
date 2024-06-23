#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <future>
#include <queue>
#include <array>



// Thread function
double compute(double x, double y)
{
   // Wait a while
    std::default_random_engine dre(42);
    std::uniform_int_distribution<int> delay(0, 1000);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay(dre)));

    return std::cos(x) * std::exp(y);
}


int main(){

    //Part a: given Code

    double x = 0.0; 
    double y = 2.71;
    // A. 'Direct' tasks
    std::future<double> fut = std::async(compute, x, y);

    // Get the shared data
    double result = fut.get();
    std::cout << "Result: " << result << '\n';

    //Part B: Use Package Task and delayed execution
    std::packaged_task<double(double, double)> task{compute};

    // Get the associated future
    std::future<double> f{task.get_future()};

    // Create a thread to execute the task
    std::thread threadObj(std::move(task), x, y);

    // Delay execution for some time
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Get the result from the future
    double delayedResult = f.get();
    std::cout << "Delayed Result: " << delayedResult << '\n';

    // Join the thread
    threadObj.join();

    //Part C: create a queue/deque of packaged tasks

    // Create a queue of packaged tasks
    std::queue<std::packaged_task<double(double, double)>> taskQueue;

    // Part C: Use a packaged tasks, dequeue each task and execute it
    std::queue<std::packaged_task<double(double x, double y)>> packaged_task_queue;
    int numTasks = 10; 
    
    // Queueing 
    for (int i = 0; i<numTasks; i++) {
      std::packaged_task<double(double x, double y)> t(compute);
      packaged_task_queue.push(std::move(t)); // this is adding the package to the queue

    }

    // Dequeuing 
    double taskTmp = 0.0; 
    for (int i = 0; i < numTasks; i++) {
        // making unique tasks 
        taskTmp = taskTmp + i; 
        auto resultQueue = packaged_task_queue.front().get_future(); // creating future for the first task on queue 
        packaged_task_queue.front()(taskTmp, y); // running task 
        
        // Outputting result
        std::cout << "resultQueue is: " << resultQueue.get() << std::endl; 
        
        packaged_task_queue.pop();  // taking task off of queue 

    }
    std::cout << "Number of Tasks completed " << taskTmp << std::endl;

    return 0;

}
