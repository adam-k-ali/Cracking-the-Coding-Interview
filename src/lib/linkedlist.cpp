//
// Created by Adam Ali on 26/12/2022.
//

#include "linkedlist.h"
#include <iostream>

void linkedlist::copy_list(ListNode* other_head) {
    if (other_head == nullptr) {
        head = nullptr;
        return;
    }
    head = new ListNode(other_head->val);
    ListNode* curr = head;
    ListNode* other_curr = other_head->next;
    while (other_curr != nullptr) {
        curr->next = new ListNode(other_curr->val);
        curr = curr->next;
        other_curr = other_curr->next;
    }
}

linkedlist linkedlist::from_vector(vector<int> v) {
    if (v.size() == 0) {
        return nullptr;
    }

    ListNode* head = new ListNode(v[0]);
    ListNode* curr = head;
    for (int i = 1; i < v.size(); i++) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }

    return linkedlist(head);
}

void linkedlist::append(int i) {
    if (head == nullptr) {
        head = new ListNode(i);
    } else {
        ListNode* curr = head;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new ListNode(i);
    }
}

void linkedlist::append_node(ListNode* node) {
    if (head == nullptr) {
        head = node;
    } else {
        ListNode* curr = head;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

ListNode* linkedlist::intersect(const linkedlist &other) const {
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* other_curr = other.head;
        while (other_curr != nullptr) {
            if (curr == other_curr) {
                return curr;
            }
            other_curr = other_curr->next;
        }
        curr = curr->next;
    }
    return nullptr;
}

void linkedlist::reverse() {
    if (head == nullptr) {
        return;
    }
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = head->next;
    while (next != nullptr) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    head = curr;
}

bool linkedlist::delete_node(ListNode* node) {
    if (node == nullptr || node->next == nullptr) {
        return false;
    }
    ListNode* next = node->next;
    node->val = next->val;
    node->next = next->next;
    delete next;
    return true;
}

void linkedlist::concat(linkedlist other) {
    if (empty()) {
        head = other.head;
    }

    ListNode* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = other.head;
}

int linkedlist::kthFromLast(int k) {
    int n = size() - 1;
    int i = 0;

    ListNode* curr = head;
    while (n - i > k) {
        curr = curr->next;
        i++;
    }
    return curr->val;
}

size_t linkedlist::size() {
    if (head == nullptr) {
        return 0;
    }

    int count = 1;
    ListNode* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
        count++;
    }
    return count;
}

bool linkedlist::empty() {
    return head == nullptr;
}

void linkedlist::print() {
    printf("[");
    ListNode* curr = head;
    int i = 0;
    int n = size();
    while (curr != NULL) {
        printf("%d", curr->val);
        if (i < n - 1) {
            printf(",");
        }
        curr = curr->next;
        i++;
    }
    printf("]\n");
}

bool linkedlist::operator==(const linkedlist &other) const {
    ListNode* curr = head;
    ListNode* other_curr = other.head;
    while (curr != nullptr && other_curr != nullptr) {
        if (curr->val != other_curr->val) {
            return false;
        }
        curr = curr->next;
        other_curr = other_curr->next;
    }
    return curr == nullptr && other_curr == nullptr;
}