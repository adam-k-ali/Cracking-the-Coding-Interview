//
// Created by Adam Ali on 03/01/2023.
//
#include "../lib/stack.h"

void stacksort(stack* s) {
    stack* temp = new stack();
    stack* in = new stack(*s);
    while (!in->empty()) {
        int val = in->pop();
        while (!temp->empty() && temp->peek()->val > val) {
            in->push(temp->pop());
        }
        temp->push(val);
    }
    *s = *temp;
}

int main() {
    stack* s = new stack({8, 1, 5, 1, 3, 9, 6, 2, 7, 4});
    s->print();
    stacksort(s);
    s->print();
    return 0;
}