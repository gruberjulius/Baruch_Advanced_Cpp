#include<iostream>
#include<type_traits>


class Shape
{
public: 
    virtual void draw() = 0;
};


class Point: public Shape
{
public:
    Point(){};
    virtual void draw() override {};
};



class Point2: public Shape
{
public:
    Point2() = delete;
    Point2& operator=(const Point2& other) = delete;
    virtual void draw() override {};
};


class Point3: public Shape
{
public:
    Point3(){};
    Point3(Point3 && other) noexcept = default;
    Point3& operator=(Point3&& other) noexcept = default;
    virtual void draw() override {};
};



///virtual des /cos: def, copy move / copy assign move assig

int main(){
    Shape * shape;
//    Point point;
    //Part A
    std::cout << "Part A" << std::endl;
    std::cout << std::boolalpha <<  std::has_virtual_destructor<Point>::value  << std::endl;
    //Part B
    std::cout << "Part B" << std::endl;
    std::cout << std::boolalpha <<  std::is_default_constructible<Point>::value  << std::endl;
    std::cout << std::boolalpha <<  std::is_copy_constructible<Point>::value  << std::endl;
    std::cout << std::boolalpha <<  std::is_move_constructible<Point>::value  << std::endl;
    //Part C

    std::cout << "Part C" << std::endl;

    std::cout << std::boolalpha <<  std::is_copy_assignable<Point>::value  << std::endl;
    std::cout << std::boolalpha <<  std::is_move_assignable<Point>::value  << std::endl;

    //Part D 
    std::cout << "Part D" << std::endl;
    std::cout << std::boolalpha <<  std::is_default_constructible<Point2>::value  << std::endl;
    std::cout << std::boolalpha <<  std::is_copy_constructible<Point2>::value  << std::endl;
    std::cout << std::boolalpha <<  std::is_move_constructible<Point2>::value  << std::endl;
    std::cout << std::boolalpha <<  std::is_copy_assignable<Point2>::value  << std::endl;
    std::cout << std::boolalpha <<  std::is_move_assignable<Point2>::value  << std::endl;

    //Part E
    std::cout << "Part E" << std::endl;


    std::cout << std::boolalpha <<  std::is_default_constructible<Point3>::value  << std::endl;
    std::cout << std::boolalpha <<  std::is_copy_constructible<Point3>::value  << std::endl;
    std::cout << std::boolalpha <<  std::is_move_constructible<Point3>::value  << std::endl;
    std::cout << std::boolalpha <<  std::is_copy_assignable<Point3>::value  << std::endl;
    std::cout << std::boolalpha <<  std::is_move_assignable<Point3>::value  << std::endl;
    return 0;
}
