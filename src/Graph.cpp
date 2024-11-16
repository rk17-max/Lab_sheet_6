#include "Graph.h"
#include <algorithm>

void Graph::addEdge(int source, int destination, int weight) {
    adjacencyList[source].emplace_back(destination, weight);
    adjacencyList[destination].emplace_back(source, weight);
}

void Graph::removeEdge(int source, int destination) {
    adjacencyList[source].remove_if([destination](const std::pair<int, int>& edge) {
        return edge.first == destination;
    });
    adjacencyList[destination].remove_if([source](const std::pair<int, int>& edge) {
        return edge.first == source;
    });
}

std::vector<int> Graph::breadthFirstSearch(int startVertex) {
    std::vector<bool> visited(adjacencyList.size(), false);
    std::vector<int> result;
    std::queue<int> queue;

    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        result.push_back(vertex);

        for (const auto& edge : adjacencyList[vertex]) {
            if (!visited[edge.first]) {
                visited[edge.first] = true;
                queue.push(edge.first);
            }
        }
    }

    return result;
}

std::vector<int> Graph::depthFirstSearch(int startVertex) {
    std::vector<bool> visited(adjacencyList.size(), false);
    std::vector<int> result;

    depthFirstSearchRecursive(startVertex, visited, result);
    return result;
}

void Graph::depthFirstSearchRecursive(int vertex, std::vector<bool>& visited, std::vector<int>& result) {
    visited[vertex] = true;
    result.push_back(vertex);

    for (const auto& edge : adjacencyList[vertex]) {
        if (!visited[edge.first]) {
            depthFirstSearchRecursive(edge.first, visited, result);
        }
    }
}

std::vector<int> Graph::dijkstraShortestPath(int source, int destination) {
    std::vector<int> distances(adjacencyList.size(), std::numeric_limits<int>::max());
    std::vector<int> parent(adjacencyList.size(), -1);
    std::vector<bool> visited(adjacencyList.size(), false);

    distances[source] = 0;

    for (int i = 0; i < adjacencyList.size() - 1; ++i) {
        int u = minDistance(distances, visited);
        visited[u] = true;

        for (const auto& edge : adjacencyList[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && distances[u] != std::numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                parent[v] = u;
            }
        }
    }

    std::vector<int> path;
    for (int at = destination; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());

    return path;
}

int Graph::minDistance(const std::vector<int>& distances, const std::vector<bool>& visited) {
    int min = std::numeric_limits<int>::max(), minIndex = -1;

    for (int v = 0; v < distances.size(); ++v) {
        if (!visited[v] && distances[v] <= min) {
            min = distances[v];
            minIndex = v;
        }
    }

    return minIndex;
}
