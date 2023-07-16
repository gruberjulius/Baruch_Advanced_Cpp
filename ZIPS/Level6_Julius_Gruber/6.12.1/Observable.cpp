#include "Observable.h"

//function to add an observer
void Observable::AddObserver(Observable* observer) {
	_observers_list.push_back(observer);
}

//function to delete one oberserver
void Observable::DeleteObserver(Observable* observer) {
	_observers_list.remove(observer);
}

//function to notfiy one observer
void Observable::NotifyObservers() {
	for (auto observer : _observers_list) {
		observer->Update(this);
		observer->NotifyObservers();
	};
}
