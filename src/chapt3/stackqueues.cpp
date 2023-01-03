//
// Created by Adam Ali on 03/01/2023.
//

#include <iostream>
#include "../lib/stackqueue.h"

int main() {
    stackqueue queue;
    for (int i = 0; i < 10; i++) {
        queue.enqueue(i);
    }
    for (int i = 0; i < 10; i++) {
        std::cout << queue.dequeue() << std::endl;
    }
    return 0;
}