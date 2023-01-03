#include "../lib/linkedlist.h"

linkedlist partition(linkedlist list, int x) {
    linkedlist left;
    linkedlist right;

    ListNode* curr = list.head;
    while (curr != nullptr) {
        if (curr->val < x) {
            left.append(curr->val);
        } else {
            right.append(curr->val);
        }
        curr = curr->next;
    }

    left.concat(right);

    return left;
}

int main() {
    linkedlist list = linkedlist::from_vector({3, 5, 8, 5, 10, 2, 1});
    list = partition(list, 5);
    list.print();
}