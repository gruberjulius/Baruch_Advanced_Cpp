#include <boost/bimap.hpp>
#include <string>
#include <iostream>


int main() {
    //Part A
    boost::bimap<std::string, int> bimap;

    // Populate the bimap using insert()
    bimap.insert(value_type("Alice", 25));
    bimap.insert(value_type("Bob", 30));
    bimap.insert(value_type("Charlie", 35));

    //Part B
    // Print the left map (names)
    std::cout << "Left Map (Names):" << std::endl;
    for (const auto& pair : bimap.left) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }

    // Print the right map (ages)
    std::cout << "Right Map (Ages):" << std::endl;
    for (const auto& pair : bimap.right) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }

    //Part C
    try {
        // Search for age based on name
        int age = bimap.left.at("Alice");
        std::cout << "Age of Alice: " << age << std::endl;

        // Search for name based on age
        std::string name = bimap.right.at(30);
        std::cout << "Name of person with age 30: " << name << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Key not found: " << e.what() << std::endl;
    }

    //Part D
    // Iterate over the bimap using the third view (set of relations)
    std::cout << "Bimap Iteration using the third view:" << std::endl;
    for (const auto& relation : bimap) {
        std::cout << relation.left << " -> " << relation.right << std::endl;
    }

    return 0;
}
