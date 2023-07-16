#include <iostream>
#include <string>

class Mediator;

class InputModule {
public:
    InputModule(Mediator* mediator) : mediator(mediator) {}

    void getUserInput();

private:
    Mediator* mediator;
};

class ProcessingModule {
public:
    ProcessingModule(Mediator* mediator) : mediator(mediator) {}

    void processInput(const std::string& itemName, int quantity);

private:
    Mediator* mediator;
};

class OutputModule {
public:
    OutputModule(Mediator* mediator) : mediator(mediator) {}

    void displayOutput(int totalPrice);

private:
    Mediator* mediator;
};

class Mediator {
public:
    Mediator() {
        inputModule = new InputModule(this);
        processingModule = new ProcessingModule(this);
        outputModule = new OutputModule(this);
    }

    ~Mediator() {
        delete inputModule;
        delete processingModule;
        delete outputModule;
    }

    void notify(const std::string& event, const std::string& itemName, int quantity);

    void run() {
        inputModule->getUserInput();
    }

private:
    InputModule* inputModule;
    ProcessingModule* processingModule;
    OutputModule* outputModule;
};

void InputModule::getUserInput() {
    std::string itemName;
    int quantity;

    std::cout << "Enter item name: ";
    std::cin >> itemName;

    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    mediator->notify("input", itemName, quantity);
}

void ProcessingModule::processInput(const std::string& itemName, int quantity) {
    // Perform processing logic
    int totalPrice = quantity * 10; // Assume each item costs $10
    mediator->notify("process", itemName, totalPrice);
}

void OutputModule::displayOutput(int totalPrice) {
    std::cout << "Total price: $" << totalPrice << std::endl;
}

void Mediator::notify(const std::string& event, const std::string& itemName, int quantity) {
    if (event == "input") {
        processingModule->processInput(itemName, quantity);
    }
    else if (event == "process") {
        outputModule->displayOutput(quantity);
    }
}

int main() {
    Mediator mediator;
    mediator.run();

    return 0;
}

