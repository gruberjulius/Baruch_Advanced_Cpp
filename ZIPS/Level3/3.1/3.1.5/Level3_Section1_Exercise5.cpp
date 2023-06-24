#include <atomic>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>

int main() {

	// Part a

	std::atomic<long long> atomicLongLong;
	std::atomic<bool> atomicBool;
	std::atomic<int> atomicInt;

	// Part b

	std::cout << "atomic long long is lock free: " << std::boolalpha << std::atomic_is_lock_free(&atomicLongLong) << std::endl;
	std::cout << "atomic bool is lock free: " << std::boolalpha << std::atomic_is_lock_free(&atomicBool) << std::endl;
	std::cout << "atomic int is lock free: " << std::boolalpha << std::atomic_is_lock_free(&atomicInt) << std::endl;
	//=> all lock free

	// Part c
	// atomically replacing one atomic by another
	atomicLongLong.store(atomicBool);

	// Part d
	atomicInt = 3;
	std::cout << "atomic int is: " << atomicInt.load() << std::endl;
    return 0;
}
