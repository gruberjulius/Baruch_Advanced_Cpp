#include<iostream>
#include<bits/stdc++.h>

// Function maps Domain to Range
template <typename R, typename D>
using FunctionType = std::function<R (const D x)>;
// Working function type
using ScalarFunction = FunctionType<double, double>;

template <typename R, typename D>
FunctionType<R,D> operator + (const FunctionType<R,D>& f,
const FunctionType<R,D>& g)
{
    // Addition of functions
    return [=] (const D& x)
    {
        return f(x) + g(x);
    };
}


template <typename R, typename D>
FunctionType<R,D> operator - (const FunctionType<R,D>& f,
const FunctionType<R,D>& g)
{
    // Addition of functions
    return [=] (const D& x)
    {
        return f(x) - g(x);
    };
}


template <typename R, typename D>
FunctionType<R,D> operator - (const FunctionType<R,D>& f)
{
    // Addition of functions
    return [=] (const D& x)
    {
        return - f(x) ;
    };
}

template <typename R, typename D>
FunctionType<R,D> operator * (const FunctionType<R,D>& f,
const FunctionType<R,D>& g)
{
    // Addition of functions
    return [=] (const D& x)
    {
        return f(x) * g(x);
    };
}


template <typename R, typename D>
FunctionType<R,D> operator / (const FunctionType<R,D>& f,
const FunctionType<R,D>& g)
{
    // Addition of functions
    return [=] (const D& x)
    {
        return f(x) /  g(x);
    };
}

template <typename R, typename D , typename T>
FunctionType<R,D> operator * (T t,
const FunctionType<R,D>& g)
{
    // Addition of functions
    return [=] (const D& x)
    {
        return t *   g(x);
    };
}



template <typename R, typename D>
FunctionType<R,D> operator << (const FunctionType<R,D>& f,
const FunctionType<R,D>& g)
{
    // Addition of functions
    return [=] (const D& x)
    {
        return f(   g(x));
    };
}

template <typename R, typename D>
FunctionType<R,D> exp(const FunctionType<R,D>& f)
{
    // The exponential function
    return [=](const D& x)
    {
         return std::exp(f(x));
    };
}



template <typename R, typename D>
FunctionType<R,D> sin(const FunctionType<R,D>& f)
{
    // The exponential function
    return [=](const D& x)
    {
         return std::sin(f(x));
    };
}

template <typename R, typename D>
FunctionType<R,D> cos(const FunctionType<R,D>& f)
{
    // The exponential function
    return [=](const D& x)
    {
         return std::cos(f(x));
    };
}

template <typename R, typename D>
FunctionType<R,D> log(const FunctionType<R,D>& f)
{
    // The exponential function
    return [=](const D& x)
    {
         return std::log(f(x));
    };
}


template <typename R, typename D>
FunctionType<R,D> abs(const FunctionType<R,D>& f)
{
    // The exponential function
    return [=](const D& x)
    {
         return std::abs(f(x));
    };
}



template <typename R, typename D>
FunctionType<R,D> sqrt(const FunctionType<R,D>& f)
{
    // The exponential function
    return [=](const D& x)
    {
         return std::sqrt(f(x));
    };
}



template <typename R, typename D>
FunctionType<R,D> min (const FunctionType<R,D>& f,
const FunctionType<R,D>& g)
{
    // Addition of functions
    return [=] (const D& x)
    {
        return min(f(x), g(x));

    };
}



template <typename R, typename D>
FunctionType<R,D> max (const FunctionType<R,D>& f,
const FunctionType<R,D>& g)
{
    // Addition of functions
    return [=] (const D& x)
    {
        return max(f(x), g(x));
    };
}


int main(){
    // Scalar functions: double to double
    ScalarFunction f = [](double x) {return x*x; };
    ScalarFunction g = [=](double x) { return x; };

    std::cout << g(2) << ", " << g(8) << "*";
    // Set I: Arithmetic functions

    double x = 5.0;
    double scale = 2.0;
//    auto fA = 2.0*(f + g);
    auto fA = f + g;
    auto fM = f - g;
    auto fD = f / g;
    auto fMul = f * g;
    auto fC = g << g << 4.0*g;// Compose
    auto fMinus = -(f + g);

    std::cout<< fA(x)<<", "<< fM(x)<<", "<< fD(x)<<", "
    << fMul(x)<<", compose: "<< fC(x)<<", "<< fMinus(x);

    auto ftmp = log(g);
    auto ftmp2 = cos(f);
    auto f2 = (abs(exp(g))*log(g) + sqrt(ftmp)) / ftmp2;
    std::cout << f2(x)<< std::endl;
    
    auto h1 = min(f, g);
    auto h2 = max(f, g);
    std::cout <<"min(f,g): "<< h1(2.0)<<'\n';
    std::cout <<"max(f,g): "<< h2(2.0)<<'\n';
    auto h3 = min(h1, max(2 * f, 3 * g));
    auto h4 = max(h2, max(-2 * f, 3 * g));

    return 0;
}
