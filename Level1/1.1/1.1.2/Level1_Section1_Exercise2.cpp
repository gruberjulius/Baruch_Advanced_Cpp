#include<iostream>
#include<complex>
#include <numeric>


auto MyMultiply = [] (auto x, auto y) { return x*y ;};

struct FOMultiply
{
    template <typename T>
                  T operator () (const T& x, const T& y)
        { return x * y; }
};

void print_vec(std::vector<int> vec){
    for(auto i: vec){
        std::cout << i << std::endl;
    }
}

template<typename T>
T MyMultiply2(const T& x, const T& y){ return x*y ;};

int main(){
    // N.B. Generic lambda
    std::vector<int> vec {1, 2, 3, 4, 5};
    int acc = std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
    std::cout << acc << std::endl;
    int accGen = std::accumulate(vec.begin(), vec.end(), 1, FOMultiply());
    std::cout << accGen << std::endl;
    int accTemp = std::accumulate(vec.begin(), vec.end(), 1, MyMultiply);
    std::cout << accTemp << std::endl;



    using Complex = std::complex<double>;
    std::vector<Complex> complexArray{Complex(1.0, 1.0), Complex(2.0, 2.0)};
    Complex initCVal(1.0, 1.0);

    //with function object
    Complex accC  =  std::accumulate(complexArray.begin(), complexArray.end(), initCVal, FOMultiply());
    std::cout << "Sum 6, complex numbers: " << accC << std::endl;
    //with template 
    auto accTc = std::accumulate(complexArray.begin(), complexArray.end(), initCVal, MyMultiply2<Complex>);
    std::cout << "Sum 6, complex numbers: " << accTc << std::endl;
    //with auto function
    auto accAc = std::accumulate(complexArray.begin(), complexArray.end(), initCVal, MyMultiply);
    std::cout << "Sum 6, complex numbers: " << accAc << std::endl;
    
    //b.
    int iVal = 0;
    Complex sum_complex(1.0, 1.0);
    std::for_each(vec.begin(), vec.end(), [&](int const& i) { iVal +=i; });
    std::for_each(complexArray.begin(), complexArray.end(), [&](Complex const& i){sum_complex +=i;} );
    
    std::cout << iVal << std::endl;


    std::cout << "Sum 6, complex numbers: " << sum_complex << std::endl;
    //c.
    int subtractor = 5;

    auto subtract_func = [&](int & i){ i -= subtractor ;};

    print_vec(vec);

    std::for_each(vec.begin(), vec.end(), subtract_func);

    print_vec(vec);

    return 0;
}




