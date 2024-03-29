#pragma once

#include "Observer.h"

// forward declaration to avoid circular imports
class Counter;

class DoubleFormat :
    public Observer
{
private:
    Counter* _counter;

public:
    // initialize with pointer
    DoubleFormat(Counter* pt);


    // override update method from abstract class
    virtual void Update(Subject* subject);
};

