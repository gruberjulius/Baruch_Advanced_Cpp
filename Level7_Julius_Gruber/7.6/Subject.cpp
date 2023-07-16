#include "Subject.h"
#include "Observer.h"

// virtual function to add an observer
void Subject::Attach(Observer* observer) {
	observers.push_back(observer);
}

// virtual function to remove an observer
void Subject::Detach(Observer* observer) {
	observers.remove(observer);
}

// virtual function to notify observers
void Subject::Notify() {
	for (auto observer : observers) {
		observer->Update(this);
	}
}
