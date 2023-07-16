#include <functional>
#include <future>
#include <iostream>
#include <thread>
#include "HelperFunc.h"


// function categories 
template <typename T>
using FactoryFunction = std::function<T()>;
template <typename T>
using ComputeFunction = std::function<T(const T& t)>;
template <typename T>
using DispatchFunction = std::function<void(T& t)>;

//TMP Processor defintion
template <typename T>
class TmpProcessor {  // No inheritance used

private:
    FactoryFunction<T> _factory;
    ComputeFunction<T> _compute;
    DispatchFunction<T> _dispatch;

public:
    TmpProcessor(const FactoryFunction<T>& factory,
               const ComputeFunction<T>& compute,
               const DispatchFunction<T>& dispatch)
      : _factory(factory), _compute(compute), _dispatch(dispatch) {}

    // The template method pattern
    virtual void algorithm() final {
        T val = _factory();
        T val2 = _compute(val);
        _dispatch(val2);
    }
};

// Custom factory, compute, and dispatch functions
int customFactory() {
    std::cout << "Executing customFactory()" << std::endl;
    return 7;
}

int customCompute(const int& val) {
    std::cout << "Executing customCompute()" << std::endl;
    return val * 3;
}

void customDispatch(int& val) {
    std::cout << "Executing customDispatch(): " << val << std::endl;
}

int main() {
    // Part A:
    // define the processor with functions
    
    TmpProcessor<int> processor(customFactory, customCompute, customDispatch);

    // Run the algorithm
    processor.algorithm();
    
    // Part B:
    // Sequential example
    // Computes in a sequential order 
    ComputeFunction<double> sequential_test = [](double a) {
        auto b = F1(a);
        auto d = F3(a);
        auto f = F4(b, d);
        return std::get<0>(f);
    };

    //This is the asynchronous version 
    ComputeFunction<double> parallel_test = [](double a) {
        std::future<double> b(std::async(F3<double>, std::ref(a)));
        auto d = F3(a);
        auto bOut = b.get();
        auto f = F4(bOut, d);
        return std::get<0>(f);
    };

	//Define the two algorithms
    TmpProcessor<int> processor_parallel(customFactory, parallel_test , customDispatch);
    
    TmpProcessor<int> processor_seq(customFactory, sequential_test , customDispatch);

	//run both the sequential and parallel algorithm
    processor_parallel.algorithm();
    processor_seq.algorithm();
}
