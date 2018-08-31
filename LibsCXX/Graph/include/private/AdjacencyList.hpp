#ifndef ADJACENCY_LIST_HPP
#define ADJACENCY_LIST_HPP

#include <unordered_map>
#include <vector>
#include <fstream>

#include "Graph.hpp"
#include "Edge.hpp"
#include "Node.hpp"

class AdjacencyList: public Graph {

private:

    std::unordered_map<Node, std::vector<Node>>  *hashMap;

    void readFile(std::ifstream &infile);

public:

    AdjacencyList();

    AdjacencyList(std::ifstream &infile);

    ~AdjacencyList();

    bool adjacent(const Node *x, const Node *y) const;

    std::vector<Node> neighbors(Node *x) const;

    bool addNode(const Node *x);

    bool removeNode(Node *x);

    bool addEdge(const Edge *x);

    bool removeEdge(Edge *x);

    int distance(const Node *from, const Node *to) const;

    const Node* getNode(int index) const;

    std::string toString() const;

//    bool adjacent(const Node *x, const Node *y) const override;
//
//    std::vector<Node> neighbors(Node *x) const override;
//
//    bool addNode(const Node *x) override;
//
//    bool removeNode(Node *x) override;
//
//    bool addEdge(const Edge *x) override;
//
//    bool removeEdge(Edge *x) override;
//
//    int distance(const Node *from, const Node *to) const override;
//
//    const Node* getNode(int index) const override;
//
//    std::string toString() const override;
};

#endif //ADJACENCY_LIST_HPP
