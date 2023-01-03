//
// Created by Adam Ali on 03/01/2023.
//

#include "../lib/dgraph.h"
#include <iostream>

int main() {
    dgraph graph;
    graph_node* a = new graph_node(1);
    graph_node* b = new graph_node(2);
    graph_node* c = new graph_node(3);
    graph_node* d = new graph_node(4);

    graph.add_node(a);
    graph.add_node(b);
    graph.add_node(c);
    graph.add_node(d);

    graph.add_edge(a, b);
    graph.add_edge(b, c);

    std::cout << graph.route_exists(a, d) << std::endl; // 0
    std::cout << graph.route_exists(a, c) << std::endl; // 1
}