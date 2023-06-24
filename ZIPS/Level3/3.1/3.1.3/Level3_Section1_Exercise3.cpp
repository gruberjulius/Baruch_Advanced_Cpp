#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>
#include <system_error>

//Part a

//mutex lock for multiple threads
std::mutex mutex1;
int counterLockGuard{0};

int attempts1 = 0;

// Function using std::mutex lock_guard for synchronization
void synchronizedFunction(std::string query) {
    std::lock_guard<std::mutex> lock(mutex1);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Query: " << query << std::endl;
	counterLockGuard++;
    attempts1++;
}

//Part c 

std::mutex mutex2;

// Function using unique lock for synchronization with other locks
void tryLockFunction(std::string query) {
	//Using defer lock:
	std::unique_lock<std::mutex> lock(mutex2, std::defer_lock);

    try{
        while(true){
            if(lock.try_lock()){
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "Query: " << query << std::endl;
                lock.unlock();
                return;
            }
        }
    }

    catch(const std::system_error& ec){
        //exception that there is no associated mutex
        if(ec.code()== std::errc::operation_not_permitted) {std::cout << "no associated mutex" << std::endl;};

        if(ec.code()== std::errc::resource_deadlock_would_occur) {std::cout << "mutex is already locked" << std::endl;};
    };
};


void functionUniqueLock(std::string query) {
	// warpping mutex in the unique_lock wrapper
	// adding defer_lock to not lock it (no ownership)
	std::unique_lock<std::mutex> lock(mutex2, std::defer_lock);
	// trying to lock it
	try {
		// continuous trying
		while (true) {
			// if locking is successful, launch function
			if (lock.try_lock()) {
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << "query: " << query << std::endl;
				// Part e
				lock.unlock();
				return;
			}
		}
	}
	// if errors in the mutex
	catch (const std::system_error& ec) {
		// exception that there is no associated mutex
		if (ec.code() == std::errc::operation_not_permitted) { std::cout << "no associated mutex" << std::endl; };
		// ecption that the mutex is already locked
		if (ec.code() == std::errc::resource_deadlock_would_occur) { std::cout << "mutex is already locked" << std::endl; };
	};
};


std::mutex mutex;

// Function using std::mutex try_lock() for synchronization with attempt count
int attempts2 = 0;
void tryLockFunction2(std::string query) {
    while (true) {
        if (mutex.try_lock()) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Query: " << query << std::endl;
            mutex.unlock();
            return;
        } else {
            ++attempts2;
        }
    }
}

// Function using std::mutex try_lock() for synchronization with attempt count
int attempts3 = 0;
void tryLockFunction3(std::string query) {
    while (true) {
        if (mutex.try_lock()) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Query: " << query << std::endl;
            mutex.unlock();
            return;
        } else {
            ++attempts3;
        }
    }
}

// Function causing a deadlock
void deadlockFunction(std::string query) {
    mutex.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Query: " << query << std::endl;
    // need to implement an unlock, otherwise this causes a deadlock function and the code can not continue
}

int main() {
    // Part a
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

    std::thread t1(synchronizedFunction, "One");
    std::thread t2(synchronizedFunction, "Two");
    std::thread t3(synchronizedFunction, "Three");
    t1.join();
    t2.join();
    t3.join();

    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Threads with lock took " << duration.count() << "s" << std::endl;

    // Part b
    start = std::chrono::system_clock::now();

    std::thread t4(tryLockFunction, "One");
    std::thread t5(tryLockFunction2, "Two");
    std::thread t6(tryLockFunction3, "Three");
    t4.join();
    t5.join();
    t6.join();

    std::cout << "Attempts t4: " << attempts1 << std::endl;
    std::cout << "Attempts t5: " << attempts2 << std::endl;
    std::cout << "Attempts t6: " << attempts3 << std::endl;

	duration =  std::chrono::system_clock::now() - start;
	std::cout << "threads with try_lock took " << duration.count() << "s" << std::endl;
	//=> we notice that threads with try_lock are a lot quicker even if a lot of attempts are made

	// PART c: code is excluded as otherwise a deadlock would arise

	//std::thread t7{ functionDeadLock, "one" };
	//std::thread t8{ functionDeadLock, "two" };

    return 0;
}
