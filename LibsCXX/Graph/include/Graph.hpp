#ifndef GRAPH_LIBRARY_HPP
#define GRAPH_LIBRARY_HPP

#include <stdexcept>
#include <stdio.h>
#include <vector>
#include <string>

#include "Node.hpp"
#include "Edge.hpp"


class Graph {

public:

    virtual  ~Graph(){};

    virtual bool adjacent(const Node *x, const Node *y) const = 0;

    virtual std::vector<Node> neighbors(Node *x) const = 0;

    virtual bool addNode(const Node *x) = 0;

    virtual bool removeNode(Node *x) = 0;

    virtual bool addEdge(const Edge *x) = 0;

    virtual bool removeEdge(Edge *x) = 0;

    virtual int distance(const Node *from, const Node *to) const = 0;

    virtual const Node* getNode(int index) const = 0;

    virtual std::string toString() const = 0;
};

#endif //GRAPH_LIBRARY_HPP

