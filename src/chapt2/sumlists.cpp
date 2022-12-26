#include "../lib/LinkedList.h"

LinkedList sum(LinkedList a, LinkedList b, bool reverse_order = true) {
    if (!reverse_order) {
        a.reverse();
        b.reverse();
    }
    ListNode* l1 = a.head;
    ListNode* l2 = b.head;
    LinkedList result;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr) {
        int a = 0;
        if (l1 != nullptr) {
            a = l1->val;
            l1 = l1->next;
        }

        int b = 0;
        if (l2 != nullptr) {
            b = l2->val;
            l2 = l2->next;
        }

        int sum = a + b + carry;
        carry = sum / 10;
        result.append(sum % 10);
    }
    if (carry > 0) {
        result.append(carry);
    }
    if (!reverse_order) {
        result.reverse();
    }
    return result;
}

int main() {
    LinkedList a = LinkedList::from_vector({7, 1, 6});
    LinkedList b = LinkedList::from_vector({5, 9, 2});
    LinkedList result = sum(a, b);
    result.print();

    a = LinkedList::from_vector({6, 1, 7});
    b = LinkedList::from_vector({2, 9, 5});
    result = sum(a, b, false);
    result.print();
    return 0;
}