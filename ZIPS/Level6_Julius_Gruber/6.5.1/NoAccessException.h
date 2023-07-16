#pragma once
#include "Exception.h"


class NoAccessException: public Exception
{
public:

    NoAccessException(){};
    std::string what(){return "Not Correct password";};
};
