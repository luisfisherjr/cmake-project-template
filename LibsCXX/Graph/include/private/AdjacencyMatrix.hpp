#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP

//#include <unordered_map>
#include <fstream>

#include "Graph.hpp"
#include "Edge.hpp"
#include "Node.hpp"

class AdjacencyMatrix: public Graph {

private:

    void readFile(std::ifstream &infile);

public:

    AdjacencyMatrix();

    AdjacencyMatrix(std::ifstream &infile);

    ~AdjacencyMatrix();

    bool adjacent(const Node *x, const Node *y) const;

    std::vector<Node> neighbors(Node *x) const;

    bool addNode(const Node *x);

    bool removeNode(Node *x);

    bool addEdge(const Edge *x);

    bool removeEdge(Edge *x);

    int distance(const Node *from, const Node *to) const;

    const Node* getNode(int index) const;

    std::string toString() const;
};

#endif //ADJACENCY_MATRIX_HPP
