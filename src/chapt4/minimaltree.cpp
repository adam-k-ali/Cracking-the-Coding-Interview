//
// Created by Adam Ali on 03/01/2023.
//

#include "../lib/binarytree.h"
#include <vector>
#include <iostream>

binary_tree_node* minimal_tree(std::vector<int> arr) {
    if (arr.size() == 0) {
        return nullptr;
    }
    int mid = arr.size() / 2;
    binary_tree_node* root = new binary_tree_node(arr[mid]);
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid + 1, arr.end());
    root->left = minimal_tree(left);
    root->right = minimal_tree(right);
    return root;
}

void print_tree(const std::string& prefix, const binary_tree_node* root, bool isLeft) {
    if (root == nullptr) {
        return;
    }
    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──" );
    std::cout << root->data << std::endl;
    print_tree(prefix + (isLeft ? "│   " : "    "), root->left, true);
    print_tree(prefix + (isLeft ? "│   " : "    "), root->right, false);
}

void print_tree(const binary_tree_node* root) {
    print_tree("", root, false);
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    binary_tree_node* root = minimal_tree(arr);

    print_tree(root);

    return 0;
}