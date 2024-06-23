#include <unordered_set>
#include <iostream>
#include <boost/unordered_set.hpp>

//Code from previous exercises
template <typename Key, typename Hash, typename EqPred>
void BucketInformation( std::unordered_set<Key, Hash, EqPred>& c, int minBucketCount = 10) {
    //Part A
    std::cout << "Number of buckets: " << c.bucket_count() << std::endl;
    std::cout << "Maximum number of possible buckets: " << c.max_bucket_count() << std::endl;
    //Part B
    std::cout << "Current load factor: " << c.load_factor() << std::endl;
    std::cout << "Current maximum load factor: " << c.max_load_factor() << std::endl;
    //Part C
    std::cout << "Bucket sizes:" << std::endl;
    for (std::size_t i = 0; i < c.bucket_count(); ++i) {
        std::cout << "Bucket " << i << ": " << c.bucket_size(i) << std::endl;
    }
    //Part D
    c.rehash(minBucketCount);
}

template <typename T>
void hash_value(std::size_t& seed, const T& val) {
    boost::hash_combine(seed, val);
}

template <typename T, typename... Types>
void hash_value(std::size_t& seed, const T& val, const Types&... args) {
    boost::hash_combine(seed, val);
    hash_value(seed, args...);
}

template <typename... Types>
std::size_t hash_value(const Types&... args) {
    std::size_t seed = 0;
    hash_value(seed, args...);
    return seed;
}


// Given Code

struct S
{
    std::string f; std::string s;
    S(const std::string& s1,
       const std::string& s2) : f(s1), s(s2) {}
};

class SHash // Hash for class S
{
public:
    std::size_t operator() (const S & s) const
    {
        return hash_value(s.f, s.s);
    }
};

class SEqual // Equality for S
{
public:
    bool operator()(const S& lhs, const S& rhs) const
    {
        return (rhs.f == lhs.f && rhs.s == lhs.s);
    }
};

int main() {

    // Part A

    std::unordered_set<S, SHash, SEqual> mySet;

    // adding elements to set
    mySet.emplace(S("Julius", "Gruber"));
    mySet.emplace(S("Ursula", "Gruber"));

    // Part B
    BucketInformation(mySet);
    //all the elements are in the buckets
}
