#ifndef SORTS_TEST_H

#include "gtest/gtest.h"

#define SORTS_TEST_H

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

    std::string toOrder[10];

    std::string givenOrder [10] = {
            "cat",
            "hat",
            "boo",
            "zoo",
            "feather",
            "leather",
            "cool",
            "pool",
            "hello",
            "fellow",
    };

    std::string expectedOrder[10] {
            "boo",
            "cat",
            "cool",
            "feather",
            "fellow",
            "hat",
            "hello",
            "leather",
            "pool",
            "zoo",
    };

    int sizeOfArrays = 10;
};

#endif //SORTS_TEST_H
