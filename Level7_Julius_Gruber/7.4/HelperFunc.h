#pragma once
#include <iostream>
#include <thread>
#include <future>
#include <random>


//time consuming function
template <typename T>
T F1(T& input) {
    std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
    //generate random waiting times for the thread
	std::default_random_engine dre(412);
    std::uniform_int_distribution<int> delay(0, 1000);
    int output = delay(dre);

    std::cout << "Finished F1 \n";
    return output;
}

//quick function
template <typename T>
T F2(T& input) {
    std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
    std::cout << "Finished F2 \n";
    input += input;
    return input;
}

// this is a time intensive function as well
template <typename T>
T F3(T& input) {
    std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
   	long long sum = 2;
	for(int i = 0; i < n; i++){
		sum *=i;
	}	
	std::cout << "Finished F3 \n";
    return input;
}

//define tuple of two tasks
template <typename T>
std::tuple<T, T> F4(T& input1, T& input2) {
    std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
    std::cout << "Finished F4 \n";
    auto output = std::make_tuple<T&, T&>(input1, input2);
    return output;
}
