#include <string>
#include <set>
#include <regex>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>

int main() {

	// GIVEN CODE
	std::string S2 = "1,1,2,3,5,8,13,21";
	std::regex myReg("(\\d+),?");

	// Part A

	// regex iterator based on S2 and myReg
	auto reg_it = std::sregex_iterator(S2.begin(), S2.end(), myReg);
	auto it_end = std::sregex_iterator();

	// Part B

    //set of str
	std::set<std::string> Strset;

	// iterating over regex operators
	for (auto it{ reg_it }; it != it_end; ++it) {

        //dereferencing the units
		std::smatch match{ *it };
		// adding to the output string
		Strset.insert(match.str());
	}

	// Part C


    //print the set
    for (const auto& element : Strset) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

	// Part D
    std::set<int> result;

    std::sregex_iterator it(S2.begin(), S2.end(), myReg);
    std::sregex_iterator end;

    for (; it != end; ++it) {
        std::smatch match = *it;
        int value = std::stoi(match[1]);
        result.insert(value);
    }

    // Print the set of integers
    for (const auto& element : result) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
