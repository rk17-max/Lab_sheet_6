#include "BinaryTree.h"

void BinaryTree::insertRecursive(BinaryTreeNode* &node, int value) {
    if (node == nullptr) {
        node = new BinaryTreeNode(value);
        return;
    }

    if (value < node->data)
        insertRecursive(node->left, value);
    else if (value > node->data)
        insertRecursive(node->right, value);
}

void BinaryTree::insert(int value) {
    insertRecursive(root, value);
}

std::vector<int> BinaryTree::inorderTraversal() {
    std::vector<int> result;
    inorderTraversalRecursive(root, result);
    return result;
}

void BinaryTree::inorderTraversalRecursive(BinaryTreeNode* node, std::vector<int>& result) {
    if (node == nullptr) return;

    inorderTraversalRecursive(node->left, result);
    result.push_back(node->data);
    inorderTraversalRecursive(node->right, result);
}

// Implement similar methods for preorder and postorder traversals
