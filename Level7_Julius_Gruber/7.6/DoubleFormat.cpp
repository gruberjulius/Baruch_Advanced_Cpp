#include "DoubleFormat.h"

#include "Counter.h"

// initialize with pointer
DoubleFormat::DoubleFormat(Counter* pt) :
    _counter{ pt } {
        _counter->Attach(this);
};


// override update method from abstract class
void DoubleFormat::Update(Subject* subject) {
    std::cout << "counter " << subject << " in double format : " << static_cast<double>(_counter->GetCounter()) << std::endl;
}
