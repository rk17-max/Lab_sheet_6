#include <iostream>
#include <cassert>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "Graph.h"

void testBinaryTreeInsertion() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    auto traversal = tree.inorderTraversal();
    assert(traversal.size() == 3);
    assert(traversal[0] == 5);
    assert(traversal[1] == 10);
    assert(traversal[2] == 15);
    std::cout << "Binary Tree Insertion Test Passed!" << std::endl;
}

void testGraphTraversal() {
    Graph graph;
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);

    auto bfsResult = graph.breadthFirstSearch(0);
    assert(!bfsResult.empty());
    std::cout << "Graph Traversal Test Passed!" << std::endl;
}

int main() {
    testBinaryTreeInsertion();
    testGraphTraversal();
    return 0;
}
