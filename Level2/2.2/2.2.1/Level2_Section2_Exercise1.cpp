#include<iostream>
#include<vector>
#include<complex>

template<typename T>
T Addition(const T& t1, const T& t2);

template<typename T>
T Addition_impl( const T& t1, const T& t2, std::true_type){
	//std::size_t n = t1.size();
	T t3(t1);
	for(auto i :t1 ){
		t3[i] =  Addition(t1[i], t2[i]);
	}	
	return t3;
}


template<typename T>
T Addition_impl(const T& t1, const T& t2, std::false_type){
    std::cout << "A" << std::endl;
	return t1 +  t2;
}

template<typename T>
T Addition(const T& t1, const T& t2){
	return Addition_impl(t1, t2, std::is_compound<T>());
}


template<typename T>
void print_obj(T a){
	int n = a.size();
	for(int i = 0; i < n; i++){
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

// Part b


template<typename T>
void AdditiveInverse( T& t);

//additive inverse for non compound types
template <typename T>
void AdditiveInverse_impl(T& t, std::false_type) {
    t = -t;
};


//additive inverse for non compound types
template <typename T>
void AdditiveInverse_impl(T& t, std::true_type) {
    for(int i = 0; i < t.size(); i++){
        AdditiveInverse(t[i]); 
    } 
};

template<typename T>
void AdditiveInverse( T& t){
    AdditiveInverse_impl(t, std::is_compound<T>());
}


int main(){
    //Part a
	double a = 3;
	double b = 4;
	double c = Addition(a, b);
	std::cout << c << std::endl;	
    AdditiveInverse(c);
	std::cout << c << std::endl;	
    //Vector
    std::cout << "Vector" << std::endl;
	std::vector<double> d  = {1, 2, 3};
	std::vector<double> e  = {3,2 , 1};
	std::vector<double> f = Addition(d, e); //test for vector
	print_obj(f);
    AdditiveInverse(f);
	print_obj(f);
    //Array
    std::cout << "Array" << std::endl;
    std::array<double, 3> g = {1, 2, 3};
    std::array<double, 3> h = {3, 2, 1};
    std::array<double, 3> i = Addition(g, h);
    print_obj(i);
    AdditiveInverse(i);
    print_obj(i);
    //Part C
    std::complex<double> z1(1.0, 2.0);
    std::complex<double> z2(0.5, 2.5);
    std::vector<std::complex<double>> a = {z1, z2};
    std::array<std::complex<double>, 2> b = {z1, z2};
    //the iteration over the loot can be done 
    //the problem occurs as the complex is a compound type: hence the iteration does not work
    //the only way to access complex variables is with real and imag and they are not subscriptable

	return 0;
}
