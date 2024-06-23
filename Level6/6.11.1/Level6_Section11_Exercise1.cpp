#include "Counter.h"
#include "LongFormat.h"
#include "DoubleFormat.h"

#include <iostream>

int main() {

	// Part D
	Counter* counter{ new Counter() };
	
	// Part L
	
	LongFormat double_obs(counter);
	DoubleFormat long_obs(counter);

	counter->IncreaseCounter();
	counter->IncreaseCounter();
	counter->DecreaseCounter();
	counter->IncreaseCounter();
	//works but their is no increase in value when dealing with small values
}
