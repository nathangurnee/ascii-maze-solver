#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include "Node.h"

// Each potential wall configuration
const std::string walls[16][4] = {
    {"empty", "empty", "empty", "empty"}, // 0
    {"empty", "right", "empty", "empty"}, // 1
    {"empty", "empty", "bottom", "empty"}, // 2
    {"empty", "right", "bottom", "empty"}, // 3
    {"empty", "empty", "empty", "left"}, // 4
    {"empty", "right", "empty", "left"}, // 5
    {"empty", "empty", "bottom", "left"}, // 6
    {"empty", "right", "bottom", "left"}, // 7
    {"top", "empty", "empty", "empty"}, // 8
    {"top", "right", "empty", "empty"}, // 9
    {"top", "empty", "bottom", "empty"}, // 10 or a
    {"top", "right", "bottom", "empty"}, // 11 or b
    {"top", "empty", "empty", "left"}, // 12 or c
    {"top", "right", "empty", "left"}, // 13 or d
    {"top", "empty", "bottom", "left"}, // 14 or e
    {"top", "right", "bottom", "left"}, // 15 or f
};

// Implements functionality used to solve a maze
class Graph
{
public:
    // Initializes data members
    Graph(const std::string&);

    // Frees memory used by class
    ~Graph();

    // Finds the shortest path through the maze using BFS
    std::string findPath();
private:
    // Converts ASCII maze to a numerical format
    void configureMaze();

    // Gives each square an x and y coordinate
    void setCoordinates();

    // Finds all sqaures conncected to a given square
    void findAdjacentNodes(Node*);

    // Breadth-First Search algorithm used to find a path through
    // the maze
    void BFS(Node*);

    // Gives the coordinate for each square in traversal through maze
    std::string getPath() const;
    
    int size; // Total size of maze
    std::string grid; // Initial configuration of maze
    Node** maze;
    std::vector<Node*> path; // Holds each square in solution of maze
};

#endif