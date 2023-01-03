#include <unordered_set>
#include <iostream>
#include "../lib/linkedlist.h"

ListNode* detectLoop(linkedlist list) {
    unordered_set<int> history;
    ListNode* curr = list.head;
    while(curr != nullptr) {
        if (history.find(curr->val) != history.end()) {
            return curr;
        }
        history.insert(curr->val);
        curr = curr->next;
    }
    return nullptr;
}

int main() {
    linkedlist list = linkedlist::from_vector({1, 2, 3, 4, 5, 3});
    std::cout << detectLoop(list)->val;
    return 0;
}