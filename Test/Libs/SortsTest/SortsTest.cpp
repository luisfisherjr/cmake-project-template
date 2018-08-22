//include to be tested
#include "Sorts.h"
#include "SortsTest.hpp"

#include <string.h>
#include <string>
#include <cstddef>

//using ::testing::Return;

SortsTest::SortsTest() {}

SortsTest::~SortsTest() {};

int stringEqual(const void* stringA, const void* stringB);

void SortsTest::SetUp() {

    for (int i = 0; i < sizeOfArrays; i++) {

        toOrder[i] = givenOrder[i];
    }


};

void SortsTest::TearDown() {
};


TEST_F(SortsTest, BubbleSortTest) {

    sorts(BUBBLE, toOrder, sizeOfArrays, sizeof(std::string), stringEqual);

    for (int i = 0; i < sizeOfArrays; i++) {

        EXPECT_EQ(expectedOrder[i], toOrder[i]);
    }
}

TEST_F(SortsTest, InsertSortTest) {

    sorts(INSERT, toOrder, sizeOfArrays, sizeof(std::string), stringEqual);

    for (int i = 0; i < sizeOfArrays; i++) {

        EXPECT_EQ(expectedOrder[i], toOrder[i]);
    }
}

TEST_F(SortsTest, SelectSortTest) {

    sorts(SELECT, &toOrder, sizeOfArrays, sizeof(std::string), stringEqual);

    for (int i = 0; i < sizeOfArrays; i++) {

        EXPECT_EQ(expectedOrder[i], toOrder[i]);
    }
}

TEST_F(SortsTest, MergeSortTest) {

    sorts(MERGE, &toOrder, sizeOfArrays, sizeof(std::string), stringEqual);

    for (int i = 0; i < sizeOfArrays; i++) {

        EXPECT_EQ(expectedOrder[i], toOrder[i]);
    }
}

TEST_F(SortsTest, QuickSortTest) {

    sorts(QUICK, &toOrder, sizeOfArrays, sizeof(std::string), stringEqual);

    for (int i = 0; i < sizeOfArrays; i++) {

        EXPECT_EQ(expectedOrder[i], toOrder[i]);
    }
}

//TEST_F(SortsTest, RadixSortTest) {
//
//    sorts(RADIX, &toOrder, sizeOfArrays, sizeof(std::string), nullptr);
//
//    for (int i = 0; i < sizeOfArrays; i++) {
//
//        EXPECT_EQ(expectedOrder[i], toOrder[i]);
//    }
//}


int stringEqual(const void* stringA, const void* stringB) {

    std::string* a = (std::string*)stringA;
    std::string* b = (std::string*)stringB;

    if (a->compare(*b) != 0) {
        return 0;
    }
    return 1;
}