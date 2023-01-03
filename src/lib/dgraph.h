//
// Created by Adam Ali on 03/01/2023.
//

#ifndef CRACKINGTHECODINGINTERVIEW_DGRAPH_H
#define CRACKINGTHECODINGINTERVIEW_DGRAPH_H

#include <vector>

struct graph_node {
    int data;
    std::vector<graph_node*> children;
    graph_node(int data) : data(data), children(std::vector<graph_node*>()) {}
};


/**
 * A directed graph.
 */
class dgraph {
private:
    std::vector<graph_node*> nodes;
public:
    // Constructor
    dgraph() : nodes(std::vector<graph_node*>()) {}

    /**
     * Adds a graph_node to the graph.
     * @param node The node to add to the graph.
     */
    void add_node(graph_node* node);

    /**
     * Adds a directed edge between two nodes.
     * @param from The graph_node to add the edge from.
     * @param to The graph_node to add the edge to.
     */
    void add_edge(graph_node* from, graph_node* to);

    /**
     * Removes a graph_node from the graph.
     * @param node The node to remove from the graph.
     */
    void remove_node(graph_node* node);

    /**
     * Removes a directed edge between two nodes.
     * @param from The graph_node to remove the edge from.
     * @param to The graph_node to remove the edge to.
     */
    void remove_edge(graph_node* from, graph_node* to);

    /**
     * Checks if a graph_node exists in the graph.
     * @param data The data of the graph_node to check.
     * @return True if the graph_node exists, false otherwise.
     */
    bool contains(graph_node* node);

    /**
     * Checks if a directed edge exists between two nodes.
     * @param from The graph_node to check the edge from.
     * @param to The graph_node to check the edge to.
     * @return True if the edge exists, false otherwise.
     */
    bool contains(graph_node* from, graph_node* to);

    /**
     * Checks if a route exists between two nodes.
     * @param from The graph_node to check the route from.
     * @param to The graph_node to check the route to.
     * @return True if the route exists, false otherwise.
     */
    bool route_exists(graph_node* from, graph_node* to);
};


#endif //CRACKINGTHECODINGINTERVIEW_DGRAPH_H
