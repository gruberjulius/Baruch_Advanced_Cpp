#include<iostream>
#include<vector>
#include<algorithm>


template<class T>
class C3{

	private:
		T m_vec;

	public:
		explicit constexpr C3() {m_vec = {}; std::cout << "explicit C3 default constructor has been called" << std::endl;};
		              
		explicit C3(std::vector<double> vec) : m_vec ( vec ) {std::cout << "C3 constructor has been called" << std::endl;};
        ~C3() {std::cout << "Destructor Called" << std::endl;};
		

        void set_vec(  std::vector<double> input){
           m_vec = input;
           std::cout << "New value assigned" << std::endl;
        }
        void print(){
            for(auto x: m_vec){
                std::cout << x << std::endl;
            }
        }		

        void multiply(const double multiplicator){
            std::transform(m_vec.begin(), m_vec.end(), m_vec.begin(), [=](auto & i){return i * multiplicator;});
            std::cout << "C multiply function has been called." << std::endl;
        }
};        


int main(){
    C3 sumsi;
    sumsi.set_vec({3, 4, 5});
    sumsi.print();

    std::vector<double> a = { 3, 4, 5 };
    C3 sumsi2(a);
    C2 sumsi3 = sumsi2;
    C2 sumsi4{a};
    return 0;
    
}
