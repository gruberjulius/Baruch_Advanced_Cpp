#pragma once

#include <array>
#include <functional>
#include <iostream>

template <typename T, int NR, int NC>
class Matrix {
private:
    std::array<std::array<T, NC>, NR> data;

public:
    Matrix() : data({}) {}

    Matrix(T value) : data({}) {
        for (std::array<T, NC>& row : data) {
            row.fill(value);
        }
    }

    Matrix(const Matrix& copy) : data(copy.data) {}

    std::array<T, NC>& operator[](int row) {
        return data[row];
    }

    Matrix operator+(const Matrix& m) const {
        Matrix res;
        for (int i = 0; i < NR; ++i) {
            for (int j = 0; j < NC; ++j) {
                res[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return res;
    }

    Matrix operator-(const Matrix& m) const {
        Matrix res;
        for (int i = 0; i < NR; ++i) {
            for (int j = 0; j < NC; ++j) {
                res[i][j] = data[i][j] - m.data[i][j];
            }
        }
        return res;
    }

    Matrix operator*(const T coeff) const {
        Matrix res;
        for (int i = 0; i < NR; ++i) {
            for (int j = 0; j < NC; ++j) {
                res[i][j] = data[i][j] * coeff;
            }
        }
        return res;
    }

    template <typename F>
    friend Matrix operator*(const F& a, const Matrix& pt) {
        Matrix res;
        for (int i = 0; i < NR; ++i) {
            for (int j = 0; j < NC; ++j) {
                res[i][j] = pt.data[i][j] * a;
            }
        }
        return res;
    }

    void modify(const std::function<T(T&)>& f) {
        for (std::array<T, NC>& row : data) {
            for (T& elem : row) {
                elem = f(elem);
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
        out << "[";
        for (int i = 0; i < NR; ++i) {
            if (i != 0) {
                out << " ";
            }
            out << "[ ";
            for (int j = 0; j < NC; ++j) {
                out << matrix.data[i][j] << " ";
            }
            out << "]";
            if (i != NR - 1) {
                out << std::endl;
            }
        }
        out << "]";
        return out;
    }
};

