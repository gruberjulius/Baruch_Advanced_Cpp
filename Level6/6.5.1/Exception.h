#pragma once
#include <string>

//expception base class
class Exception
{
public:
    Exception(){};
    virtual std::string what(){return "";};
};
