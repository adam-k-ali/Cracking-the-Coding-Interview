#include "../lib/LinkedList.h"
#include <iostream>
using namespace std;

bool palindrome(LinkedList list) {
    LinkedList reversed = list;
    reversed.reverse();
    return list == reversed;
}

int main() {
    LinkedList list = LinkedList::from_vector({1,2,3,4,5});
    cout << palindrome(list) << endl;
    list = LinkedList::from_vector({1,2,3,2,1});
    cout << palindrome(list) << endl;
    return 0;
}