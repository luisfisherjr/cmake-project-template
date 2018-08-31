#ifndef SORTS_TEST_H

#include "gtest/gtest.h"
#include <string>

#define SORTS_TEST_H

#define LARGE_SIZE 10000

class SortsTest: public ::testing::Test {

protected:

    // initialization code here
    SortsTest();

    // cleanup any pending stuff, but no exceptions allowed
    virtual ~SortsTest();

    // code here will execute just before the test ensues
    virtual void SetUp();

    // code here will be called just after the test completes
    // ok to through exceptions from here if need be
    virtual void TearDown();

    int givenIntsOrder[LARGE_SIZE];
    int expectedIntsOrder[LARGE_SIZE];
    int intsToOrder[LARGE_SIZE];

    char* givenCStringOrder[LARGE_SIZE];
    char* expectedCStringOrder[LARGE_SIZE];
    char* cStringToOrder[LARGE_SIZE];
};

#endif //SORTS_TEST_H
