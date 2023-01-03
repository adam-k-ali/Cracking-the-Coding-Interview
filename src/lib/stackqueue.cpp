//
// Created by Adam Ali on 03/01/2023.
//

#include "stackqueue.h"

void stackqueue::enqueue(int i) {
    s1->push(i);
    queue_size++;
}

int stackqueue::dequeue() {
    if (empty()) {
        std::cout << "Queue is empty" << std::endl;
        throw std::runtime_error("Queue is empty");
    }
    if (s2->empty()) {
        while (!s1->empty()) {
            s2->push(s1->pop());
        }
    }
    queue_size--;
    return s2->pop();
}

size_t stackqueue::size() {
    return queue_size;
}

bool stackqueue::empty() {
    return queue_size == 0;
}