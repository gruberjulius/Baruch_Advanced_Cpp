#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;

    for (int num : {10, 5, 20, 30, 25, 7, 40}) { pq.push(num); };

    std::cout << "Priority Queue:";
    while (!pq.empty()) {
        std::cout << " " << pq.top();
        pq.pop();
    }
    std::cout << std::endl;



    std::priority_queue<int, std::vector<int>, std::greater<int>> pq1;

    for (int num : {10, 5, 20, 30, 25, 7, 40}) { pq1.push(num); };
    
    std::cout << "Priority Queue (with std::greater<int>):";
    while (!pq1.empty()) {
        std::cout << " " << pq1.top();
        pq1.pop();
    }
    std::cout << std::endl;

    auto cmp = [](int left, int right) -> bool { return (left > right); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> pq2(cmp);

    pq2.push(10);
    pq2.push(5);
    pq2.push(20);
    pq2.push(30);
    pq2.push(25);
    pq2.push(7);
    pq2.push(40);

    std::cout << "Priority Queue (with lambda comparator):";
    while (!pq2.empty()) {
        std::cout << " " << pq2.top();
        pq2.pop();
    }
    std::cout << std::endl;
    return 0;

}


