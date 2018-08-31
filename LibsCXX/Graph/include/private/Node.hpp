#ifndef GRAPH_NODE_HPP
#define GRAPH_NODE_HPP

#include <string>
#include <Data.hpp>


class Node {

private:

    const Data *data = nullptr;
    int value = 0;

public:

    Node(const Data *data);
    ~Node();

    std::string toString() const;

    bool equals(const Node *node) const;

    int hashCode() const;
};

namespace std {
    template<>
    class hash<Node> {
    public:
        size_t operator()(const Node &node) const
        {
            return (size_t) node.hashCode();
        }
    };
};



#endif //GRAPH_NODE_HPP

