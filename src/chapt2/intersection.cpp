#include "../lib/LinkedList.h"
#include <iostream>

using namespace std;

int main() {
    LinkedList list = LinkedList::from_vector({1,2,3,4,5});
    LinkedList list2 = LinkedList::from_vector({1,2,3,4,5});
    cout << list.intersect(list2) << endl;

    list.head->next = list2.head->next->next;
    cout << list.intersect(list2) << endl;

    return 0;
}