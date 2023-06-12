#include <iostream>
#include <bitset>
#include <boost/dynamic_bitset.hpp>
#include <string>

int main(){
    //Part a
    //unsigned long
    unsigned long value = 12345; // Example value
    std::bitset<sizeof(unsigned long) * 8> bits(value);
    
    std::cout << bits << std::endl;
    std::cout << "Check for the long long" << std::endl;
    
    //unsigned long long 
    unsigned long long value1 = 987654321; // Example value
    std::bitset<sizeof(unsigned long long) * 8> bits1(value);

    std::cout << bits1 << std::endl;

    std::string fullString = "01010"; // Example full string
    std::bitset<5> bits2(fullString);

    std::cout << bits2 << std::endl;
    // PART c 
    // exception handling for out of range values
    try {
        std::string testString1 = "010101010";
        // 42 is out of range
        std::bitset<5> testBitset1{ testString1,10}; //this index is out of range
    } catch (const std::out_of_range& err) // catching out of range index 
    {
        std::cout << "Error! Bitset is out of range" << std::endl; 
    }
    
    try {
        std::string out_of_range_str2 = "Julius"; 
        std::bitset<7> out_of_range_bstr2{ out_of_range_str2}; // not transferable to 
    }
    catch (const std::invalid_argument& err) //catching invalid bitset
    {
        std::cout << "Error! Bitset is out of range" << std::endl;
    }

    // Part e 
    std::bitset<5> bitset;
    std::cout << "Bitset at beginning " << bitset << std::endl;
    //Set/reset all bits.
    bitset.set(); 
    std::cout << "Bitset after setting " << bitset << std::endl;

    bitset.reset(); 
    std::cout << "Bitset after resetting " << bitset << std::endl;
    //Flip the bits.
    bitset.flip(); 
    std::cout << "Bitset after flipping " << bitset << std::endl;
    //Test if none, all or any bits are set.
    bitset.none(); 
    std::cout << "Bitset after none " << bitset << std::endl;
    bitset.all(); 
    std::cout << "Bitset after all " << bitset << std::endl;
    bitset.any(); 
    std::cout << "Bitset after any " << bitset << std::endl;
    //Access the elements.
    std::cout << "bitset.test(0): " << bitset.test(0) << std::endl;
    std::cout << "bitset[0]: " << bitset[0] << std::endl;
    //Count the number of set bits. 
    std::cout << "bitset.count(): " << bitset.count() << std::endl; 

    // Part e 
    // Converting bitset to std::string, unsigned long, unsigned long long 
    std::bitset<5> bit_orig(13) ;
    std::bitset<5> bit_long(bit_orig);
    std::bitset<5> bit_llong(bit_orig);
    std::bitset<5> bit_str(bit_orig);

    std::cout << bit_orig << " as a long is: " << bit_long.to_ulong() << '\n';
    std::cout << bit_orig << " as a long long is: " << bit_llong.to_ullong() << '\n';
    std::cout << bit_orig << " as a string is: " << bit_str.to_string() << '\n';

    std::bitset<5> bset1(5); 
    std::bitset<5> bset2(5);

    // this should be equal 
    if (bset1 == bset2)
    {
        std::cout << "Bitsets are equal \n"; 
    }
    
}
