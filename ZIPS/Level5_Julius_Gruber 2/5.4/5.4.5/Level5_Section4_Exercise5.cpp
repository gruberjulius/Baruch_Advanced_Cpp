#include <iostream>
#include <unordered_set>
#include <string>


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

int main() {
    std::unordered_set<int> numbers = {1, 2, 3, 4, 5};
    BucketInformation(numbers);

    std::unordered_set<std::string> words = {"apple", "banana", "orange"};
    BucketInformation(words);

    // Rehashing example
    std::unordered_set<int> numbers2 = {1, 2, 3, 4, 5};
    BucketInformation(numbers2);

    // Rehash to have at least 10 buckets
    BucketInformation(numbers2, 10);

    return 0;
}
