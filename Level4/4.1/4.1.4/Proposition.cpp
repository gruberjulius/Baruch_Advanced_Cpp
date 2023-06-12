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
