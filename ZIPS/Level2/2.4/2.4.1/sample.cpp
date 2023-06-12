#include <iostream>
#include <memory>

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    // Get the length of the array
    int length = sizeof(arr) / sizeof(arr[0]);

    // Create a smart pointer to the beginning of the array
    std::unique_ptr<int[]> ptr(new int[length]);
    std::copy(arr, arr + length, ptr.get());

    // Iterate through the array using the smart pointer
    for (int i = 0; i <= length + 10; i++) {
        std::cout << ptr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
