#include <iostream>
#include <list>
#include <boost/functional/hash.hpp>


struct Point {
    int x;
    int y;
};

struct LineSegment {
    Point start;
    Point end;
};

std::size_t hash_value(const Point& pt) {
    std::size_t seed = 0;
    boost::hash_combine(seed, pt.x);
    boost::hash_combine(seed, pt.y);
    return seed;
}

std::size_t hash_value(const LineSegment& line) {
    std::size_t seed = 0;
    boost::hash_combine(seed, hash_value(line.start));
    boost::hash_combine(seed, hash_value(line.end));
    return seed;
}

struct PointHash {
    std::size_t operator()(const Point& pt) const {
        std::size_t seed = 0;
        boost::hash_combine(seed, pt.x);
        boost::hash_combine(seed, pt.y);
        return seed;
    }
};

int main(){
    Point pt{3, 4};
    LineSegment line{{1, 2}, {5, 6}};

    std::size_t pointHash = hash_value(pt);
    std::size_t lineHash = hash_value(line);

    std::cout << "Hash of Point: " << pointHash << std::endl;
    std::cout << "Hash of LineSegment: " << lineHash << std::endl;

    std::list<Point> points;
    
    Point pt1{3, 4};
    Point pt2{5, 6};
    Point pt3{8, 8};
    points.emplace_back(pt1);
    points.emplace_back(pt2);
    points.emplace_back(pt3);

    std::size_t pointsHash = boost::hash_range(points.begin(), points.end());

    std::cout << "Hash of Points: " << pointsHash << std::endl;

    
    PointHash hashFunc;
    std::size_t pointHash1 = hashFunc(pt);

    std::cout << "Hash of Point: " << pointHash1 << std::endl;


    return 0;
}


