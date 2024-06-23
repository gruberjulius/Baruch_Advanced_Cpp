#include <iostream>
#include <thread>
#include "SynchronizedQueue.h"
#include "Producer.cpp"
#include "Consumer.cpp"

int main() {
    //Define a class of Type SynchronizedQueue
 
    SynchronizedQueue<std::string> queue;
    // Create a producer and assign a thread
    Producer p(1, &queue);
    std::thread p1(p);

    // Create consumer and assign a thread
    Consumer c(1, &queue);
    std::thread c1(c);

    //join threads in the end
    p1.join();
    c1.join();

}

