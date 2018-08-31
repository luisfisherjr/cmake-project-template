#include <string>
//#include <sstream>
#include <iostream>

#include "AdjacencyList.hpp"
#include "StringData.hpp"

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

//@Override
//public boolean addNode(Node x) {
//
//    if (adjacencyList.containsKey(x)) return false;
//
//    adjacencyList.put(x, new ArrayList<Edge>());
//
//    return true;
//}

bool AdjacencyList::removeNode(Node *x) {

}

bool AdjacencyList::addEdge(const Edge *x) {

}

//@Override
//public boolean addEdge(Edge x) {
//
//    if (!adjacencyList.containsKey(x.getFrom()) ||
//        !adjacencyList.containsKey(x.getTo())) return false;
//
//    for(Edge e: adjacencyList.get(x.getFrom())) {
//        if (e.equals(x)) return false;
//    }
//
//    adjacencyList.get(x.getFrom()).add(x);
//
//    return true;
//}

bool AdjacencyList::removeEdge(Edge *x) {

}

int AdjacencyList::distance(const Node *from, const Node *to) const {

}

const Node* AdjacencyList::getNode(int index) const {

}

std::string AdjacencyList::toString() const {

}

// TODO readFile, as read file is being performed, complete functions being used
// use readFile below as an example
void AdjacencyList::readFile(std::ifstream &infile) {

    bool isFirstLine = true;
    int expectedNodeCount = 0;

    Node *nodeFrom = nullptr;
    Node *nodeTo =nullptr;
    int value = 0;

    Edge *edge = nullptr;

    std::string line;
    std::string lineSegment;

    while (std::getline(infile, line)) {

        std::cout << "in loop..." << std::endl;

        if (isFirstLine) {

            isFirstLine = false;
            expectedNodeCount = std::stoi(line);
            continue;
        }

        std::stringstream  sStream(line);
        std::vector<std::string> parsedLine;

        while(std::getline(sStream,lineSegment,':')) {

            parsedLine.push_back(lineSegment);
        }

        nodeFrom = new Node(new StringData(&parsedLine[0]));
        nodeTo = new Node(new StringData(&parsedLine[1]));
        value = std::stoi(parsedLine[2]);

        edge = new Edge(nodeFrom, nodeTo);
        edge->setValue(value);
    }
}


//@Override
//public boolean adjacent(Node x, Node y) {
//
//    // should i include?
//    if (!adjacencyList.containsKey(x)) return false;
//
//    ArrayList<Edge> edges = (ArrayList)adjacencyList.get(x);
//
//    for(Edge e: edges) {
//        if (e.getTo().equals(y)) return true;
//    }
//
//    return false;
//}
//
//@Override
//public List<Node> neighbors(Node x) {
//
//    // should i include?
//    if (!adjacencyList.containsKey(x)) return null;
//
//    ArrayList<Edge> edges = (ArrayList<Edge>)adjacencyList.get(x);
//
//    ArrayList<Node> neighbors = new ArrayList<Node>();
//
//    for(Edge e: edges) {
//        neighbors.add(e.getTo());
//    }
//
//    return neighbors;
//}
//
//@Override
//public boolean removeNode(Node x) {
//
//    if (!adjacencyList.containsKey(x)) return false;
//
//    Node[] keys;
//    ArrayList<Edge> edges;
//
//    /* remove all the from x edges */
//    adjacencyList.remove(x);
//
//    keys = new Node[adjacencyList.size()];
//
//    adjacencyList.keySet().toArray(keys);
//
//    /* remove all the to x edges */
//    for(Node n: keys) {
//
//        edges = (ArrayList<Edge>) adjacencyList.get(n);
//
//        /* iterates in reverse order to avoid null point exceptions, and keep runtime low*/
//        for(int index = edges.size() - 1; index > -1; index--) {
//
//            if (edges.get(index).getTo().equals(x)) edges.remove(index);
//        }
//    }
//
//    return true;
//}
//
//@Override
//public boolean addEdge(Edge x) {
//
//    if (!adjacencyList.containsKey(x.getFrom()) ||
//        !adjacencyList.containsKey(x.getTo())) return false;
//
//    for(Edge e: adjacencyList.get(x.getFrom())) {
//        if (e.equals(x)) return false;
//    }
//
//    adjacencyList.get(x.getFrom()).add(x);
//
//    return true;
//}
//
//@Override
//public boolean removeEdge(Edge x) {
//
//    if (!adjacencyList.containsKey(x.getFrom())) return false;
//    if (!adjacencyList.get(x.getFrom()).contains(x)) return false;
//
//    adjacencyList.get(x.getFrom()).remove(x);
//
//    return true;
//}
//
//@Override
//public int distance(Node from, Node to) {
//
//    if (!adjacencyList.containsKey(from)) return 0;
//
//    ArrayList<Edge> edges = (ArrayList)adjacencyList.get(from);
//
//    for(int index = 0; index < edges.size(); index++) {
//        if (edges.get(index).getTo().equals(to)) return edges.get(index).getValue();
//    }
//    return 0;
//}
//
//@Override
//public Optional<Node> getNode(int index) {
//    return null;
//}
