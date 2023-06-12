#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

class Producer {
private:
    std::queue<int>& dataQueue;
    std::mutex& mutex;
    std::condition_variable& cv;
    bool& isBarberSleeping;

public:
    Producer(std::queue<int>& queue, std::mutex& mtx, std::condition_variable& condVar, bool& sleeping)
        : dataQueue(queue), mutex(mtx), cv(condVar), isBarberSleeping(sleeping) {}

    void produce() {
        int customerNumber = 1;
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(10));

            std::unique_lock<std::mutex> lock(mutex);
            if (dataQueue.size() < 5) {
                dataQueue.push(customerNumber);
                std::cout << "Customer " << customerNumber << " arrived" << std::endl;
                if (isBarberSleeping) {
                    isBarberSleeping = false;
                    cv.notify_all();
                }
                customerNumber++;
            }
            else {
                std::cout << "Customer " << customerNumber << " arrived but the waiting room is full" << std::endl;
                customerNumber++;
            }
        }
    }
};

class Consumer {
private:
    std::queue<int>& dataQueue;
    std::mutex& mutex;
    std::condition_variable& cv;
    bool& isBarberSleeping;

public:
    Consumer(std::queue<int>& queue, std::mutex& mtx, std::condition_variable& condVar, bool& sleeping)
        : dataQueue(queue), mutex(mtx), cv(condVar), isBarberSleeping(sleeping) {}

    void consume() {
        while (true) {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, [this] { return !dataQueue.empty() || !isBarberSleeping; });

            if (!dataQueue.empty()) {
                int customer = dataQueue.front();
                dataQueue.pop();
                lock.unlock();

                std::cout << "Barber is serving customer " << customer << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                std::cout << "Barber finished serving customer " << customer << std::endl;

                // Notify waiting customers
                cv.notify_all();
            }
            else {
                std::cout << "Barber is sleeping" << std::endl;
                isBarberSleeping = true;
                lock.unlock();
            }
        }
    }
};

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

