//
// Created by Adam Ali on 26/12/2022.
//

#include "LinkedList.h"

void LinkedList::copy_list(ListNode* other_head) {
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

LinkedList LinkedList::from_vector(vector<int> v) {
    if (v.size() == 0) {
        return nullptr;
    }

    ListNode* head = new ListNode(v[0]);
    ListNode* curr = head;
    for (int i = 1; i < v.size(); i++) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }

    return LinkedList(head);
}

void LinkedList::append(int i) {
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

void LinkedList::reverse() {
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

bool LinkedList::delete_node(ListNode* node) {
    if (node == nullptr || node->next == nullptr) {
        return false;
    }
    ListNode* next = node->next;
    node->val = next->val;
    node->next = next->next;
    delete next;
    return true;
}

void LinkedList::concat(LinkedList other) {
    if (empty()) {
        head = other.head;
    }

    ListNode* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = other.head;
}

int LinkedList::kthFromLast(int k) {
    int n = size() - 1;
    int i = 0;

    ListNode* curr = head;
    while (n - i > k) {
        curr = curr->next;
        i++;
    }
    return curr->val;
}

size_t LinkedList::size() {
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

bool LinkedList::empty() {
    return head == nullptr;
}

void LinkedList::print() {
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

bool LinkedList::operator==(const LinkedList &other) const {
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