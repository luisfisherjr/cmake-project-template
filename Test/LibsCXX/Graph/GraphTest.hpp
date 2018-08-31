#ifndef GRAPH_TEST_H

#include "gtest/gtest.h"

#include "GraphFactory.hpp"
#include "Graph.hpp"

#define GRAPH_TEST_H

class GraphSearchTest: public ::testing::Test {

protected:

    // initialization code here
    GraphSearchTest();

    // cleanup any pending stuff, but no exceptions allowed
    virtual ~GraphSearchTest();

    // code here will execute just before the test ensues
    virtual void SetUp();

    // code here will be called just after the test completes
    // ok to through exceptions from here if need be
    virtual void TearDown();

    std::vector<Graph*> allGraphs;
    Graph *graph;
    GraphFactory *graphFactory;

    std::string graphFile1 = "../../../Resources/graph-1.txt";
    std::string graphFile2 = "../../../Resources/graph-2.txt";

};

#endif //GRAPH_TEST_H
