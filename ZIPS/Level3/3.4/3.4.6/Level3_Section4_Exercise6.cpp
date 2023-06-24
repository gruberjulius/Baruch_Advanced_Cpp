
#include <thread>
#include <chrono>
#include <iostream>
#include <future>

// list of all functions in the program
int F1(int a) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return ++a;
};
int F2(int a) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return ++a;
};
int F3(int c) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return ++c;
};
int F4(int b, int d) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return b + d;
};

int main(){
    //Part a
    std::chrono::steady_clock::time_point start, end;

    start =  std::chrono::steady_clock::now();
    int a = 1;
    int res{F4(F1(a), F3(F2(a)))};
    end =  std::chrono::steady_clock::now();
    std::cout << "single threaded lasts: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
    //write time here

    //Part b

	// async and future
	start = std::chrono::steady_clock::now();
	// async on the left branch of the graph
	std::future<int> b_async{ std::async(F1, a) };
	int res2{ F4(b_async.get(), F3(F2(a)))};
	end = std::chrono::steady_clock::now();
	std::cout << "async and future lasts: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
    //write time here

    //Part c

	// promises
	std::promise<int> p;
	std::future<int> b_promise{ p.get_future() };

	start = std::chrono::steady_clock::now();

	// thread with the promise for the left branch of the graph 
	std::thread f1{ F1_promise, a, std::move(p) };
	int c_promise{ F3(F2(a)) };
	f1.join();
	int res3{ F4(b_promise.get(), c_promise) };
	end = std::chrono::steady_clock::now();
	std::cout << "promise lasts: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	// => 3037 miliseconds: we still have the second less but not faster than async

    //Part d
    //threads with packaged taks
    //



}
