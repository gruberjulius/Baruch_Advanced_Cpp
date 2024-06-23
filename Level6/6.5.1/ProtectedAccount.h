#pragma once
#include "Account.h"
#include "RealAccount.h"
#include <string>

//protected account class
class ProtectedAccount: public Account
{
private:
    double balance;
    std::string pwd;
    RealAccount acc; //including a real account here 
public:

    ProtectedAccount(double initial_amount, std::string password);

    void Withdraw(double amount);
    double GetBalance(std::string password);
};
