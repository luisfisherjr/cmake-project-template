#include <cstddef>
#include <cstring> // std::strcmp
#include <cstdlib> // std::rand, std::srand

#include <iostream>
#include <algorithm> // std::generate

#include "GraphFactory.hpp"
#include "Graph.hpp"

//currently used to test swap macro
int main(int argc, char *argv[]) {

    STRATEGY backEndType = OBJECT_ORIENTED;

    GraphFactory *factory = new GraphFactory();

    std::string graphFile1 = "../../Resources/graph-1.txt";
    std::string graphFile2 = "../../Resources/graph-2.txt";

    std::ifstream infile(graphFile1);

    Graph *listGraph = factory->createGraph(ADJACENCY_LIST, infile);
    Graph *objectGraph = factory->createGraph(OBJECT_ORIENTED);
    Graph *matrixGraph = factory->createGraph(ADJACENCY_MATRIX);

    delete factory;
    delete objectGraph;
    delete matrixGraph;
    delete listGraph;
}