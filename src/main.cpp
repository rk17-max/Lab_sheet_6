#include "Visualization.h"

int main() {
    try {
        Visualization app;
        app.run();
    } catch (const std::exception& e) {
        std::cerr << "Application error: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}
