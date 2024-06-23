#include "RealAccount.h"
#include "NoFundsException.h"
#include <iostream>

// constructor
RealAccount::RealAccount(){};

//value constructor
RealAccount::RealAccount(double initial_amount)
{
    balance = initial_amount;
}

// withdraw function
void RealAccount::Withdraw(double amount)
{
    if (amount > balance) {
		throw NoFundsException();
	}
    balance -= amount;
    std::cout <<"succesfully withdrew " << amount << "$" << std::endl;
};

// get balance
double RealAccount::GetBalance()
{
    std::cout << "Your balance " << balance << "$" << std::endl;
    return balance;
};

