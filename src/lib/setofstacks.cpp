//
// Created by Adam Ali on 03/01/2023.
//

#include "setofstacks.h"

void setofstacks::push(int i) {
    if (stacks.empty() || stacks.back().size() == max_size) {
        // Add new stack to end of vector
        stacks.push_back(stack());
    }
    stacks.back().push(i);
}

int setofstacks::pop() {
    if (stacks.empty()) {
        std::cout << "Stack is empty" << std::endl;
        throw std::runtime_error("Stack is empty");
    }

    int val = stacks.back().pop();
    if (stacks.back().empty()) {
        // Remove the last stack
        stacks.pop_back();
    }
    return val;
}

int setofstacks::popAt(int index) {
    if (index >= stacks.size()) {
        std::cout << "Index out of bounds" << std::endl;
        throw std::runtime_error("Index out of bounds");
    }

    int val = stacks[index].pop();
    if (stacks[index].empty()) {
        // Remove empty stack
        stacks.erase(stacks.begin() + index);
    }
    return val;
}

int setofstacks::peek() {
    if (stacks.empty()) {
        std::cout << "Stack is empty" << std::endl;
        throw std::runtime_error("Stack is empty");
    }

    return stacks.back().peek()->val;
}

int setofstacks::min() {
    if (stacks.empty()) {
        std::cout << "Stack is empty" << std::endl;
        throw std::runtime_error("Stack is empty");
    }

    return stacks.back().min();
}

size_t setofstacks::size() {
    size_t size = 0;
    for (stack s : stacks) {
        size += s.size();
    }
    return size;
}

bool setofstacks::empty() {
    return stacks.empty();
}

void setofstacks::print(bool debug) {
    for (stack s : stacks) {
        s.print(debug);
    }
}