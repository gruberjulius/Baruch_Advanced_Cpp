#include <stack>
#include <iostream>

// max: leaves biggest value on the stack
void max(std::stack<int>& stack) {
    // setting the first value to be the max (for now)
    int max_val = stack.top() ;
    stack.pop();
    //remove all non-max values
    while (!stack.empty()) {
        if (max_val > stack.top()) {
            stack.pop();
        } else {
            max_val = stack.top();
            stack.pop();
        }
    }
    //putting the max value back on
    stack.push(max_val);
}

// min: leaves smallest value on stack
void min(std::stack<int>& stack) {
    // setting the first value to be the min (for now)
    int min_val{ stack.top() };
    stack.pop();
    // removing all non-minimal other values of the stack
    while (!stack.empty()) {
        if (min_val < stack.top()) {
            stack.pop();
        } else {
            min_val = stack.top();
            stack.pop();
        }
    }
    // putting the min back on the stack
    stack.push(min_val);
}

// over: duplicates the second stack value on top of the stack
void over(std::stack<int>& stack) {
    // getting top value
    int top = stack.top();
    //pop the top elementsj 
    stack.pop();
    // getting second value
    int second =  stack.top() ;
    // pushing elements on the top again
    stack.push(top);
    stack.push(second);
}

// rot: rotate the stack's third data value to the top of the stack
void rot(std::stack<int>& stack) {
    // getting top value
    int top = stack.top();
    //pop the value 
    stack.pop();
    // getting second value
    int second = stack.top();
    //pop stack
    stack.pop();
    // getting third value
    int third{ stack.top() };
    stack.pop();

    // repushing first and second and third in the other order
    stack.push(second);
    stack.push(top);
    stack.push(third);
}

// swap: interchange the top two values on the stack
void swap(std::stack<int>& stack) {
    // getting top value
    int top{ stack.top() };
    stack.pop();
    // getting second value
    int second{ stack.top() };
    stack.pop();
    // repushing first and second in the other order
    stack.push(top);
    stack.push(second);
}

//drop the first element
void drop(std::stack<int>& stack) {
    //remove first element
    stack.pop();
}

void print(const std::stack<int>& stack) {
    //print the stack
    auto copy{ stack };
    std::cout << "{";
    while (!copy.empty()) {
        std::cout << copy.top() << ", ";
        copy.pop();
    }
    std::cout << "}" << std::endl;
}

std::stack<int> create_stack() {
    std::stack<int> new_stack;
    for (int i =  6 ; i > 0; --i) {
        new_stack.push(i);
    }
    return new_stack;
}

int main() {
    auto stack = create_stack();
    print(stack);

    max(stack);
    print(stack);

    stack = create_stack();
    min(stack);
    print(stack);

    stack = create_stack();
    over(stack);
    print(stack);

   	stack = create_stack();
	rot(stack);
	print(stack);

	stack = create_stack();
	swap(stack);
	print(stack);

	stack = create_stack();
	drop(stack);
	print(stack);
    //Stack works as expected
}
