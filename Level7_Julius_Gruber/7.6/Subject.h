#pragma once

#include <list>
#include <memory>
#include <functional>

// forward declaration 
class Observer;

class Subject
{
private:
	// list of observers
	//std::list <Observer*> observers;
	//Calling the Update function from observer
	std::list<std::function<void(Subject*)>>;

public:

	// virtual function to add an observer
	virtual void Attach(Observer* observer);

	// virtual function to remove an observer
	virtual void Detach(Observer* observer);

	// virtual function to notify observers
	virtual void Notify();
};

