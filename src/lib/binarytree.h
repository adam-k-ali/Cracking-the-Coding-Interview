//
// Created by Adam Ali on 03/01/2023.
//

#ifndef CRACKINGTHECODINGINTERVIEW_BINARYTREE_H
#define CRACKINGTHECODINGINTERVIEW_BINARYTREE_H

struct binary_tree_node {
    int data;
    binary_tree_node* left;
    binary_tree_node* right;
    binary_tree_node(int data) : data(data), left(nullptr), right(nullptr) {}
};

#endif //CRACKINGTHECODINGINTERVIEW_BINARYTREE_H
