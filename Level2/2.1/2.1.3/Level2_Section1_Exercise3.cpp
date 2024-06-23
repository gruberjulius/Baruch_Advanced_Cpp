#include<iostream>
#include<typeinfo>
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
    std::cout << "  " << typeid(T).name() << std::endl;
    std::cout << "Is abstract" << std::boolalpha << std::is_abstract<T>::value << std::endl;
    std::cout <<  "Is polymorphic" <<  std::boolalpha << std::is_polymorphic<T>::value << std::endl;
    std::cout << " Is empty " << std::boolalpha << std::is_empty<T>::value << std::endl;
}



template<typename class1, typename  class2>
void same(const class1& C1, const class2& C2){

    std::cout << " Check if Type of  " << typeid(class1).name() << " and "  << typeid(class2).name() <<  "are the same " << std::endl;
    std::cout << std::boolalpha << std::is_same<class2, class1>::value << std::endl;
    std::cout << std::boolalpha << std::is_same<class1, class2>::value << std::endl;
}


template<typename class1, typename class2>
void base_of(const class1& C1, const class2& C2){

    std::cout << " Check if Type of  " << typeid(class1).name() << " and "  << typeid(class2).name() <<  "are the base of each other " << std::endl;

    std::cout << std::boolalpha << std::is_base_of<class2, class1>::value << std::endl;
    std::cout << std::boolalpha << std::is_base_of<class1, class2>::value << std::endl;
}

template<typename class1, typename  class2>
void convertible(const class1& C1, const class2& C2){

    std::cout << " Check if Type of  " << typeid(class1).name() << " and "  << typeid(class2).name() <<  "are convertible " << std::endl;
    std::cout << std::boolalpha << std::is_convertible<class2, class1>::value << std::endl;
    std::cout << std::boolalpha << std::is_convertible<class1, class2>::value << std::endl;
}



int main(){
    Point point;
    Shape* shape;

    std::cout << "Check if Types are empty, polymorphic, abstract" << std::endl;
    classTypeDescription(*shape);
    classTypeDescription(point);
    Base base;
    classTypeDescription(base);
    std::cout << "Check if types are the same " << std::endl;
    
    same(point, shape);
    same(base, shape);
    same(point, shape);


    std::cout << "Check if types are base of " << std::endl;
    
    base_of(point, shape);
    base_of(base, shape);
    base_of(point, shape);

    std::cout << "Check if types are convertible " << std::endl;
    convertible(point, shape);
    convertible(base, shape);
    convertible(point, shape);
    return 0;
}
