//
// Created by Adam Ali on 28/12/2022.
//

#ifndef CRACKINGTHECODINGINTERVIEW_STACK_H
#define CRACKINGTHECODINGINTERVIEW_STACK_H

#include <iostream>
#include <vector>

struct StackNode {
    int val;
    int local_min;
    StackNode *next;

    explicit StackNode(int val) : val(val), local_min(val), next(nullptr) {}
    explicit StackNode(int val, int min) : val(val), local_min(min), next(nullptr) {}
};

class stack {
private:
    StackNode* top;
    size_t stack_size;

public:
    stack() : top(nullptr), stack_size(0) {}
    stack(StackNode* top) : top(top), stack_size(0) {}
    stack(std::vector<int> v) : top(nullptr), stack_size(0) {
        for (int i = 0; i < v.size(); i++) {
            push(v[i]);
        }
    }

    void push(int i);
    int pop();
    StackNode* peek();
    int min();
    size_t size();

    bool empty();
    void print(bool debug = false);
};


#endif //CRACKINGTHECODINGINTERVIEW_STACK_H
