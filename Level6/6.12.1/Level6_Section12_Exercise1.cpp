#include "Counter.h"

#include <iostream>

int main() {

	//Create counter variables
	Counter* counter1{ new Counter() };
	Counter* counter2{ new Counter() };
	counter1->AddObserver(counter2);

	//update the counter
	counter1->Update(counter1);
	counter1->Update(counter1);

	//delete the observer
	counter1->DeleteObserver(counter2);

	//update the counter	
	counter1->Update(counter1);
	counter1->Update(counter1);
	//there is only 1 counter now
}
