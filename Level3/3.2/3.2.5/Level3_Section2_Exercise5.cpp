#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

class BarberShop {
private:
    std::queue<int> waitingRoom;
    std::mutex mutex;
    std::condition_variable cv;
    bool isBarberSleeping = true;

public:
    void barber() {
        while (true) {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, [this] { return !waitingRoom.empty() || !isBarberSleeping; });

            if (!waitingRoom.empty()) {
                int customer = waitingRoom.front();
                waitingRoom.pop();
                lock.unlock();

                std::cout << "Barber is serving customer " << customer << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                std::cout << "Barber finished serving customer " << customer << std::endl;
            }
            else {
                std::cout << "Barber is sleeping" << std::endl;
                isBarberSleeping = true;
                lock.unlock();
            }
        }
    }

    void customer() {
        int customerNumber = 1;
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(10));

            std::unique_lock<std::mutex> lock(mutex);
            if (waitingRoom.size() < 5) {
                waitingRoom.push(customerNumber);
                std::cout << "Customer " << customerNumber << " arrived" << std::endl;
                if (isBarberSleeping) {
                    isBarberSleeping = false;
                    cv.notify_one();
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

int main() {
    BarberShop barberShop;
    std::thread barberThread(&BarberShop::barber, &barberShop);
    std::thread customerThread(&BarberShop::customer, &barberShop);

    barberThread.join();
    customerThread.join();

    return 0;
}

