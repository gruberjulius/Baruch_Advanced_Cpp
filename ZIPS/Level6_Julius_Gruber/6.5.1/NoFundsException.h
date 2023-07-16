#pragma once
#include "Exception.h"

class NoFundsException: public Exception
{

public:
    NoFundsException(){};
    std::string what(){return "Not enough money";};
}; 
