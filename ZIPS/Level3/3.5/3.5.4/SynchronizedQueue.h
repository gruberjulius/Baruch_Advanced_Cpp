#include <mutex>
#include <queue>

template <typename T>
class SynchronizedQueue {
private:
    std::priority_queue<T> m_queue;  // STL Priority Queue to store information
    std::mutex m_mutex;              // The mutex (used for synchronization), globally
    std::condition_variable m_cond;  // The waiting condition
public:

    //add data to the queue and notify others
    void Enqueue(const T& data) {
        std::unique_lock<std::mutex> lock(m_mutex); //lock queue 
        m_queue.push(data); // add data
        m_cond.notify_one(); // notifies the elements are ready
    };  // Lock is released here

    //lock the queue, get data from itm, destroy it  and return the result
    T Dequeue() {
        std::unique_lock<std::mutex> lock(m_mutex); // locking mechanism
        while (m_queue.size() == 0) m_cond.wait(lock);
        // Retrieve the data from the queue
        T result = m_queue.top(); //gets the top element to return 
        m_queue.pop();  // deletes element and remove it
        return result;
    };  // Lock is released here
};
