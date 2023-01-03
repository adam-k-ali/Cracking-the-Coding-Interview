//
// Created by Adam Ali on 03/01/2023.
//
#include "../lib/setofstacks.h"

int main() {
    setofstacks stacks = setofstacks(3);
    for (int i = 0; i < 10; i++) {
        stacks.push(i);
    }
    stacks.print();
    stacks.popAt(1);
    stacks.print();
    stacks.pop();
    stacks.print();

    return 0;
}