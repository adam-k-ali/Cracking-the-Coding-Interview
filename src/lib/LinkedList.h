//
// Created by Adam Ali on 26/12/2022.
//

#ifndef CRACKING_THE_CODING_INTERVIEW_LIST_H
#define CRACKING_THE_CODING_INTERVIEW_LIST_H

#include <vector>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class LinkedList {
private:
    void copy_list(ListNode* other_head);
public:
    ListNode* head;

    LinkedList() : head(nullptr) {}
    LinkedList(ListNode* head) : head(head) {}
    // Copy constructor
    LinkedList(const LinkedList& other) {
        copy_list(other.head);
    }

    static LinkedList from_vector(vector<int> v);

    void append(int i);
    void reverse();
    int kthFromLast(int k);
    bool delete_node(ListNode* node);
    void concat(LinkedList other);

    size_t size();
    bool empty();

    void print();

    bool operator==(const LinkedList& other) const;
};


#endif //CRACKING_THE_CODING_INTERVIEW_LIST_H
