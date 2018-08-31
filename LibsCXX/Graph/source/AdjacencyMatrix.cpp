#include "AdjacencyMatrix.hpp"

AdjacencyMatrix::AdjacencyMatrix(){}

AdjacencyMatrix::AdjacencyMatrix(std::ifstream &infile){

    readFile(infile);
}

AdjacencyMatrix::~AdjacencyMatrix(){}

bool AdjacencyMatrix::adjacent(const Node *x, const Node *y) const {

}

std::vector<Node> AdjacencyMatrix::neighbors(Node *x) const {

}

bool AdjacencyMatrix::addNode(const Node *x) {

}

bool AdjacencyMatrix::removeNode(Node *x) {

}

bool AdjacencyMatrix::addEdge(const Edge *x) {

}

bool AdjacencyMatrix::removeEdge(Edge *x) {

}

int AdjacencyMatrix::distance(const Node *from, const Node *to) const {

}

const Node* AdjacencyMatrix::getNode(int index) const {

}

std::string AdjacencyMatrix::toString() const {

}

void AdjacencyMatrix::readFile(std::ifstream &infile) {

}