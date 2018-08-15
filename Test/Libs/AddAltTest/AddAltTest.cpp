//include to be tested
#include "AddAlt.h"

#include "AddAltTest.hpp"

//using ::testing::Return;

AddAltTest::AddAltTest() {}

AddAltTest::~AddAltTest() {};

void AddAltTest::SetUp() {};

void AddAltTest::TearDown() {};

TEST_F(AddAltTest, AddSameSigned) {

    int num1 = 5;
    int num2 = 25;

    expected = num1 + num2;
    given = addAlt(num1, num2);

    EXPECT_EQ(expected, given);

    num1 *= -1;
    num2 *= -1;

    expected = num1 + num2;
    given = addAlt(num1, num2);

    EXPECT_EQ(expected, given);
}

TEST_F(AddAltTest, AddMixedSigned) {

    int num1 = -5;
    int num2 = 25;

    expected = num1 + num2;
    given = addAlt(num1, num2);

    EXPECT_EQ(expected, given);

    num1 *= -1;
    num2 *= -1;

    expected = num1 + num2;
    given = addAlt(num1, num2);

    EXPECT_EQ(expected, given);
}