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

void deleteDuplicates(ListNode* head) {
    if (list_size(head) <= 1) {
        // List is empty or only contains 1 element.
        return;
    }

    ListNode* curr = head;
    while(curr != NULL) {
        ListNode* last = curr;
        ListNode* search = curr->next;

        while (search != NULL) {
            if (search->val == curr->val) {
                // Delete node
                last->next = search->next;
            } else {
                last = search;
            }
            search = search->next;

        }

        curr = curr->next;
    }
}

int main() {
    vector<int> vect{1, 2, 2, 3, 2, 4, 3};
    ListNode* list = list_from_vector(vect);
    deleteDuplicates(list);
    print_list(list);
}

