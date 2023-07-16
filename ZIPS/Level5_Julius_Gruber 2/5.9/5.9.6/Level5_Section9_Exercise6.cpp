#include <iostream>
#include <boost/signals2.hpp>

// Slot for the Hardware layer
void hardwareSlot(double& data) {
    if (data < 2.0 || data > 4.0) {
        data = 3.0;
    }
}

// Slot for the Data layer
void dataSlot(double& data) {
    data *= 2; // Modify the data by multiplying it by 2
}

// Slot for the Communication layer
void communicationSlot(double& data) {
    std::cout << "Formatted and printed data: " << data << std::endl;
}

int main() {
    //Part A
    // Create the signals
    boost::signals2::signal<void(double&)> signalExterior;
    boost::signals2::signal<void(double&)> signalHardware;
    boost::signals2::signal<void(double&)> signalData;
    boost::signals2::signal<void(double&)> signalCommunication;

    //Part B
    // Connect the slots to the signals
    signalExterior.connect(hardwareSlot);
    signalHardware.connect(dataSlot);
    signalData.connect(communicationSlot);

    // Connect the signals to each other
    signalExterior.connect(signalHardware);
    signalHardware.connect(signalData);
    signalData.connect(signalCommunication);

    // Initialize the data in the Exterior layer
    double value = -3.7;
    signalExterior(value);

    return 0;
}

