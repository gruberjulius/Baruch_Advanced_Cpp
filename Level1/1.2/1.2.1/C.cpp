#include<iostream>
#include<vector>
#include<algorithm>

class C{

	private:
		std::vector<double> m_vec;

	public:
		explicit C() {std::cout << "C default constructor has been called" << std::endl;};
		C(std::vector<double> vec) : m_vec ( vec ) {std::cout << "C constructor has been called" << std::endl;};
		C(const C& copy) {m_vec = copy.m_vec; std::cout << "C copy constructor has been called." << std::endl; };
        C& operator= (const C& copy) {m_vec = copy.m_vec; std::cout << " C assignment has been called." << std::endl; return *this;}
        ~C() {std::cout << "Destructor Called" << std::endl;};

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
    C sumsi;
    sumsi.set_vec({3, 4, 5});
    sumsi.print();

    std::vector<double> a = { 3, 4, 5 };
    C sumsi2(a);
    C sumsi3 = sumsi2;
    C sumsi4{a};
    return 0;
    
}
