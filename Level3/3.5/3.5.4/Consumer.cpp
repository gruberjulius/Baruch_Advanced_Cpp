#include <iostream>
#include <string>
#include "SynchronizedQueue.h"

//class that gets consumes from the queue
class Consumer {
private:
    int m_id;                                 // The id of the consumer
    SynchronizedQueue<std::string>* m_queue;  // The queue to use
public:
    // Constructor with id and the queue to use
    Consumer(int id, SynchronizedQueue<std::string>* queue) {
        m_id = id;
        m_queue = queue;
    }
    // The thread function reads data from the queue
    void operator()() {
        while (true) {
            // Get the data from the queue and print it
            std::cout << "Consumer " << std::to_string(m_id).c_str() << " consumed: ("
                << m_queue->Dequeue().c_str() << ")" << std::endl;
            // Make sure we can be interrupted
            std::this_thread::yield();
        }
    }
};
