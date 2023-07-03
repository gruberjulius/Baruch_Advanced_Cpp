#pragma once
#include <functional>
#include <iostream>

template <typename T, int N>
class Vector {
private:
    T data[N];

public:
    Vector(){};  // default
   
    //value constructor
    Vector(T arr[]) {
    for (int i = 0; i < N; i++) {
            data[i] = arr[i];
        };
    };  
    
    //value constructor
    Vector(std::initializer_list<T> arr) {
        for (int i = 0; i < N; i++) {
            data[i] = arr[i];
        };
    };  
    //copy constructor
    Vector(Vector& v) {
        for (int i = 0; i < N; i++) {
            data[i] = v.data[i];
        };
    }               

    T& operator[](int pos) { return this->data[pos]; };  // accessing elements

    // addition
    Vector operator+(Vector& v) {

        Vector v_out(v);
        for (int i = 0; i < N; i++) {
            v_out.data[i] = v.data[i] + this->data[i];
        };
        return v_out;
    }     

    // subtraction
    Vector operator-(Vector& v) {
        Vector v_out(this->data);
        for (int i =0; i < N; i++) {
            v_out[i] -= v[i];
        }
        return v_out;
    }  

    // unary minus
    Vector operator-() {
        for (T el : this->data) {
            el = -el;
        };
    }  

    // scalar multiplication
    Vector operator*(int i) {
        Vector<T, N> v_out;
        for (T el : v_out.data) {
            el = i * el;
        };
        return v_out;
    };  

    void print() {
        for (T el : this->data) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }

    // Part d
    template <typename F>
    Vector<T, N> friend operator*(const F& a, const Vector<T, N>& pt) {
        Vector<T, N> v_out;
        for (int i = 0; i < N; i++) {
            v_out[i] = pt.data[i] * a;
        };
        return v_out;
    };

    // Part E: modifying elements of vector
    void modify(const std::function<T(T&)>& f) {
        for (T& el : this->data) {
            el = f(el);
        }
    };
};

