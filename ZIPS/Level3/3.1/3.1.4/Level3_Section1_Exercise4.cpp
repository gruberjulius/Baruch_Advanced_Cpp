#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>

template <typename T>
class SynchronizingQueue {
public:
    void Enqueue(const T& item) {
        std::unique_lock<std::mutex> lock(mutex_);
        queue_.push(item);
        lock.unlock();
        condition_.notify_one();
    }

    T Dequeue() {
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this] { return !queue_.empty(); });
        T item = queue_.front();
        queue_.pop();
        return item;
    }

private:
    std::queue<T> queue_;
    mutable std::mutex mutex_;
    std::condition_variable condition_;
};


SynchronizingQueue<int> queue;

void Producer() {
    for (int i = 1; i <= 10; ++i) {
        queue.Enqueue(i);
        std::cout << "Produced: "  << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Simulate some work
    }
}

void Consumer() {
    for (int i = 1; i <= 10; ++i) {
        int item = queue.Dequeue();
        std::cout << "Consumed: " << item << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));  // Simulate some work
    }
}

int main() {
    std::thread producerThread(Producer);
    std::thread consumerThread(Consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
