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

    char* stdStringsToOrder[10];

    char* stdStringsGivenOrder [10] = {
        "cat",
        "hat",
        "boo",
        "zoo",
        "feather",
        "leather",
        "cool",
        "aARASDSXZCEDFSAWCEQ!XDSZVFZFECZEDZACasdaaxdadwdDSGSZVDSVZ",
        "hello",
        "fellow",
    };

    char* stdStringsExpectedOrder[10] {
        "aARASDSXZCEDFSAWCEQ!XDSZVFZFECZEDZACasdaaxdadwdDSGSZVDSVZ",
        "boo",
        "cat",
        "cool",
        "feather",
        "fellow",
        "hat",
        "hello",
        "leather",
        "zoo",
    };

    int intsToOrder[10];

    int intsGivenOrder [10] = {
        8,
        6,
        9,
        0,
        12,
        -5,
        7,
        22,
        12,
        -1,
    };

    int intsExpectedOrder[10] {
        -5,
        -1,
        0,
        6,
        7,
        8,
        9,
        12,
        12,
        22,
    };

    int sizeOfArrays = 10;
};

#endif //SORTS_TEST_H
