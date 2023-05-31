#include<iostream>
#include<type_traits>

class Shape
{
    public: 
        virtual void draw() = 0;
};

class Base{
    private:
        int y;
    public: 
        Base() {};
        void draw(){};
};

class Point: public Shape{
    public:
        Point(){};
        virtual void draw() override{};
    
};

template<typename T>
void classTypeDescription(const T& C){
    std::cout << std::boolalpha << std::is_abstract<T>::value << std::endl;
    std::cout << std::boolalpha << std::is_polymorphic<T>::value << std::endl;
    std::cout << std::boolalpha << std::is_empty<T>::value << std::endl;
}



template<typename class1, typename class2>
void base_of(const class1& C1, const class2& C2){
    std::cout << std::boolalpha << std::is_base_of<class2, class1>::value << std::endl;
    std::cout << std::boolalpha << std::is_base_of<class1, class2>::value << std::endl;
}

template<typename class1, typename  class2>
void convertible(const class1& C1, const class2& C2){

    std::cout << std::boolalpha << std::is_convertible<class2, class1>::value << std::endl;
    std::cout << std::boolalpha << std::is_convertible<class1, class2>::value << std::endl;
}


int main(){
    Point point;
    Shape* shape;

    std::cout << "Shape" << std::endl;
    classTypeDescription(*shape);
    classTypeDescription(point);
    Base base;
    classTypeDescription(base);
    
    base_of(point, shape);
    base_of(base, shape);
    base_of(point, shape);

    
    convertible(point, shape);
    convertible(base, shape);
    convertible(point, shape);
    return 0;
}
