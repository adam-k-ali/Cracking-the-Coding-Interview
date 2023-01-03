#include "../lib/linkedlist.h"
#include <iostream>
using namespace std;

bool palindrome(linkedlist list) {
    linkedlist reversed = list;
    reversed.reverse();
    return list == reversed;
}

int main() {
    linkedlist list = linkedlist::from_vector({1, 2, 3, 4, 5});
    cout << palindrome(list) << endl;
    list = linkedlist::from_vector({1, 2, 3, 2, 1});
    cout << palindrome(list) << endl;
    return 0;
}