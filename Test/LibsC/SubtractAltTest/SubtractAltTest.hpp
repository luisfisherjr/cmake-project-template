//
// Created by luis on 8/7/18.
//

#ifndef SUBTRACTALT_TEST_HPP

#define SUBTRACTALT_TEST_HPP

#include "gtest/gtest.h"

class SubtractAltTest: public ::testing::Test {

protected:

    // initialization code here
    SubtractAltTest();

    // cleanup any pending stuff, but no exceptions allowed
    virtual ~SubtractAltTest();

    // code here will execute just before the test ensues
    virtual void SetUp();

    // code here will be called just after the test completes
    // ok to through exceptions from here if need be
    virtual void TearDown();

    // put in any custom data members that you need
    int expected;
    int given;
};

#endif //SUBTRACTALT_TEST_HPP
