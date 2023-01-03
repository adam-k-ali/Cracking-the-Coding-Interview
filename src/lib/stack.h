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
    // Constructor
    stack() : top(nullptr), stack_size(0) {}
    // Copy constructor
    stack(const stack& other) {
        StackNode* other_top = other.top;
        StackNode* new_top = nullptr;
        StackNode* new_node = nullptr;
        while (other_top != nullptr) {
            new_node = new StackNode(other_top->val, other_top->local_min);
            new_node->next = new_top;
            new_top = new_node;
            other_top = other_top->next;
        }
        top = new_top;
        stack_size = other.stack_size;
    }
    // Constructor from vector
    stack(std::vector<int> v) : top(nullptr), stack_size(0) {
        for (int i = 0; i < v.size(); i++) {
            push(v[i]);
        }
    }

    // Destructor
    ~stack() {
        while (top != nullptr) {
            StackNode* newTop = top->next;
            delete top;
            top = newTop;
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
