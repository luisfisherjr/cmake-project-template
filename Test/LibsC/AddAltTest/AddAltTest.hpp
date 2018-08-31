#ifndef ADDALT_TEST_HPP

#include "gtest/gtest.h"

#define ADDALT_TEST_HPP

class AddAltTest: public ::testing::Test {

protected:

    // initialization code here
    AddAltTest();

    // cleanup any pending stuff, but no exceptions allowed
    virtual ~AddAltTest();

    // code here will execute just before the test ensues
    virtual void SetUp();

    // code here will be called just after the test completes
    // ok to through exceptions from here if need be
    virtual void TearDown();

    // put in any custom data members that you need
    int expected;
    int given;
};

#endif //ADDALT_TEST_HPP
