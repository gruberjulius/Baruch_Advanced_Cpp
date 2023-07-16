#pragma once
#include "Account.h"

class RealAccount: public Account
{
private:
    double balance;

public:
    RealAccount();
    RealAccount(double initial_amount);
    void Withdraw(double amount);

    double GetBalance();
};
