#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

void print(std::vector<char> vec){
	int n = vec.size();
	for(int i = 0;i <n; i++){
		std::cout << vec[i] << " " << std::endl;
	}
}	

int main() {

	// Part a

    //define the two sets
	std::vector<char> S1{ 'a', 'b', 'c', 'd', 'e', 'k' };
	std::vector<char> S2{ 'a', 'e' };

	std::for_each(S2.begin(), S2.end(), [&](const char c) {
		S1.erase(std::remove(S1.begin(), S1.end(), c));
		});
	print(S1);
    //function works as expected

}

