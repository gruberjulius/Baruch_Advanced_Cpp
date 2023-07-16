#include <boost/signals2.hpp>
#include <iostream>
#include <boost/functional.hpp>


int main() {

	// Code from last exercise

	// Define potential emitters
	boost::signals2::signal<void()> signalA;
	boost::signals2::signal<void()> signalB;
	boost::signals2::signal<void()> signalC;
	boost::signals2::signal<void()> signalD;

	// Define slots
	auto slotB = []() {std::cout << "Slot B called by B\n " << std::endl; };
	auto slotC = []() {std::cout << "Slot C called by C\n " << std::endl; };
	auto slotD1 = []() {std::cout << "Slot D1 called by D\n " << std::endl; };
	auto slotD2 = []() {std::cout << "Slot D2 called by D\n " << std::endl; };

	signalA.connect(0, boost::ref(signalB));
	signalB.connect(1, boost::ref(signalC));
	signalC.connect(2, boost::ref(signalD));
	signalB.connect(3, boost::ref(slotB));
	signalC.connect(4, boost::ref(slotC));
	signalD.connect(5, boost::ref(slotD1));
	signalD.connect(6, boost::ref(slotD2));

	signalA();
    //runs slot for furthers signal

	signalB.disconnect(boost::ref(signalC));
	signalA();
    //nothing changed
}
