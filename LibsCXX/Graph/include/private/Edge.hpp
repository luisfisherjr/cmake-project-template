#ifndef GRAPH_EDGE_HPP
#define GRAPH_EDGE_HPP

#include "Node.hpp"

class Edge {

private:
    Node *from;
    Node *to;
    int value;

public:

    Edge(Node *from, Node *to);
    ~Edge();

    int getValue() const;

    void setValue(int value);

    const Node* getFrom() const;

    void setFrom(Node *from);

    const Node* getTo() const;

    void setTo(Node *to);

    std::string toString() const;

    bool equals(const Edge *edge) const;

    int hashCode() const;
};


namespace std {
    template<>
    class hash<Edge> {
    public:
        size_t operator()(const Edge &edge) const
        {
            return (size_t) edge.hashCode();
        }
    };
};

#endif //GRAPH_EDGE_HPP
