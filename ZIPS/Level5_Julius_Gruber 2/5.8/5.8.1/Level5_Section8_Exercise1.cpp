#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

// function to print vector
template <typename T>
void print(const std::vector<T> vec) {
    std::cout << "[ ";
	for (int i = 0 ; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
		if (i != vec.size() - 1) { 
            std::cout << ", "; 
        }
	};
    std::cout << " ]";
}

int main() {

	// Part A

	std::vector<int> vec2{ 3,4,5,6,7,5,6,7,8,9,1,2,3,4 };

	std::cout << "before make_heap: " << std::endl;
    print(vec2); 
	// Part B

	std::make_heap(vec2.begin(), vec2.end());

	std::cout << "after make_heap: " << std::endl;
    print(vec2) ;
    //all parents nodes have higher values than children node's

    // Part C
	std::pop_heap(vec2.begin(), vec2.end());

	std::cout << "after pop_heap: " << std::endl;
    print(vec2) ;
    //removes the largest elements from the top and puts it at the end

	vec2.pop_back();

	std::cout << "after pop_back: " << std::endl;
    print(vec2) ;
    //useful to remove the largest element from the end

	// Part C

	vec2.push_back(6);

	std::cout << "after push_back: " << std::endl;
    print(vec2);
    //add value 6 to the heap

	std::push_heap(vec2.begin(), vec2.end());

	std::cout << "after push_heap: " << std::endl;
    print(vec2);
	// now the heap is sorted again

	// Part E

	std::sort_heap(vec2.begin(), vec2.end());

	std::cout << "after sort_heap: " << std::endl;
    print(vec2);
    //the values are sorted in ascending order

	// Part F

	std::cout << "largest element of vec2: " << *std::max_element(vec2.begin(), vec2.end()) << std::endl;


}
