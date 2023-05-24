#include<iostream>
#include<vector>
#include<algorithm>

class C1{

	private:
		std::vector<double> m_vec;
		C1 (const C1& copy) = delete;
		C1& operator = (const C1& copy) = delete;

	public:
		C1() = default; //{std::cout << "C default constructor has been called" << std::endl;};
		C1(std::vector<double> vec) : m_vec ( vec ) {std::cout << "C constructor has been called" << std::endl;};
        ~C1() {std::cout << "Destructor Called" << std::endl;};
		

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
    C1 sumsi;
    sumsi.set_vec({3, 4, 5});
    sumsi.print();

    std::vector<double> a = { 3, 4, 5 };
    C1 sumsi2(a);
    C1 sumsi3 = sumsi2;
    C1 sumsi4{a};
    return 0;
    
}
