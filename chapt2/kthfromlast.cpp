//
// Created by Adam Ali on 25/12/2022.
//
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

size_t list_size(ListNode* head) {
    if (head == NULL) {
        return 0;
    }

    int count = 1;
    ListNode* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
        count++;
    }
    return count;
}

ListNode* list_from_vector(vector<int> v) {
    if (v.size() == 0) {
        return nullptr;
    }

    ListNode* head = new ListNode(v[0]);
    ListNode* curr = head;
    for (int i = 1; i < v.size(); i++) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }

    return head;
}

void print_list(ListNode* head) {
    printf("[");
    ListNode* curr = head;
    while (curr != NULL) {
        printf("%d,", curr->val);
        curr = curr->next;
    }
    printf("]");
}

int kthFromLast(ListNode* head, int k) {
    int n = list_size(head) - 1;
    int i = 0;

    ListNode* curr = head;
    while (n - i > k) {
        curr = curr->next;
        i++;
    }
    return curr->val;
}

int main() {
    ListNode* head = list_from_vector({1,2,3,4,5});
    for (int i = 0; i < 5; i++) {
        cout << kthFromLast(head, i) << endl;
    }
}