#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "BinaryTree.h"
#include "AVLTree.h"
#include "Graph.h"
#include <SFML/Graphics.hpp>

class Visualization {
private:
    sf::RenderWindow window;
    BinaryTree binaryTree;
    AVLTree avlTree;
    Graph graph;

    // Rendering methods
    void drawBinaryTree();
    void drawGraph();
    void drawAVLTree();

public:
    Visualization();
    void run();
    void handleEvents();
    void renderMenu();
};

#endif // VISUALIZATION_H
