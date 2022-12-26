#include "../lib/LinkedList.h"

LinkedList partition(LinkedList list, int x) {
    LinkedList left;
    LinkedList right;

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
    LinkedList list = LinkedList::from_vector({3, 5, 8, 5, 10, 2, 1});
    list = partition(list, 5);
    list.print();
}