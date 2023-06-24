

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
