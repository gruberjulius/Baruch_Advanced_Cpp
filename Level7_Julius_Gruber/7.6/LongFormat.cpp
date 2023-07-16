#include "LongFormat.h"

#include "Counter.h"

// initialize with pointer
LongFormat::LongFormat(Counter* pt) :
    _counter{ pt } {
        _counter->Attach(this);
};


// override update method from abstract class
void LongFormat::Update(Subject* subject) {
    std::cout << "counter " << subject << " in long format : " << static_cast<long>(_counter->GetCounter()) << std::endl;
}
