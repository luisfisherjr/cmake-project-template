#ifndef GRAPH_FACTORY_HPP
#define GRAPH_FACTORY_HPP

#include <stdexcept>
#include <stdio.h>
#include <vector>

#include <fstream>

#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
#include "ObjectOriented.hpp"

#include "Graph.hpp"

/**
 * Interface to define common behaviors across different representations
 */
enum STRATEGY {
    ADJACENCY_LIST,
    ADJACENCY_MATRIX,
    OBJECT_ORIENTED
};

class GraphFactory {

public:

    /**
     * Factory pattern to create correct strategy of graph representation
     * @param strategy supported strategies are listed under enum
     * @param file     file to read the contents
     * @return representation from the strategy and file above
     */
    Graph* createGraph(STRATEGY strategy, std::ifstream &file) {
        switch (strategy) {
            case ADJACENCY_LIST:
                return new AdjacencyList(file);
            case ADJACENCY_MATRIX:
                return new AdjacencyMatrix(file);
            case OBJECT_ORIENTED:
                return new ObjectOriented(file);
            default:
                throw std::invalid_argument("...");
        }
    }

    Graph* createGraph(STRATEGY strategy) {
        switch (strategy) {
            case ADJACENCY_LIST:
                return new AdjacencyList();
            case ADJACENCY_MATRIX:
                return new AdjacencyMatrix();
            case OBJECT_ORIENTED:
                return new ObjectOriented();
            default:
                throw std::invalid_argument("...");
        }
    };
};

#endif //GRAPH_FACTORY_HPP
