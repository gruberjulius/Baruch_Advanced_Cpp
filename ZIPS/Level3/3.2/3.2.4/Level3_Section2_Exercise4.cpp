
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <atomic>


//Part a, given necessary code

// Types and data needed
std::string data;// Shared data between master and worker
std::mutex m; // Ensures no race condition
// Synchronisation between master and worker
std::condition_variable cv;
// Initial state of worker and master
std::atomic<bool> workerReady = false;
std::atomic<bool> masterReady = false;

//Part b
//Worker Thread from Lecture slide slightly modified
void WorkerThread(){
    std::cout << "Worker is called...\n";
    // False state: wait until master sends data
    std::unique_lock<std::mutex> myLock(m);

    cv.wait(myLock, [] { return workerReady.load(); }); // Now in True state
    //Update the data file
    std::cout << "Worker is processing data\n"; 
    //add information to data file
    data += "addition from worker";
    // Notify master
    masterReady = true;
    // Postprocess
    myLock.unlock(); 
    cv.notify_one();
    masterReady = true;
    std::cout << "Worker is exited...\n";
}

//Part d

std::atomic_flag workerReadyFlag =  ATOMIC_FLAG_INIT;
std::atomic_flag masterReadyFlag = ATOMIC_FLAG_INIT;

void workerThreadFlag(){
    std::unique_lock<std::mutex> workerLock(m);

    cv.wait(workerLock, [](){return workerReadyFlag.test_and_set();});

    data += "worker has worked";

    masterReadyFlag.test_and_set();
    workerLock.unlock();
    cv.notify_one();
}



int main(){
    
    //Part c
    // Part c : Master Code from lecture slides 
	std::cout << "Master is called...\n";
    std::thread worker(WorkerThread);
    data = "Master Data";

	// Transition into True state, when the lock is available
	{ 
		std::lock_guard<std::mutex> myLock(m);
        workerReady = true;
        //workerReady.test_and_set();
    }

	std::cout<< "Master has notified worker, wait for response...\n";
    cv.notify_one();
    {
        std::unique_lock<std::mutex> myLock(m);         
        cv.wait(myLock, [] { return masterReady.load(); });
    }

	std::cout << "Master back again...\n";
    worker.join();
    std::cout << data << std::endl;

    //Part d
    std::thread worker2(workerThreadFlag);

    {
        std::unique_lock<std::mutex> masterLock(m);

        workerReadyFlag.test_and_set();
        
        cv.wait(masterLock, []{return masterReadyFlag.test_and_set();});
    }

    worker2.join();

    std::cout << data << std::endl;


}
