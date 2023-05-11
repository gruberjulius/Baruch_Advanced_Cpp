#include <iostream>
#include <span>

template<typename T, std::size_t length>
void print(std::span<T, length> span) {
    for(auto i : span) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    print(std::span{data});
}
