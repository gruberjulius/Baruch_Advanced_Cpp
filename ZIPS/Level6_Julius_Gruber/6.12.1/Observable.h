#pragma once

#include <list>

class Observable
{
protected:

	//list of dependent variables
	std::list<Observable*> _observers_list;

public:
	virtual void AddObserver(Observable* observer);

	virtual void DeleteObserver(Observable* observer);

	virtual void NotifyObservers();

	virtual void Update(Observable* observer) = 0;

};

