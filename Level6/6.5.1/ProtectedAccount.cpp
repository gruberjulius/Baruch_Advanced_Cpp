#include "ProtectedAccount.h"
#include "NoAccessException.h"

ProtectedAccount::ProtectedAccount(double initial_amount, std::string password)
{
    balance = initial_amount;
    pwd =  password;
    acc = RealAccount(initial_amount); constructor with inital amount 
};

void ProtectedAccount::Withdraw(double amount)
{
    acc.Withdraw(amount);
}

double ProtectedAccount::GetBalance(std::string password)
{
    if (pwd != password){
        throw NoAccessException();
    }
    double balance = acc.GetBalance(); // get Balance from real account
    return balance;
}
