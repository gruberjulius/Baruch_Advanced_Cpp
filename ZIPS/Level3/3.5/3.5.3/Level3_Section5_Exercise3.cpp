#include <forward_list>
#include <iostream>
#include <array>

template <typename T>
void forward_list_print(const std::forward_list<T>& list) {
    if (list.empty()) {
        std::cout << "list is empty";
    } else {
        for (const T& elem : list) {
            std::cout << elem << ", ";
        }
    }
    std::cout << std::endl;
}

template <typename T>
std::size_t forward_list_size(const std::forward_list<T>& list) {
    return std::distance(list.begin(), list.end());
}

template <typename T, typename Iterator>
void erase(std::forward_list<T>& list, Iterator pos) {
    list.erase_after(pos);
}

template <typename T, typename Iterator>
void erase(std::forward_list<T>& list, Iterator l, Iterator r) {
    list.erase_after(l, r);
}

int main() {
    std::forward_list<int> l1;
    forward_list_print(l1);

    std::forward_list<int> l2(5, 1);
    forward_list_print(l2);

    std::forward_list<int> l3{1, 2, 3, 4, 5, 6, 7, 8};
    forward_list_print(l3);

    std::cout << std::endl;

    std::cout << "list 1: " << forward_list_size(l1) << std::endl;
    std::cout << "list 2: " << forward_list_size(l2) << std::endl;
    std::cout << "list 3: " << forward_list_size(l3) << std::endl;

    l1 = {0};
    l1.insert_after(l1.begin(), 7);
    forward_list_print(l1);

    l1.insert_after(l1.begin(), 1, 6);
    forward_list_print(l1);

    std::array<int, 3> iterator{3, 4, 5};
    l1.insert_after(l1.begin(), iterator.begin(), iterator.end());
    forward_list_print(l1);

    l1.insert_after(l1.begin(), {1, 2});
    forward_list_print(l1);

    erase(l1, l1.begin());
    forward_list_print(l1);

    erase(l3, l3.begin(), l3.end());
    forward_list_print(l3);

    l1 = {1, 3, 5};
    l2 = {2, 4, 6};
    l1.merge(l2);
    forward_list_print(l1);

    l3 = {1, 1, 1};
    l1.splice_after(l1.cbegin(), l3);
    forward_list_print(l1);
    forward_list_print(l3);

    return 0;
}

