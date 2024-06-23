#include <iostream>
#include <random>
#include <bitset>

// Engine print function
void print(auto rem, auto engine, int count) {
    std::cout << rem << ": ";
    for (int i{}; i != count; ++i){
        std::cout << static_cast<unsigned>(engine()) << ' ';
    }
    std::cout << '\n';
}

// Print function to output bits and calculate set bit count and percentage
template <typename EngineType, int Width>
void print_bits(std::string rem, EngineType engine, int count) {
    std::cout << rem << ":\n";
    int counter = 0;
    for (int i = 0; i != count; ++i) {
        auto bits = std::bitset<Width>(engine());  // Use the random number to create bitset
        std::cout << bits << " ";  // Print the random bits
        counter += bits.count();  // Count bits set in this bitset and add to running counter
    }
    std::cout << '\n';
    std::cout << "Set Bit Count: " << counter << std::endl;  // Output the final count 
    std::cout << "Set Bit Percentage: " << 100.0 * counter / (count * Width) << "%" << std::endl;  // Output the percentage
}

int main() {
    // Part A: Using independent_bits_engine with width = 4
    auto seed = std::random_device{}();  // Generate random seed
    std::independent_bits_engine<std::default_random_engine, 4, unsigned long> indbit(seed);  // Instantiate independent_bits_engine with width = 4
    print("Bitset 1 (as integers)", indbit, 4);  // Display as integers

    // Part C: Using independent_bits_engine with different widths
    // Width = 2
    std::independent_bits_engine<std::default_random_engine, 2, unsigned long> indbit2(seed);
    print_bits<decltype(indbit2), 2>("Bitset 1 (as bits)", indbit2, 40);  // Output bits and calculate set bit count and percentage

    // Width = 8
    std::independent_bits_engine<std::default_random_engine, 8, unsigned long> indbit3(seed);
    print_bits<decltype(indbit3), 8>("Bitset 1 (as bits)", indbit3, 30);  // Output bits and calculate set bit count and percentage

    // Width = 16
    std::independent_bits_engine<std::default_random_engine, 16, unsigned long> indbit4(seed);
    print_bits<decltype(indbit4), 16>("Bitset 1 (as bits)", indbit4, 30);  // Output bits and calculate set bit count and percentage

    // Width = 64
    std::independent_bits_engine<std::default_random_engine, 64, unsigned long long> indbit5(seed);
    print_bits<decltype(indbit5), 64>("Bitset 1 (as bits)", indbit5, 30);  // Output bits and calculate set bit count and percentage

    // Overall thoughts: The set bit percentage tends to be more consistent as the width increases, which is caused by the crentral limit theorem
}

