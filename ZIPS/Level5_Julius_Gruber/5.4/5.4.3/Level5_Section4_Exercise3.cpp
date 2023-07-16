#include <boost/functional/hash.hpp>
#include "Point.cpp"
#include <unordered_set>
#include <boost/unordered_set.hpp>
#include <functional>
#include <boost/functional/hash.hpp>
#include <chrono>
#include <iostream>


// Part a

//Given Code
struct PointHash : std::unary_function<Point, std::size_t> {
    std::size_t operator()(const Point& pt) const {
        std::size_t seed = 0;
        boost::hash_combine(seed, pt.x());
        boost::hash_combine(seed, pt.y());
        return seed;
    }
};

// Part b

// custom hash function
struct customPointHash : std::unary_function<Point, std::size_t> {
    std::size_t operator()(const Point& pt) const {
        // custom function that does not use boost/stl hash
        std::size_t hash_value = std::hash<double>()(pt.x()) + 100 * std::hash<double>()(pt.y());
        return hash_value;
    }
};


int main() {


    std::chrono::steady_clock::time_point start, end;

    // Part a

    boost::unordered_multiset<Point, PointHash> pointSet;

    // create multiset
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) { 
        pointSet.emplace(Point(i % 4, i / 4)); 
    }
    end = std::chrono::steady_clock::now();
    std::cout << "time create-multiset: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()  << "mus" << std::endl;

    // erasing multiset
    start = std::chrono::steady_clock::now();
    for (auto it = pointSet.begin() ; it != pointSet.end(); ++it) {
        it = pointSet.erase(it); 
    }
    end = std::chrono::steady_clock::now();
    std::cout << "time erase-multiset: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "mus" << std::endl;
    
    
    // Part b

    boost::unordered_multiset<Point, customPointHash> custompointSet;

    // creating multiset with custom hash function
    start = std::chrono::steady_clock::now();
    for (int i{ 0 }; i < 1000; ++i) { 
        custompointSet.emplace(Point(i % 4, i / 4)); 
    }
    end = std::chrono::steady_clock::now();
    std::cout << "time create multiset custom hash function: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;

    // erasing multisetwith custom hash function
    start = std::chrono::steady_clock::now();
    for (auto it{ custompointSet.begin() }; it != custompointSet.end(); ++it) {
        it = custompointSet.erase(it);
    };
    end = std::chrono::steady_clock::now();
    std::cout << "time erase multiset custom hash function: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()  << std::endl;


    // Part c

    std::unordered_multiset<Point, customPointHash> stdCustompointSet;

    // creating multiset with custom hash function
    start = std::chrono::steady_clock::now();
    for (int i =0 ; i < 1000; ++i) { 
        stdCustompointSet.emplace(Point(i % 4, i / 4)); 
    }
    end = std::chrono::steady_clock::now();
    std::cout << "time create std multiset custom hash function: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()  << std::endl;

    // erasing multisetwith custom hash function
    start = std::chrono::steady_clock::now();
    for (auto it{ stdCustompointSet.begin() }; it != stdCustompointSet.end(); ++it) {
        it = stdCustompointSet.erase(it);
    };
    end = std::chrono::steady_clock::now();
    std::cout << "time to erase std multiset custom hash function: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()  << std::endl;

}





