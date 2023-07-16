// Part a, b, c: implementation of exceptions
#include "NoFundsException.h"
#include "NoAccessException.h"

// Part e-i: account implementation
#include "RealAccount.h"
#include "ProtectedAccount.h"


#include <iostream>

int main() {

	RealAccount acc1{ 100 };
	std::cout << "Current balance: " << acc1.GetBalance() << std::endl;

	acc1.Withdraw(50);

	try {
		acc1.Withdraw(200);
	}
	catch (Exception& err) {
		std::cerr << err.what() << std::endl;
	};

	ProtectedAccount pacc1(100, "passwd");

	try{
		pacc1.GetBalance("false passwd");
	}
	catch (Exception& err) {
		std::cerr << err.what() << std::endl;
	};
	return 0;

}
