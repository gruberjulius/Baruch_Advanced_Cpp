#pragma once
#include <algorithm>

class OptionData
{
public:
    //public values so they are more reachable
    double K;
    double T;
    double r;
    double sig;
    double D;
    int type;
    // default constructor
    OptionData(): K(0.0), T(0.0), r(0.0), sig(0.0), D(0.0), type(0){};

    OptionData(double strike, double maturity, double interestRate, double volatility, double dividend, int optionType)
        : K(strike), T(maturity), r(interestRate), sig(volatility), D(dividend), type(optionType)
    {}

    //defintion for stockPrice, -1 for put, 1 for call
    double myPayOffFunction(double stockPrice)
    {
        if (type == -1) 
        {
            return std::max(K - stockPrice, 0.0);
        }
        else 
        {
            return std::max(stockPrice - K, 0.0);
        }
    }


};


