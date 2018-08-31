#include "Edge.hpp"

Edge::Edge(Node *from, Node *to) {
    this->from = from;
    this->to = to;
}

Edge::~Edge() {}

int Edge::getValue() const {
    return value;
};

void Edge::setValue(int value) {
    this->value = value;
}

const Node* Edge::getFrom() const {
    return from;
}

void Edge::setFrom(Node *from) {
    this->from = from;
}

const Node*  Edge::getTo() const {
    return to;
}

void Edge::setTo(Node *to) {
    this->to = to;
}

std::string Edge::toString() const {
    return "Edge{from=" + from->toString() + ", to=" + to->toString() + ", value=" + std::to_string(value) + "}";
}

bool Edge::equals(const Edge *edge) const {
    if (this == edge) return true;
    if (this->from->equals(edge->from) && this->to->equals(edge->to) && this->value == edge->value) return true;
    return false;
}

int Edge::hashCode() const {
    int result = from != nullptr ? from->hashCode() : 0;
    result = 31 * result + (to != nullptr ? to->hashCode() : 0);
    result = 31 * result + value;
    return result;
}