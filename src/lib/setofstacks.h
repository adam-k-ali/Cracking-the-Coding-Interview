//
// Created by Adam Ali on 03/01/2023.
//

#ifndef CRACKINGTHECODINGINTERVIEW_SETOFSTACKS_H
#define CRACKINGTHECODINGINTERVIEW_SETOFSTACKS_H

#include "stack.h"
#include <vector>
#include <stddef.h>

class setofstacks {
private:
    std::vector<stack> stacks;
    size_t max_size;
public:
    setofstacks(size_t max_size) : max_size(max_size) {}

    void push(int i);
    int pop();
    int popAt(int index);
    int peek();
    int min();
    size_t size();

    bool empty();
    void print(bool debug = false);
};



#endif //CRACKINGTHECODINGINTERVIEW_SETOFSTACKS_H
