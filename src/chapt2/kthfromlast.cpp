//
// Created by Adam Ali on 25/12/2022.
//
#include <iostream>
#include <vector>
#include "../lib/LinkedList.h"

using namespace std;

int main() {
    LinkedList list = LinkedList::from_vector({1,2,3,4,5});
    for (int i = 0; i < 5; i++) {
        cout << list.kthFromLast(i) << endl;
    }
    return 0;
}