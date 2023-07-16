#pragma once
#include "Exception.h"

class Account
{
public:
    Account(){};

    virtual void Withdraw(double amount) = 0;
    double GetBalance(){return 0;};
};
