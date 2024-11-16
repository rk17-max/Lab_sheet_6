cmake_minimum_required(VERSION 3.10)
project(DataStructureVisualizer)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add include directories
include_directories(include)

# Add executable
add_executable(DataStructureVisualizer 
    src/main.cpp
    src/BinaryTree.cpp
    src/AVLTree.cpp
    src/Graph.cpp
    src/Visualization.cpp
)

# Link libraries
target_link_libraries(DataStructureVisualizer 
    sfml-graphics 
    sfml-window 
    sfml-system
)
