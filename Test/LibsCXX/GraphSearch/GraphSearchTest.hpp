#ifndef GRAPH_TEST_H

#include "gtest/gtest.h"
#include "Graph.hpp"

#define GRAPH_TEST_H

class GraphTest: public ::testing::Test {

protected:

    // initialization code here
    GraphTest();

    // cleanup any pending stuff, but no exceptions allowed
    virtual ~GraphTest();

    // code here will execute just before the test ensues
    virtual void SetUp();

    // code here will be called just after the test completes
    // ok to through exceptions from here if need be
    virtual void TearDown();

//    std::string stringArray[10] {
//        "cat",
//        "hat",
//        "boo",
//        "zoo",
//        "feather",
//        "leather",
//        "cool",
//        "pool",
//        "hello",
//        "fellow"
//    };
//
//    DoubleLinkedList *doubleLinkedList;
};

#endif //GRAPH_TEST_H
