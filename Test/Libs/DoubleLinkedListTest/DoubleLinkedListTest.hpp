#ifndef DOUBLELINKEDLIST_TEST_H

#include "gtest/gtest.h"
#include "Node.h"

#define DOUBLELINKEDLIST_TEST_H

class DoubleLinkedListTest: public ::testing::Test {

protected:

    // initialization code here
    DoubleLinkedListTest();

    // cleanup any pending stuff, but no exceptions allowed
    virtual ~DoubleLinkedListTest();

    // code here will execute just before the test ensues
    virtual void SetUp();

    // code here will be called just after the test completes
    // ok to through exceptions from here if need be
    virtual void TearDown();

    std::string stringArray[10];

    linkDLL *head;
};

#endif //DOUBLELINKEDLIST_TEST_H
