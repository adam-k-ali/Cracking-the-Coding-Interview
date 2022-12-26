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
public:
    ListNode* head;

    LinkedList() : head(nullptr) {}
    LinkedList(ListNode* head) : head(head) {}

    static LinkedList from_vector(vector<int> v);

    void append(int i);
    int kthFromLast(int k);
    bool delete_node(ListNode* node);

    size_t size();

    void print();
};


#endif //CRACKING_THE_CODING_INTERVIEW_LIST_H
