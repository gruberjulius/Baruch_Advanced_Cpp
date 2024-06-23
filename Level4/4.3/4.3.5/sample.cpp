#include <iostream>
#include <bitset>
#include <random>

double calculatePercentage(unsigned int setBitsCount, unsigned int totalBitsCount) {
  return (static_cast<double>(setBitsCount) / totalBitsCount) * 100.0;
}

double testSetBitPercentage(unsigned int width, unsigned int numTests) {
  std::default_random_engine engine;
  std::independent_bits_engine<std::default_random_engine, 32, unsigned int> bitEngine(engine);

  unsigned int totalSetBitsCount = 0;
  unsigned int totalBitsCount = width * numTests;

  for (unsigned int i = 0; i < numTests; ++i) {
    unsigned int randomBits = bitEngine();

    std::bitset<32> bitset(randomBits);
    unsigned int setBitsCount = bitset.count();

    totalSetBitsCount += setBitsCount;
  }

  double percentage = calculatePercentage(totalSetBitsCount, totalBitsCount);
  return percentage;
}

int main() {
  unsigned int width = 2;
  unsigned int numTests = 1000000;

  double setBitPercentage = testSetBitPercentage(width, numTests);

  std::cout << "Percentage of set bits: " << setBitPercentage << "%" << std::endl;

  return 0;
}

