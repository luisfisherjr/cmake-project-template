//include to be tested
#include "Sorts.h"
#include "SortsTest.hpp"

#include <string.h>

//using ::testing::Return;

int compareString(const void* stringA, const void* stringB);
int compareInt(const void* intA, const void* intB);

SortsTest::SortsTest() {}

SortsTest::~SortsTest() {};


void SortsTest::SetUp() {

    for (int i = 0; i < sizeOfArrays; i++) {

        stdStringsToOrder[i] = stdStringsGivenOrder[i];
        intsToOrder[i] = intsGivenOrder[i];
    }
};

void SortsTest::TearDown() {
};


TEST_F(SortsTest, BubbleSortTest) {

    // sorts std::string objects
    sorts(BUBBLE, stdStringsToOrder, sizeOfArrays, sizeof(char*), compareString);

    for (int i = 0; i < sizeOfArrays; i++) {

        EXPECT_EQ(stdStringsExpectedOrder[i], stdStringsToOrder[i]);
    }

    // sorts int primitives
    sorts(BUBBLE, intsToOrder, sizeOfArrays, sizeof(int), compareInt);

    for (int i = 0; i < sizeOfArrays; i++) {

        EXPECT_EQ(intsExpectedOrder[i], intsToOrder[i]);
    }
}

TEST_F(SortsTest, SelectSortTest) {

    // sorts std::string objects
    sorts(SELECT, stdStringsToOrder, sizeOfArrays, sizeof(char*), compareString);

    for (int i = 0; i < sizeOfArrays; i++) {

        EXPECT_EQ(stdStringsExpectedOrder[i], stdStringsToOrder[i]);
    }

    // sorts int primitives
    sorts(SELECT, intsToOrder, sizeOfArrays, sizeof(int), compareInt);

    for (int i = 0; i < sizeOfArrays; i++) {

        EXPECT_EQ(intsExpectedOrder[i], intsToOrder[i]);
    }
}

TEST_F(SortsTest, InsertSortTest) {

    // sorts std::string objects
    sorts(INSERT, stdStringsToOrder, sizeOfArrays, sizeof(char*), compareString);

    for (int i = 0; i < sizeOfArrays; i++) {

        EXPECT_EQ(stdStringsExpectedOrder[i], stdStringsToOrder[i]);
    }

    // sorts int primitives
    sorts(INSERT, intsToOrder, sizeOfArrays, sizeof(int), compareInt);

    for (int i = 0; i < sizeOfArrays; i++) {

        EXPECT_EQ(intsExpectedOrder[i], intsToOrder[i]);
    }
}


TEST_F(SortsTest, MergeSortTest) {

    // sorts std::string objects
    sorts(MERGE, stdStringsToOrder, sizeOfArrays, sizeof(char*), compareString);

    for (int i = 0; i < sizeOfArrays; i++) {

        EXPECT_EQ(stdStringsExpectedOrder[i], stdStringsToOrder[i]);
    }

    // sorts int primitives
    sorts(MERGE, intsToOrder, sizeOfArrays, sizeof(int), compareInt);

    for (int i = 0; i < sizeOfArrays; i++) {

        EXPECT_EQ(intsExpectedOrder[i], intsToOrder[i]);
    }
}

TEST_F(SortsTest, QuickSortTest) {

    // sorts std::string objects
    sorts(QUICK, stdStringsToOrder, sizeOfArrays, sizeof(char*), compareString);

    for (int i = 0; i < sizeOfArrays; i++) {

        EXPECT_EQ(stdStringsExpectedOrder[i], stdStringsToOrder[i]);
    }

    // sorts int primitives
    sorts(QUICK, intsToOrder, sizeOfArrays, sizeof(int), compareInt);

    for (int i = 0; i < sizeOfArrays; i++) {

        EXPECT_EQ(intsExpectedOrder[i], intsToOrder[i]);
    }
}

//TEST_F(SortsTest, RadixSortTest) {
//
//    sorts(RADIX, &stdStringsToOrder, sizeOfArrays, sizeof(std::string), nullptr);
//
//    for (int i = 0; i < sizeOfArrays; i++) {
//
//        EXPECT_EQ(stdStringsExpectedOrder[i], stdStringsToOrder[i]);
//    }
//}


int compareInt(const void* intA, const void* intB) {

    int value =  *(int*)intA - *(int*)intB;

    printf("\ncompare return: %d\n", value);

    return value;
}

int compareString(const void* stringA, const void* stringB) {

    int value =  strcmp(*((char**)stringA),*((char**)stringB));

    printf("\ncompare return: %d\n", value);

    return value;
}