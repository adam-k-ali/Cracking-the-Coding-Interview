//
// Created by Adam Ali on 28/12/2022.
//

#include "stack.h"
#include <iostream>
#include <math.h>

void stack::push(int i) {
    int min_val = std::min(i, min());
    // Update top of stack
    StackNode* newTop = new StackNode(i, min_val);
    newTop->next = top;
    top = newTop;
    stack_size++;
}

int stack::pop() {
    // Check if stack is empty
    if (top == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        throw std::runtime_error("Stack is empty");
    }

    int val = top->val;
    // Update top of stack
    StackNode *newTop = top->next;
    delete top;
    top = newTop;
    stack_size--;
    return val;

}

StackNode* stack::peek() {
    if (top == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        throw std::runtime_error("Stack is empty");
    }

    return top;
}

int stack::min() {
    if (empty()) {
        std::cout << "Stack is empty" << std::endl;
        return std::numeric_limits<int>::max();
    }

    return peek()->local_min;

}
size_t stack::size() {
    return stack_size;
}

bool stack::empty() {
    return top == nullptr;
}

void stack::print(bool debug) {
    if (debug) {
        std::cout << "Stack size: " << size() << std::endl;
        // Print table header
        std::cout << "Top\tMin" << std::endl;
        StackNode* curr = top;
        while (curr != nullptr) {
            std::cout << curr->val << "\t" << curr->local_min << std::endl;
            curr = curr->next;
        }
    } else {
        StackNode *curr = top;
        while (curr != nullptr) {
            std::cout << curr->val;
            if (curr->next != nullptr) {
                std::cout << " -> ";
            }
            curr = curr->next;
        }
    }
    std::cout << std::endl;
}