#include <iostream>
#include<string>
#include <boost/dynamic_bitset.hpp>

void func_part_a(){
    // Part a
    // unsigned long
    unsigned long value = 12345; // Example value
    boost::dynamic_bitset<> bits(value);
    
    std::cout << bits << std::endl;
    std::cout << "Check for the long long" << std::endl;
    
    // unsigned long long 
    unsigned long long value1 = 987654321; // Example value
    boost::dynamic_bitset<> bits1(value);

    std::cout << bits1 << std::endl;

    std::string fullString = "01010"; // Example full string
    boost::dynamic_bitset<> bits2(fullString);

    std::cout << bits2 << std::endl;
    
    // Part c 
    // exception handling for out of range values
    try {
        std::string testString1 = "010101010";
        // 42 is out of range
        boost::dynamic_bitset<> testBitset1(testString1, 10); // this index is out of range
    } catch (const std::out_of_range& err) // catching out of range index 
    {
        std::cout << "Error! Bitset is out of range" << std::endl; 
    }
    
    try {
        std::string out_of_range_str2 = "Julius"; 
        boost::dynamic_bitset<> out_of_range_bstr2(out_of_range_str2); // not transferable to 
    }
    catch (const std::invalid_argument& err) //catching invalid bitset
    {
        std::cout << "Error! Bitset is out of range" << std::endl;
    }

    // Part e 
    boost::dynamic_bitset<> bitset(5);
    std::cout << "Bitset at beginning " << bitset << std::endl;
    // Set/reset all bits.
    bitset.set(); 
    std::cout << "Bitset after setting " << bitset << std::endl;

    bitset.reset(); 
    std::cout << "Bitset after resetting " << bitset << std::endl;
    // Flip the bits.
    bitset.flip(); 
    std::cout << "Bitset after flipping " << bitset << std::endl;
    // Test if none, all or any bits are set.
    bitset.none(); 
    std::cout << "Bitset after none " << bitset << std::endl;
    bitset.all(); 
    std::cout << "Bitset after all " << bitset << std::endl;
    bitset.any(); 
    std::cout << "Bitset after any " << bitset << std::endl;
    // Access the elements.
    std::cout << "bitset.test(0): " << bitset.test(0) << std::endl;
    std::cout << "bitset[0]: " << bitset[0] << std::endl;
    // Count the number of set bits. 
    std::cout << "bitset.count(): " << bitset.count() << std::endl; 

    // Part e 
    // Converting bitset to std::string, unsigned long, unsigned long long 
    boost::dynamic_bitset<> bit_orig(13);
    boost::dynamic_bitset<> bit_long(bit_orig);
    
    boost::dynamic_bitset<> bit_str(bit_orig);

	std::string buffer;	
	to_string(bit_str, buffer); 
    std::cout << bit_orig << " as a long is: " << bit_long << '\n';
    std::cout << bit_orig << " as a string is: " << buffer<< '\n';

    boost::dynamic_bitset<> bset1(5);
    boost::dynamic_bitset<> bset2(5);

    // this should be equal
    if (bset1 == bset2)
    {
        std::cout << "Bitsets are equal \n";
    }

}



void func_part_b(){
        // Part a
    boost::dynamic_bitset<> bs1(3);
    bs1.set();
    boost::dynamic_bitset<> bs2(3);

    std::cout << "bs1 " << bs1 << " bs2 " << bs2 << std::endl;

    // Part b
    // Toggling the bitsets
    bs1.flip();
    bs2.flip();

    std::cout << "bs1 " << bs1 << " bs2 " << bs2 << std::endl;

    // Part c
    std::cout << "XOR: " << (bs1 ^ bs2) << std::endl;
    std::cout << "OR: " << (bs1 | bs2) << std::endl;
    std::cout << "AND: " << (bs1 & bs2) << std::endl;

    // Part d
    // Left shift operations
    boost::dynamic_bitset<> bsLeft(bs1);
    bsLeft <<= 1;
    std::cout << "bs1 " << bs1 << std::endl;

    // Right shift operations
    boost::dynamic_bitset<> bsRight(bs1);
    bsRight >>= 1;
    std::cout << "bs1 " << bs1 << std::endl;

    // Part e
    // Creating hashed values of the bitsets
    std::size_t bs1Hash = std::hash<boost::dynamic_bitset<>>{}(bs1);
    std::size_t bs2Hash = std::hash<boost::dynamic_bitset<>>{}(bs2);

    // Given Code
    auto blit = 0b0011;

    boost::dynamic_bitset<> b{0b0011}; // Create from a binary literal

    boost::dynamic_bitset<> bs(blit);

    boost::dynamic_bitset<unsigned int> dbs(4); // All 0 by default

    dbs[1] = dbs[0] = 1;

    std::cout << "\nbyte: " << b.to_ulong() << '\n';

    std::cout << "bitset: " << bs << '\n';

    std::cout << "dynamic bitset: " << dbs << '\n';

    // Part g
    boost::dynamic_bitset<> b2{0b1011}; // Binary literal
    boost::dynamic_bitset<> b3{7};      // Binary from integer
    boost::dynamic_bitset<> b4 = b3 ^ b; // Binary from existing bytes

    // Part h
    b3 &= b4; // AND operation (bitwise)
    b3 |= b2; // OR operation (bitwise)

    // Part i
    // Shift everything to the left by 8 bits, hence every content goes out of scope
    std::cout << "B2 left bit shift " << (b2 << 8).to_ulong() << std::endl;

    // Shift everything to the right by 8 bits, hence every content goes out of scope
    std::cout << "B2 right bit shift " << (b2 >> 8).to_ulong() << std::endl;


}

int main() {
    //include functions from part 1
    func_part_a();
    //include functions from part 2 

    func_part_b();

}
