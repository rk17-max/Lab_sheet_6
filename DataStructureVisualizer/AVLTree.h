#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <vector>
#include <algorithm>

class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    // Rotation methods
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);

    // Helper methods
    int getHeight(AVLNode* node);
    int getBalanceFactor(AVLNode* node);
    AVLNode* insertRecursive(AVLNode* node, int value);
    AVLNode* deleteRecursive(AVLNode* node, int value);

public:
    AVLTree() : root(nullptr) {}

    void insert(int value);
    void remove(int value);
    std::vector<int> inorderTraversal();
    bool search(int value);
};

#endif // AVL_TREE_H
