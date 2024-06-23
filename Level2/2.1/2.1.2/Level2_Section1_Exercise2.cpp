#include<iostream>
#include<memory>


template<typename T>
void isPointer_impl(const T& t, std::true_type){
    std::cout << "Pointer: " << *t << std::endl;
    
}


template<typename T>
void isPointer_impl(const T& t, std::false_type){
    std::cout << "Scalar Reference:  " << t << std::endl;
}

template<typename T>
void is_pointer(const T& val){
   isPointer_impl(val, std::is_pointer<T>());
}


int main(){
    int b = 5;
    int *a = &b;

    int d = 4;
    int &c = d;

    isPointer_impl(a);
    isPointer_impl(c);
    return 0;
}
