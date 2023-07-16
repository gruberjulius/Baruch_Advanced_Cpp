#include <iostream>
#include <boost/signals2/signal.hpp>

//Part A
// Slot implemented as a lambda function
auto lambdaSlot = []() {
    std::cout << "Lambda slot called" << std::endl;
};

// Slot implemented as a free function
void freeFunctionSlot() {
    std::cout << "Free function slot called" << std::endl;
}

// Slot implemented as a function object
struct FunctionObjectSlot {
    void operator()() const {
        std::cout << "Function object slot called" << std::endl;
    }
};

struct MyStruct { 
    double val;
    MyStruct(double v) { val = v; }
    void modify(double newValue) { val = newValue; std::cout << "A third slot " << val << std::endl; } 
};

int main() {
    //Part A
    boost::signals2::signal<void()> signal;

    // Connect the lambda slot
    signal.connect(lambdaSlot);

    // Connect the free function slot
    signal.connect(&freeFunctionSlot);

    // Connect the function object slot
    signal.connect(FunctionObjectSlot());

    // Emit the signal
    signal();

    // Part B

	MyStruct mystruct(1);

    //need to call a binder, as it is not an object directly
	auto modifier = boost::bind(&MyStruct::modify, &mystruct, 2);
	signal.connect(boost::ref(modifier));

    signal();
    return 0;

    // Part C

	signal.disconnect(lambdaSlot);
	signal.disconnect( &freeFunctionSlot  );
    //throws an error here
//	signal.disconnect(FunctionObjectSlot());
	signal.disconnect(boost::ref(modifier));
   	signal();

	// Part D

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

	signalA.connect(boost::ref(signalB));
	signalB.connect(boost::ref(signalC));
	signalC.connect(boost::ref(signalD));
	signalB.connect(boost::ref(slotB));
	signalC.connect(boost::ref(slotC));
	signalD.connect(boost::ref(slotD1));
	signalD.connect(boost::ref(slotD2));

	signalA();


	signalB.disconnect(boost::ref(signalC));
	signalA();
    //works without disconnecting the terminal 
}

