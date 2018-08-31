#include "AdjacencyList.hpp"

AdjacencyList::AdjacencyList() {
    hashMap = new std::unordered_map<Node, std::vector<Node>>();
}

AdjacencyList::AdjacencyList(std::ifstream &infile) {
    hashMap = new std::unordered_map<Node, std::vector<Node>>();
    readFile(infile);
}

AdjacencyList::~AdjacencyList() {
    delete hashMap;
}

bool AdjacencyList::adjacent(const Node *x, const Node *y) const {

}

std::vector<Node> AdjacencyList::neighbors(Node *x) const {

}

bool AdjacencyList::addNode(const Node *x) {

}

bool AdjacencyList::removeNode(Node *x) {

}

bool AdjacencyList::addEdge(const Edge *x) {

}

bool AdjacencyList::removeEdge(Edge *x) {

}

int AdjacencyList::distance(const Node *from, const Node *to) const {

}

const Node* AdjacencyList::getNode(int index) const {

}

std::string AdjacencyList::toString() const {

}

void AdjacencyList::readFile(std::ifstream &infile) {

}
