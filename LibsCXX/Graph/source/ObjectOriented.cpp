#include "ObjectOriented.hpp"

ObjectOriented::ObjectOriented(){}

ObjectOriented::ObjectOriented(std::ifstream &infile){

    readFile(infile);
}

ObjectOriented::~ObjectOriented(){}

bool ObjectOriented::adjacent(const Node *x, const Node *y) const {

}

std::vector<Node> ObjectOriented::neighbors(Node *x) const {

}

bool ObjectOriented::addNode(const Node *x) {

}

bool ObjectOriented::removeNode(Node *x) {

}

bool ObjectOriented::addEdge(const Edge *x) {

}

bool ObjectOriented::removeEdge(Edge *x) {

}

int ObjectOriented::distance(const Node *from, const Node *to) const {

}

const Node* ObjectOriented::getNode(int index) const {

}

std::string ObjectOriented::toString() const {

}

void ObjectOriented::readFile(std::ifstream &infile) {

}
