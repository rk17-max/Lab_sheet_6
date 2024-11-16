#include "AVLTree.h"

// Rotations
AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Helper methods
int AVLTree::getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

int AVLTree::getBalanceFactor(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

AVLNode* AVLTree::insertRecursive(AVLNode* node, int value) {
    if (!node)
        return new AVLNode(value);

    if (value < node->data)
        node->left = insertRecursive(node->left, value);
    else if (value > node->data)
        node->right = insertRecursive(node->right, value);

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && value < node->left->data)
        return rotateRight(node);

    if (balance < -1 && value > node->right->data)
        return rotateLeft(node);

    if (balance > 1 && value > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && value < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Public methods
void AVLTree::insert(int value) {
    root = insertRecursive(root, value);
}

void AVLTree::remove(int value) {
    root = deleteRecursive(root, value);
}

std::vector<int> AVLTree::inorderTraversal() {
    std::vector<int> result;
    inorderRecursive(root, result);
    return result;
}

bool AVLTree::search(int value) {
    return searchRecursive(root, value);
}

void AVLTree::inorderRecursive(AVLNode* node, std::vector<int>& result) {
    if (node) {
        inorderRecursive(node->left, result);
        result.push_back(node->data);
        inorderRecursive(node->right, result);
    }
}

bool AVLTree::searchRecursive(AVLNode* node, int value) {
    return node && (node->data == value || value < node->data ? searchRecursive(node->left, value) : searchRecursive(node->right, value));
}

AVLNode* AVLTree::deleteRecursive(AVLNode* node, int value) {
    if (!node)
        return node;

    if (value < node->data)
        node->left = deleteRecursive(node->left, value);
    else if (value > node->data)
        node->right = deleteRecursive(node->right, value);
    else {
        if (!node->left) {
            AVLNode* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            AVLNode* temp = node->left;
            delete node;
            return temp;
        }

        AVLNode* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteRecursive(node->right, temp->data);
    }

    if (!node)
        return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && getBalanceFactor(node->left) >= 0)
        return rotateRight(node);

    if (balance > 1 && getBalanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && getBalanceFactor(node->right) <= 0)
        return rotateLeft(node);

    if (balance < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

AVLNode* AVLTree::minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}
