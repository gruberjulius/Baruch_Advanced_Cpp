#include <iostream>
#include <bitset>
#include <random>

double testRandomness(unsigned int width, unsigned int numTests) {
  std::random_device rd;
  std::default_random_engine engine(rd());
  std::independent_bits_engine<std::default_random_engine, 32, unsigned int> bitEngine(engine);

  unsigned int totalSetBits = 0;

  for (unsigned int i = 0; i < numTests; ++i) {
    unsigned int randomBits = bitEngine();

    std::bitset<32> bitset(randomBits);
    totalSetBits += bitset.count() % (width + 1);  // Adjusted to consider the width

  }

  double percentage = (static_cast<double>(totalSetBits) / numTests) * 100.0;  // Adjusted calculation
  return percentage;
}

int main() {
  unsigned int width = 16;
  unsigned int numTests = 10;

  double percentage = testRandomness(width, numTests);

  std::cout << "Percentage of set bits: " << percentage << "%" << std::endl;

  return 0;
}

