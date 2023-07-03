#include <array>
#include <functional>
#include <iostream>

template <typename T, int NR, int NC>
class Matrix
{
	using NestedMatrix = std::array<std::array<T, NC>, NR>;

private:
	NestedMatrix data;

public:

    //default constructor
	Matrix() {
		for (std::array<T, NC>& row : data) {
			for (T& elem : row) {
				elem = 0;
			}
		}
	};

	// value constructor 
	Matrix(T value) {
		for (std::array<T, NC>& row : data) {
			for (T& elem : row) {
				elem = value;
			}
		}
	}

	// copy constructor (all the values everywhere)
	Matrix(const Matrix& copy) {
		for (int i{ 0 }; i < NR; ++i) {
			for (int j{ 0 }; j < NC; ++j) {
				this->data[i][j] = copy.data[i][j];
			}
		}
	}

    //operator to access rows
	std::array<T, NC>& operator[](int row) {
		return this->data[row];
	};

	// addition of two matrices
	Matrix operator+(const Matrix& m) {
		Matrix res(m);
		for (int i{ 0 }; i < NR; ++i) {
			for (int j{ 0 }; j < NC; ++j) {
				res[i][j] = this->data[i][j] + m.data[i][j];
			};
		};
		return res;
	};

	// substraction
	Matrix operator-(const Matrix& m) {
		Matrix res(m);
		for (int i{ 0 }; i < NR; ++i) {
			for (int j{ 0 }; j < NC; ++j) {
				res.data[i][j] -= this->data[i][j] - m.data[i][j];
			};
		};
		return res;
	};


	// scalar multiplication
	Matrix operator*(const T coeff) {
		Matrix<T, NR, NC> res;
		for (int i{ 0 }; i < NR; ++i) {
			for (int j{ 0 }; j < NC; ++j) {
				res.data[i][j] = this->data[i][j] * coeff;
			}
		};
		return res;
	};


	// scalar multiplication with any type
	template <typename F>
	friend Matrix operator* (const F& a, const Matrix& pt) {
		Matrix<T, NR, NC> res;
		for (int i{ 0 }; i < NR; ++i) {
			for (int j{ 0 }; j < NC; ++j) {
				res.data[i][j] = pt.data[i][j] * a;
			}
		};
		return res;
	};

	// function that modifies the matrix
	void modify(const std::function < T(T&)>& f) {
		for (std::array<T, NC>& row : data) {
			for (T& elem : row) {
				elem = f(elem);
			}
		}
	};

	// function to print the matrix
	friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
		out << "[";
		for (int i{ 0 }; i < NR; ++i) {
			if (i != 0) { out << " "; };
			out << "[ ";
			for (int j{ 0 }; j < NC; ++j) {
				std::cout << matrix.data[i][j] << " ";
			}
			out << "]";
			if (i != NR - 1) { out << std::endl; };
		}
		out << "]";
		return out;
	};

};
