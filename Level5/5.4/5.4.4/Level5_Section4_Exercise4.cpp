#include <boost/functional/hash.hpp>
#include <iostream>
#include <string>

// Part a

//end of variadic hash
template <typename T>
void hash_value(std::size_t& seed, const T& val)
{
    // combining hash of seed with last value
    boost::hash_combine(seed, val);
};

// variadic hash begin
template <typename T, typename... Types>
void hash_value(std::size_t& seed, const T& val, const Types&... args)
{
    // combining seed with first value
    boost::hash_combine(seed, val);

    // calling recursively
    hash_value(seed, args...);
};


// Part B

//hash_value function
template <typename... Types>
std::size_t hash_value(const Types&... args)
{
    std::size_t seed = 0;
    hash_value(seed, args...);
    return seed;
};

int main() {

    // Part a

    double v1 = 3.21 ;
    double v2 = 1.44 ;
    double v3 = 1.68 ;

    std::size_t seed = 0 ;
    hash_value(seed, v1);
    std::cout << "hash with one argument: " << seed << std::endl;

    seed = 0;
    hash_value(seed, v1, v2);
    std::cout << "hash with two arguments: " << seed << std::endl;

    seed = 0;
    hash_value(seed, v1, v2, v3);
    std::cout << "hash with three arguments: " << seed << std::endl;

    //works with all amount of numbers
    
    // Part b

    int int_var = 42 ;
    double double_var = 2.71 ;
    std::string string_var{ "merry christmas" };

    seed = hash_value(int_var);
    std::cout << "hash with 1 argument: " << seed << std::endl;

    seed = hash_value(int_var, double_var);
    std::cout << "hash with 2 heterogenuous arguments: " << seed << std::endl;

    seed = hash_value(int_var, double_var, string_var);
    std::cout << "hash with 3 heterogenuous arguments: " << seed << std::endl;


}
