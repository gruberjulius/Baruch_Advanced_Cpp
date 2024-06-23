#include <iostream>
#include "EmptyState.h"
#include "FullState.h"
#include "NotFullNotEmptyState.h"
#include "Singleton.hpp"
#include "Stack.h"
#include "StackState.h"

int main() {
    // creating a stack
    int n = 11;
    Stack stk(n);

    for (int i = 0; i < n - 1; i++) {
        stk.Push(i);  //switch to not full not empty
    }

    //try to push to the stack
    try {
        stk.Push(5);
    } catch (std::runtime_error e1) {
        std::cout << e1.what();
    }

    //initialise a new stack
    Stack stk2(0);

    // trying out push error
    try {
        stk2.Push(1);  //stack to the push 
    } catch (std::runtime_error e2) {
        //catch the error
        std::cout << e2.what();
    }

    // trying out pop error
    try {
        stk2.Pop();  // throw error because cant pop from empty stack
    } catch (std::runtime_error e4) {
        std::cout << e4.what();
    }
}

