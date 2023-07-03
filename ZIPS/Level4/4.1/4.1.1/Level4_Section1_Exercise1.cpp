#include<iostream>
#include<bitset>

class Proposition{
private:
	std::bitset<1> data;
public:

	Proposition(){};
	Proposition(bool a){
		data.set(0 ,a);
	}
	Proposition(std::bitset<1> a ){
		data = a;
	}

    // Part B

	bool operator==(const Proposition& p) { return p.data[0] == this->data[0]; };		// equality
	bool operator!=(const Proposition & p) { return p.data[0] != this->data[0]; };		// inequality
	Proposition operator&(const Proposition& p) { return p.data[0] && this->data[0]; };	// and
	Proposition operator|(const Proposition& p) { return p.data[0] || this->data[0]; };	// or
	Proposition operator^(const Proposition& p) { return p.data[0] ^ this->data[0]; };	// xor
	Proposition operator!(){ return !this->data[0]; };									// negation
	void operator=(bool val) { this->data.set(0, val); };						// assignement

    //defining the friend functions: we need friend keyword here
	friend Proposition operator%(const Proposition& p1, const Proposition& p2) {		// conditionnal 
		return !p1.data[0] | p2.data[0];
	};
	friend Proposition operator%=(const Proposition& p1, const Proposition& p2) {		// biconditionnal
		return ( p1 % p2 ) & ( p2 % p1 );
	};
	// printing the value
	friend std::ostream& operator<<(std::ostream& out, const Proposition& p) {
		out << std::boolalpha << p.data[0];
		return out;
	};

};

int main(){
	Proposition a;	
	bool b = true;
	Proposition A(b);	
	std::bitset<1> c = {false};
	Proposition B(c);	

    //Part B
    //Testing Functionalities
	std::cout << std::boolalpha << (A == true) << std::endl;	// equality
	std::cout << std::boolalpha << (A != true) << std::endl;	// inequality
	std::cout << (A & B) << std::endl;						// and
	std::cout << (A | B) << std::endl;						// or
	std::cout << (A ^ B) << std::endl;						// xor
	std::cout << (!A) << std::endl;							// not
	std::cout << (A % B) << std::endl;						// conditionnal
	std::cout << (A %= B) << std::endl;						// biconditionnal
	B = true;
	std::cout << B << std::endl;								// assignement
	std::cout << std::endl;
	// works as expected

    // Part C:
	// checking De Morgan's Laws
	std::cout << "De Morgan Laws:" << std::endl;
	std::cout << std::boolalpha << (!(A | B) == (!A & !B)) << std::endl;
	std::cout << std::boolalpha << (!(A & B) == (!A | !B)) << std::endl;
    //works as expected

    // Part D:
	// checking Distributive Laws
	Proposition C(true);
	std::cout << "Distributive Laws:" << std::endl;
	std::cout << std::boolalpha << (A & (B | C) == ((A & B) | (A & C))) << std::endl;
	std::cout << std::boolalpha << (A | (B & C) == ((A | B) & (A | C))) << std::endl;
    //works as expected

    std::vector<Proposition> both;
    both.push_back(Proposition(true));
    both.push_back(Proposition(false));
    for(auto A: both){
        for(auto B: both){
            for(auto B: both){
                std::cout << "Values: " << A << B << C << " LHS and RHS equal? " << ((A % (B % C)) == ((A & B) % C)) << std::endl;
            }
        }
    }
    //works as expected and is a tautology
    
    return 0;
}


