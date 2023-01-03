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


class linkedlist {
private:
    void copy_list(ListNode* other_head);
public:
    ListNode* head;

    linkedlist() : head(nullptr) {}
    linkedlist(ListNode* head) : head(head) {}
    // Copy constructor
    linkedlist(const linkedlist& other) {
        copy_list(other.head);
    }

    static linkedlist from_vector(vector<int> v);

    void append(int i);
    void append_node(ListNode* node);
    ListNode* intersect(const linkedlist &other) const;
    void reverse();
    int kthFromLast(int k);
    bool delete_node(ListNode* node);
    void concat(linkedlist other);

    size_t size();
    bool empty();

    void print();

    bool operator==(const linkedlist& other) const;
};


#endif //CRACKING_THE_CODING_INTERVIEW_LIST_H
