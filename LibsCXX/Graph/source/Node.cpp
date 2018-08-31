#include "Node.hpp"

Node::Node(const Data *data) {
    this->data = data;
}

Node::~Node() {
    this->data = nullptr;
}

std::string Node::toString() const {
    return "Node{data=" + data->toString() + '}';
};

int Node::hashCode() const {
    return this->data->hashCode();
};


bool Node::equals(const Node *node) const {
    if (this == node) return true;
    if (this->data == node->data) return true;
    return false;
}