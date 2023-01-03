//
// Created by Adam Ali on 25/12/2022.
//
#include <iostream>
#include <vector>
#include "../lib/linkedlist.h"

using namespace std;

int main() {
    linkedlist list = linkedlist::from_vector({1, 2, 3, 4, 5, 6});
    ListNode *middleNode = list.head->next->next; // Delete '3'
    list.delete_node(middleNode);
    list.print();
    return 0;
}