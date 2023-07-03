#include <iostream>
#include <array>
#include <functional>
#include <algorithm>

template <typename T, int N>
class Vector
{
	// Part A, B, C
	// constructors, access, operations
	using data_type = std::array<T, N>;
private:
	// choosing std::array for data
	data_type data{ 0 };

public:
	// default
    Vector() {};

    //constructor with value
	Vector(data_type input) {
		for (int i = 0; i < N; ++i) {
			data[i] = input[i];
		};
	};

    //constructor with copy constructor
	Vector(const Vector& copy) {
		for (int i = 0; i < N; ++i) {
			data[i] = copy.data[i];
		};
	}

	// accessing elements
	T& operator[](int idx) { 
        return this->data[idx]; 
    };

	// addition of vectors
	Vector operator+ ( const Vector& vec) {
		Vector res(this->data);
		for (int i = 0; i < N; ++i) {
			res[i] += vec.data[i];
		};
		return res;
	};

	// unary minus for a vector
	Vector operator-() {
		Vector res(this->data);
		for (int i = 0; i < N; ++i) {
			res[i] -= 1;
		};
		return res;
	};

	// substraction of two vectors
	Vector operator-(const Vector& vec) {
		Vector res(this->data);
		for (int i = 0; i < N; ++i) {
			res[i] -= vec.data[i];
		};
		return res;
	};

	// scalar multiplication of a vector with a scalar
	Vector operator*(T coeff) {
		Vector res(this->data);
		for (int i = 0; i < N; ++i) {
			res[i] *= coeff;
		};
		return res;
	};

	// printing vector: declared as friend 
	friend std::ostream& operator<<(std::ostream& out, const Vector& vec) {
		out << "[ ";
		for (T elem : vec.data) { 
            std::cout << elem << " "; 
        }
		out << "]";
		return out;
	};

	// Part d

    //enable multiplication with different data types
	template <typename F>
	friend Vector operator* (const F& a, const Vector& pt) {
		Vector<T, N> res(pt.data);
		for (int i = 0; i < N; ++i) {
            //need to convert with different datatype
			res[i] *= a;
		};
		return res;
	};

	// Part e

	// function that modifies the vector
	void modify(const std::function < T(T&)>& f) {
		for (auto& elem : this->data) { 
            elem = f(elem); 
        };
	};

	// getting begin and last of vector
	auto begin() const { return data.begin(); };
	auto end() const { return data.end(); };

};
