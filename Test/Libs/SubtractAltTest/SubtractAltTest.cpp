//include to be tested
#include "SubtractAlt.h"

#include "SubtractAltTest.hpp"

//using ::testing::Return;

SubtractAltTest::SubtractAltTest() {}

SubtractAltTest::~SubtractAltTest() {};

void SubtractAltTest::SetUp() {};

void SubtractAltTest::TearDown() {};

TEST_F(SubtractAltTest, SubtractSameSigned) {

    int num1 = 5;
    int num2 = 25;

    expected = num1 - num2;
    given = subtractAlt(num1, num2);

    EXPECT_EQ(expected, given);

    num1 *= -1;
    num2 *= -1;

    expected = num1 - num2;
    given = subtractAlt(num1, num2);

    EXPECT_EQ(expected, given);
}

TEST_F(SubtractAltTest, SubtractMixedSigned) {

    int num1 = -5;
    int num2 = 25;

    expected = num1 - num2;
    given = subtractAlt(num1, num2);

    EXPECT_EQ(expected, given);

    num1 *= -1;
    num2 *= -1;

    expected = num1 - num2;
    given = subtractAlt(num1, num2);

    EXPECT_EQ(expected, given);
}