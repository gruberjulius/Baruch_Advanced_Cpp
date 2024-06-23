
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
