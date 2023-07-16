
#include <boost/signals2.hpp>
#include <iostream>

struct BootstrapCheck

{
    //iterate through the slots and return first false
    typedef bool result_type;
    template <typename InputIterator>
    bool operator()(InputIterator first, InputIterator last) const
    {
        while (first != last)
        {
            if (!*first)
                return false;
           ++first;
        }
        return true;
    }
};


int main() {

    boost::signals2::signal<bool(), BootstrapCheck> sig;

    // Part B

    auto slot1 = []() {std::cout << "slot1" << std::endl; return true; };
    auto slot2 = []() {std::cout << "slot2" << std::endl; return false; };
    auto slot3 = []() {std::cout << "slot3" << std::endl; return true; };

    // Part C

    sig.connect(boost::ref(slot1));
    sig.connect(boost::ref(slot2));
    sig.connect(boost::ref(slot3));

    sig();
    //iteration stopped after second slot as expected
    return 0;
}
