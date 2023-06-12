#include <iostream>
#include <thread>
#include <functional>

class ActiveObject {
private:
    std::thread thread_;

public:
    explicit ActiveObject(std::function<void()> threadFunction) {
        thread_ = std::thread(threadFunction);
    }

    explicit ActiveObject(std::thread src) : thread_(std::move(src)) {
        std::cout << "Active thread object constructor called" << std::endl;
    }

    ~ActiveObject() {
        if (thread_.joinable()) {
            thread_.join();
        }
    }
};

void threadFunction() {
    std::cout << "Thread is executing." << std::endl;
}

int main() {
    //Part A, B,C 
    auto lambda = []() { std::cout << "Currently threading" << std::endl; };

    std::thread t(threadFunction);
    std::thread t1(lambda);
    std::thread t2;

    ActiveObject obj(std::move(t));
    ActiveObject obj1(std::move(t1));
    ActiveObject obj2(std::move(t2));

    return 0;
    //Works as expected
}

