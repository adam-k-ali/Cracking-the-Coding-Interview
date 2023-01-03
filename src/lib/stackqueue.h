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
    stackqueue() : s1(new stack()), s2(new stack()), queue_size(0) {}

    void enqueue(int i);
    int dequeue();
    size_t size();
    bool empty();
};


#endif //CRACKINGTHECODINGINTERVIEW_STACKQUEUE_H
