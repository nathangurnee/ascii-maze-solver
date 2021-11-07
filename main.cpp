#include <iostream>
#include "Graph.h"

int main()
{
    std::string line;
    std::string grid;
    while (getline(std::cin, line)) { grid += line; }
    
    Graph maze(grid);
    std::cout << maze.findPath() << std::endl;

    return 0;
}