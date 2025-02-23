#include "stack.h"
#include <iostream>
using namespace std;

// Constructor
Stack::Stack() {
    count = 0;
}

bool Stack::empty() const {
    return count == 0;
}

// pop the first item of stack
Error_code Stack::pop() {
    Error_code outcome = success;
    if (count == 0)
        outcome = underflow;
    else --count;
    return outcome;
}

// Fetch the first item of stack
Error_code Stack::top(double &item) const {
    Error_code outcome = success;
    if (count == 0)
        outcome = underflow;
    else
        item = entry[count - 1];
    return outcome;
}

// Push to the stack
Error_code Stack::push(const double &item) {
    Error_code outcome = success;
    if (count >= maxstack)
        outcome = overflow;
    else
        entry[count++] = item;
    return outcome;
}

// Print the stack
Error_code Stack::print() const {
    Error_code outcome = success;

    Stack temp_stack = *this;

    if (count == 0) {
        outcome = underflow;
    } else {

        for (int i = 0; i < count; i++) {
            double item;
            temp_stack.top(item);
            cout << item << endl;
            temp_stack.pop();
        }

    }

    return outcome;

}

// Clear the stack
Error_code Stack::clear() {
    Error_code outcome = success;

        while (count > 0) {
            pop();
        }

    return outcome;

}


int Stack::length() {

    return count;

}