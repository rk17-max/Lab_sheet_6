
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <vector>
#include <iostream>

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    BinaryTreeNode* root;

    // Helper methods
    void insertRecursive(BinaryTreeNode* &node, int value);
    void inorderTraversalRecursive(BinaryTreeNode* node, std::vector<int>& result);
    void preorderTraversalRecursive(BinaryTreeNode* node, std::vector<int>& result);
    void postorderTraversalRecursive(BinaryTreeNode* node, std::vector<int>& result);

public:
    BinaryTree() : root(nullptr) {}

    // Insertion methods
    void insert(int value);

    // Traversal methods
    std::vector<int> inorderTraversal();
    std::vector<int> preorderTraversal();
    std::vector<int> postorderTraversal();

    // Search and deletion methods
    bool search(int value);
    void remove(int value);

    // Utility methods
    int getHeight();
    void clear();
};

#endif // BINARY_TREE_H
