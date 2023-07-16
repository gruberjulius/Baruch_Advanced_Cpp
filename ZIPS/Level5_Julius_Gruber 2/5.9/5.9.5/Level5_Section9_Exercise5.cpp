#include <boost/signals2/signal.hpp>
#include <iostream>

// Part A

using FunctionType = boost::function<void(double)>;
using SignalType = boost::signals2::signal<void(double)>;

class Subject
{
    private:
        // signal where slots will be connected
        SignalType attentionList;
    public:
        // initializing empty signal list
        Subject() { attentionList = SignalType(); }
        // adding slot to signal 
        void AddObserver(const FunctionType& ft)
        {
            attentionList.connect(ft);
        }
        // running the signal
        void ChangeEvent(double x)
        {
            attentionList(x);
        }
};

// Part B

void CPrint(double x)
{
    std::cout << "C function: " << x << std::endl;
}

struct Print{
    void operator() (double x)
    {
        std::cout << "I am a printer " << x << std::endl;
    }
};


int main() {

    // Part C

    // GIVEN CODE

    // Create the notifier
    Subject mySubject;

    // Create the attention list
    Print myPrint;

    mySubject.AddObserver(myPrint);
    mySubject.AddObserver(&CPrint);

    // Trigger the event
    std::cout << "Give the value: "; double val; std::cin >> val;
    mySubject.ChangeEvent(val);


}
