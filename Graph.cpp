#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>
#include <vector>
#include "Graph.h"

Graph::Graph(const std::string& str)
{
    size = str.size();
    grid = str;
    maze = new Node*[size];
    configureMaze();
}

Graph::~Graph()
{
    for (int i = 0; i < size; i++)
    {
        delete maze[i];
        maze[i] = NULL;
    }
    delete [] maze;
}

std::string Graph::findPath()
{
    BFS(maze[0]);  // Calls BFS on first square in maze

    // Inserts last square of maze into path
    path.push_back(maze[size - 1]);

    Node* temp = maze[size - 1]->parent;
    while (temp != NULL)
    {
        path.push_back(temp);
        temp = temp->parent;
    }

    // Puts path in correct order
    std::reverse(path.begin(), path.end());

    return getPath(); // List of coordinates
}

void Graph::configureMaze()
{
    for (int i = 0; i < size; i++)
    {
        Node* temp = new Node();
        
        if (tolower(grid[i]) == 'a')
        {
            temp->data = 10;
        } else if (tolower(grid[i]) == 'b')
        {
            temp->data = 11;
        } else if (tolower(grid[i]) == 'c')
        {
            temp->data = 12;
        } else if (tolower(grid[i]) == 'd')
        {
            temp->data = 13;
        } else if (tolower(grid[i]) == 'e')
        {
            temp->data = 14;
        } else if (tolower(grid[i]) == 'f')
        {
            temp->data = 15;
        } else
        {
            temp->data = grid[i] - 48;
        }

        maze[i] = temp;
    }

    setCoordinates();
}

void Graph::setCoordinates()
{
    int width = sqrt(size); // Number of squares across
    for (int i = 0; i < size; i++)
    {
        maze[i]->y = i / width;
        maze[i]->x = i % width;
    }
}

void Graph::findAdjacentNodes(Node* v)
{
    int width = sqrt(size); // Number of squares across
    int index = v->x + (width * v->y); // Index of square

    Node* neighbor = NULL;
    
    if (v->x - 1 >= 0) // Look left
    {
        neighbor = maze[index - 1]; // Neighbor to the left

        // Checks for no wall between squares
        if (walls[v->data][3] == "empty" &&
            walls[neighbor->data][1] == "empty")
        {
            // Adds to square's adjacency list
            v->adjacentNodes.push_back(neighbor);
        }
    }

    if (v->x + 1 < width) // Look right
    {
        neighbor = maze[index + 1]; // Neighbor to the right

        // Refers to wall array in Graph.h
        if (walls[v->data][1] == "empty" &&
            walls[neighbor->data][3] == "empty")
        {
            v->adjacentNodes.push_back(neighbor);
        }
    }

    if (v->y - 1 >= 0) // Look up
    {
        neighbor = maze[index - width]; // Neighbor above

        if (walls[v->data][0] == "empty" &&
            walls[neighbor->data][2] == "empty")
        {
            v->adjacentNodes.push_back(neighbor);
        }
    }

    if (v->y + 1 < width) // Look down
    {
        neighbor = maze[index + width]; // Neighbor below

        if (walls[v->data][2] == "empty" &&
            walls[neighbor->data][0] == "empty")
        {
            v->adjacentNodes.push_back(neighbor);
        }
    }    
}

void Graph::BFS(Node* vertex)
{
    vertex->color = "gray"; // Discovered
    vertex->distance = 0; // Starting node
    vertex->parent = NULL; // Root

    std::queue<Node*> nodeQueue;
    nodeQueue.push(vertex);

    while (!nodeQueue.empty())
    {
        Node* temp = nodeQueue.front();

        findAdjacentNodes(temp);

        int numAdjacentNodes = temp->adjacentNodes.size();
        for (int i = 0; i < numAdjacentNodes; i++)
        {
            if (temp->adjacentNodes[i]->color == "white") // Undiscovered
            {
                temp->adjacentNodes[i]->color = "gray";
                temp->adjacentNodes[i]->distance = temp->distance + 1;
                temp->adjacentNodes[i]->parent = temp;

                nodeQueue.push(temp->adjacentNodes[i]);
            }
        }

        nodeQueue.pop();
        temp->color = "black"; // Completed
    }
}

std::string Graph::getPath() const
{
    int pathSize = path.size();
    std::stringstream strm;
    for (int i = 0; i < pathSize; i++)
    {
        if (i == pathSize - 1)
        {
            strm << "(" << path[i]->x << ", " << path[i]->y << ")";
        } else
        {
            strm << "(" << path[i]->x << ", " << path[i]->y << ")\n";
        }
    }

    return strm.str();
}