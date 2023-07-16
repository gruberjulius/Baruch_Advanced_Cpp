#pragma once
#include "OptionData.hpp"

// SDE abstract base class, implemented the standard in SDEstd
class SDE
{
public:
    virtual double drift(double x, double V) const = 0;
    virtual double diffusion(double x, double V) const = 0;
    
    // adding jump diffusion
    virtual double jump(double x, double V) const = 0; 
};
