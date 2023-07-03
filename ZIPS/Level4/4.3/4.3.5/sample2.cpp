#include <iostream>
#include <bitset>
#include <random>

unsigned int countSetBits(unsigned int width, unsigned int numTests) {
  std::random_device rd;
  std::default_random_engine engine(rd());
  std::independent_bits_engine<std::default_random_engine, 32, unsigned int> bitEngine(engine);

  unsigned int totalCount = 0;

  for (unsigned int i = 0; i < numTests; ++i) {
    unsigned int randomBits = bitEngine();
    std::bitset<32> bitset(randomBits >> (32 - width));

    unsigned int setBitsCount = bitset.count();
    totalCount += setBitsCount;
  }

  return totalCount;
}

int main() {
  unsigned int width = 2;
  unsigned int numTests = 1000000;

  unsigned int totalSetBits = countSetBits(width, numTests);

  double percentage = (static_cast<double>(totalSetBits) / (numTests * width * 32)) * 100.0;

  std::cout << "Percentage of set bits: " << percentage << "%" << std::endl;

  return 0;
}

