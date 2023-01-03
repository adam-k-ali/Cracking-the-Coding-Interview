//
// Created by Adam Ali on 03/01/2023.
//

#include "dgraph.h"

void dgraph::add_node(graph_node* n) {
    nodes.push_back(n);
}

void dgraph::add_edge(graph_node* from, graph_node* to) {
    if (from == nullptr || to == nullptr) {
        return;
    }
    if (contains(from, to)) {
        return; // Edge already exists
    }
    from->children.push_back(to);
}

void dgraph::remove_node(graph_node* n) {
    if (n == nullptr) {
        return;
    }
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i] == n) {
            nodes.erase(nodes.begin() + i);
            return;
        }
    }
}

void dgraph::remove_edge(graph_node* from, graph_node* to) {
    if (from == nullptr || to == nullptr) {
        return;
    }
    for (int i = 0; i < from->children.size(); i++) {
        if (from->children[i] == to) {
            from->children.erase(from->children.begin() + i);
            return;
        }
    }
}

bool dgraph::contains(graph_node* n) {
    if (n == nullptr) {
        return false;
    }
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i] == n) {
            return true;
        }
    }
    return false;
}

bool dgraph::contains(graph_node* from, graph_node* to) {
    if (from == nullptr || to == nullptr) {
        return false;
    }
    for (int i = 0; i < from->children.size(); i++) {
        if (from->children[i] == to) {
            return true;
        }
    }
    return false;
}

bool dgraph::route_exists(graph_node *from, graph_node *to) {
    if (from == nullptr || to == nullptr) {
        return false;
    }
    if (from == to) {
        return true;
    }
    for (int i = 0; i < from->children.size(); i++) {
        if (route_exists(from->children[i], to)) {
            return true;
        }
    }
    return false;
}