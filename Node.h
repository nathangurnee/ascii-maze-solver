#ifndef NODE_H
#define NODE_H

#include <vector>

// Attributes of a node in the graph
class Node
{
public:
    Node()
        : color("white"), distance(-1), x(-1), y(-1), data(-1),
        parent(NULL) {}
private:
    std::string color; // Flag to indicate a node has been discovered
    int x, y; // Coordinates
    int distance; // Distance from root
    int data; // Value of node in graph
    Node* parent; // Parent of node
    std::vector<Node*> adjacentNodes;
friend class Graph;
};

#endif