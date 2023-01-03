//
// Created by Adam Ali on 25/12/2022.
//
#include <iostream>
#include <vector>
#include "../lib/linkedlist.h"


using namespace std;

void deleteDuplicates(linkedlist list) {
    if (list.size() <= 1) {
        // List is empty or only contains 1 element.
        return;
    }

    ListNode* curr = list.head;
    while(curr != nullptr) {
        ListNode* last = curr;
        ListNode* search = curr->next;

        while (search != nullptr) {
            if (search->val == curr->val) {
                // Delete graph_node
                last->next = search->next;
            } else {
                last = search;
            }
            search = search->next;

        }

        curr = curr->next;
    }
}

int main() {
    vector<int> vect{1, 2, 2, 3, 2, 4, 3};
    linkedlist list = linkedlist::from_vector(vect);
    deleteDuplicates(list);
    list.print();
}

