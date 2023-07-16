#pragma once

#include "Observable.h"

class Observer
{
public:
	virtual void Update(Observable* observer) = 0;
};

