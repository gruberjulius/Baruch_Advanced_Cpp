#include<iostream>
#include<bitset>
#include<boost/dynamic_bitset/dynamic_bitset.hpp>


int main(){
	
    // Part a 
	std::bitset<3> bs1;
	bs1.set();
	std::bitset<3> bs2;

    std::cout << "bs1" << bs1 << " bs2" << bs2 << std::endl;
    //Part b
    //toggling the bitsets
    bs1.flip();
    bs2.flip();

    std::cout << "bs1" << bs1 << " bs2" << bs2 << std::endl;
    // PART c 
	std::cout << "XOR: " << (bs1 ^ bs2) << std::endl;
	std::cout << "OR: " << (bs1 | bs2) << std::endl;
	std::cout << "AND: " << (bs1 & bs2) << std::endl;

	// Part d 
	// left shift operations
	std::bitset<3> bsLeft{ bs1 << 1 };
    std::cout << "bs1 " << bs1  << std::endl;
	// right shift operations
	std::bitset<3> bsRight{ bs1 >> 1 };

    std::cout << "bs1 " << bs1  << std::endl;
    
    // Part e 
	// creating hashed values of the bisets
	std::size_t bs1Hash = std::hash<std::bitset<3>>{}(bs1);
	std::size_t bs2Hash = std::hash<std::bitset<3>>{}(bs2);

    //Given Code 
    auto blit = 0b0011;

    std::byte b{ 0b0011 }; // Create from a binary literal

    std::bitset<4> bs(blit);

    boost::dynamic_bitset<unsigned int> dbs(4); // all 0 by default

    dbs[1] = dbs[0] = 1;

    std::cout << "\n byte: " << std::to_integer<int>(b) << '\n';

    std::cout << "bitset: " << bs << '\n';

    std::cout << "dynamic bitset: " << dbs << '\n';
    //Working as expected
    //
    // Part g 
	std::byte b2{ 0b1011 }; //Binary literal
	std::byte b3{ 7 }; // binary from integer 
	std::byte b4 = b3 ^ b; //binary from existing bytes

    // Part h 
	b3 &= b4; // AND operation (bitwise)
	b3 |= b2; // OR operation (bitwise)

    // Part i 
	// Shift everything to the left by 8 bits, hence every content goes out of scope
    std::cout << "B2 left bit shift " << std::to_integer<int>(b2 << 8) << std::endl; 
	
	// Shift everything to the right by 8 bits, hence every content goes out of scope 
	std::cout << "B2 right bit shift " << std::to_integer<int>(b2 >> 8) << std::endl;

   	// Part j 
    // As the are from fixed size, they can be easily be used as a replacement for an array of bools
    // which safes spaces and makes operations more efficetion
	//  Bytes and bitsets can represent raw memory bitmap. 
	
	//  In the lecture concepts like setting flags, sparse matrices, huffman coding, bloom filters compact data structures where given as examples



}
