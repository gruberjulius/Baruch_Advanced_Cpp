#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include "Producer.cpp"
#include "Consumer.cpp"

int main() {
    std::queue<int> dataQueue;
    std::mutex mutex;
    std::condition_variable cv;
    bool isBarberSleeping = true;

    Producer producer(dataQueue, mutex, cv, isBarberSleeping);
    Consumer consumer(dataQueue, mutex, cv, isBarberSleeping);

    std::thread producerThread(&Producer::produce, &producer);
    std::thread consumerThread(&Consumer::consume, &consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}

