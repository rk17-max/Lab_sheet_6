#include "Visualization.h"

Visualization::Visualization() : window(sf::VideoMode(800, 600), "Data Structure Visualizer") {
    // Initialize any additional settings if needed
}

void Visualization::run() {
    while (window.isOpen()) {
        handleEvents();
        renderMenu();
    }
}

void Visualization::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        // Handle other events (mouse clicks, keyboard input, etc.)
    }
}

void Visualization::renderMenu() {
    window.clear(sf::Color::White);

    // Render the menu and options here
    // For example, you can add buttons, input fields, etc.

    window.display();
}

void Visualization::drawBinaryTree() {
    // Implement binary tree drawing logic here
}

void Visualization::drawGraph() {
    // Implement graph drawing logic here
}

void Visualization::drawAVLTree() {
    // Implement AVL tree drawing logic here
}
