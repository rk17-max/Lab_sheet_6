#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <limits>

class Graph {
private:
    std::unordered_map<int, std::list<std::pair<int, int>>> adjacencyList;

public:
    // Basic graph operations
    void addEdge(int source, int destination, int weight = 1);
    void removeEdge(int source, int destination);

    // Traversal algorithms
    std::vector<int> breadthFirstSearch(int startVertex);
    std::vector<int> depthFirstSearch(int startVertex);

    // Shortest path algorithms
    std::vector<int> dijkstraShortestPath(int source, int destination);
    std::vector<int> bellmanFordShortestPath(int source, int destination);

    // Minimum Spanning Tree algorithms
    std::vector<std::pair<int, int>> primMST();
    std::vector<std::pair<int, int>> kruskalMST();
};

#endif // GRAPH_H
