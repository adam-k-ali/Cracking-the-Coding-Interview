//
// Created by Adam Ali on 03/01/2023.
//

#ifndef CRACKINGTHECODINGINTERVIEW_STACKQUEUE_H
#define CRACKINGTHECODINGINTERVIEW_STACKQUEUE_H

#include "stack.h"

class stackqueue {
private:
    stack* s1;
    stack* s2;
    size_t queue_size;
public:
    // Constructor
    stackqueue() : s1(new stack()), s2(new stack()), queue_size(0) {}
    // Copy constructor
    stackqueue(const stackqueue& other) {
        s1 = new stack(*other.s1);
        s2 = new stack(*other.s2);
        queue_size = other.queue_size;
    }
    // Destructor
    ~stackqueue() {
        delete s1;
        delete s2;
    }

    void enqueue(int i);
    int dequeue();
    size_t size();
    bool empty();
};


#endif //CRACKINGTHECODINGINTERVIEW_STACKQUEUE_H
