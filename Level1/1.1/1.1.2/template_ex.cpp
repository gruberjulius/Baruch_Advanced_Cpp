#include<iostream>

//template <typename T>
 //                 T multi (const T& x, const T& y)
//{ return x * y; }
float div1(float a, float b){
    return a/b;
}


int div1 (int a, int b ){
    return a/ b;
}

int main(){
    float  a = 3;
    float b = 4;
    auto c = div1(a, b);

    std::cout << c << std::endl;



}
