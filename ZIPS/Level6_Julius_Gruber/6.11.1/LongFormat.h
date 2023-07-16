#pragma once
#include "Observer.h"

// forward declaration to avoid circular imports
class Counter;

class LongFormat :
    public Observer
{
private:
    Counter* _counter;

public:
    // initialize with pointer
    LongFormat(Counter* pt);


    // override update method from abstract class
    virtual void Update(Subject* subject);
};

