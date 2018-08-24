#include <algorithm> // std::generate
#include <cstdlib> // std::rand, std::srand std::malloc
#include <cstring> // strcmp
#include <list>

//include to be tested
#include "Sorts.h"

#include "SortsTest.hpp"

//using ::testing::Return;

int compareString(const void* stringA, const void* stringB);
int compareInt(const void* intA, const void* intB);


void populateRandCString(char *s, int length);
char* randomCString();

SortsTest::SortsTest() {


    std::generate(givenIntsOrder, givenIntsOrder + LARGE_SIZE, std::rand);
    std::generate(givenCStringOrder, givenCStringOrder + LARGE_SIZE, randomCString);

    for (int i = 0; i < LARGE_SIZE; i++) {
        expectedIntsOrder[i] = givenIntsOrder[i];
        expectedCStringOrder[i] = givenCStringOrder[i];
    }

    // WARNING qsort may not always be stable
    // since bubble sort and this qsort have same  results should be stable
    qsort(expectedIntsOrder, LARGE_SIZE, sizeof(int), compareInt);
    qsort(expectedCStringOrder, LARGE_SIZE, sizeof(char*), compareString);
}

SortsTest::~SortsTest() {

    for(int i = 0; i < LARGE_SIZE; i++) {
        free(givenCStringOrder[i]);
        givenCStringOrder[i] = 0;
        expectedIntsOrder[i] = 0;
        cStringToOrder[i] = 0;
    }
};


void SortsTest::SetUp() {

    for (int i = 0; i < LARGE_SIZE; i++) {
        intsToOrder[i] = givenIntsOrder[i];
        cStringToOrder[i] = givenCStringOrder[i];
    }
};

void SortsTest::TearDown() {
};

TEST_F(SortsTest, BubbleSortTest) {

    // compare primitive ints
    sorts(BUBBLE, intsToOrder, LARGE_SIZE, sizeof(int), compareInt);

    for (int i = 0; i < LARGE_SIZE; i++) {

        EXPECT_EQ(expectedIntsOrder[i], intsToOrder[i]);
    }

    // compare cstrings
    sorts(BUBBLE, cStringToOrder, LARGE_SIZE, sizeof(char*), compareString);

    for (int i = 0; i < LARGE_SIZE; i++) {

        EXPECT_EQ(expectedCStringOrder[i], cStringToOrder[i]);
    }
}

TEST_F(SortsTest, SelectSortTest) {

    // WARNING this sort is not stable
    // using explicit casting in EXPECT_EQ *(char*) for comparing strings

    // compare primitive ints
    sorts(SELECT, intsToOrder, LARGE_SIZE, sizeof(int), compareInt);

    for (int i = 0; i < LARGE_SIZE; i++) {

        EXPECT_EQ(expectedIntsOrder[i], intsToOrder[i]);
    }

    // compare cstrings
    sorts(SELECT, cStringToOrder, LARGE_SIZE, sizeof(char*), compareString);

    for (int i = 0; i < LARGE_SIZE; i++) {

        EXPECT_EQ(*(char*)expectedCStringOrder[i], *(char*)cStringToOrder[i]);
    }
}

TEST_F(SortsTest, SelectStableSortTest) {

    // compare primitive ints
    sorts(SELECT_STABLE, intsToOrder, LARGE_SIZE, sizeof(int), compareInt);

    for (int i = 0; i < LARGE_SIZE; i++) {

        EXPECT_EQ(expectedIntsOrder[i], intsToOrder[i]);
    }

    // compare cstrings
    sorts(SELECT_STABLE, cStringToOrder, LARGE_SIZE, sizeof(char*), compareString);

    for (int i = 0; i < LARGE_SIZE; i++) {

        EXPECT_EQ(expectedCStringOrder[i], cStringToOrder[i]);
    }
}

TEST_F(SortsTest, InsertSortTest) {

    // compare primitive ints
    sorts(INSERT, intsToOrder, LARGE_SIZE, sizeof(int), compareInt);

    for (int i = 0; i < LARGE_SIZE; i++) {

        EXPECT_EQ(expectedIntsOrder[i], intsToOrder[i]);
    }

    // compare cstrings
    sorts(INSERT, cStringToOrder, LARGE_SIZE, sizeof(char*), compareString);

    for (int i = 0; i < LARGE_SIZE; i++) {

        EXPECT_EQ(expectedCStringOrder[i], cStringToOrder[i]);
    }
}

TEST_F(SortsTest, MergeSortTest) {

    // compare primitive ints
    sorts(MERGE, intsToOrder, LARGE_SIZE, sizeof(int), compareInt);

    for (int i = 0; i < LARGE_SIZE; i++) {

        EXPECT_EQ(expectedIntsOrder[i], intsToOrder[i]);
    }

    // compare cstrings
    sorts(MERGE, cStringToOrder, LARGE_SIZE, sizeof(char*), compareString);

    for (int i = 0; i < LARGE_SIZE; i++) {

        EXPECT_EQ(expectedCStringOrder[i], cStringToOrder[i]);
    }
}

//TEST_F(SortsTest, QuickSortTest) {
//
//    // compare primitive ints
//    sorts(QUICK, intsToOrder, LARGE_SIZE, sizeof(int), compareInt);
//
//    for (int i = 0; i < LARGE_SIZE; i++) {
//
//        EXPECT_EQ(expectedIntsOrder[i], intsToOrder[i]);
//    }
//
//    // compare cstrings
//    sorts(QUICK, cStringToOrder, LARGE_SIZE, sizeof(char*), compareString);
//
//    for (int i = 0; i < LARGE_SIZE; i++) {
//
//        EXPECT_EQ(expectedCStringOrder[i], cStringToOrder[i]);
//    }
//}

//TEST_F(SortsTest, RadixSortTest) {
//
//    // sorts CStrings
//    sorts(RADIX, givenCStringOrder, LARGE_SIZE, sizeof(char*), compareString);
//
//    for (int i = 0; i < LARGE_SIZE; i++) {
//
//        EXPECT_EQ(expectedCStringOrder[i], givenCStringOrder[i]);
//    }
//
//    // sorts primitive int
//    sorts(RADIX, givenIntsOrder, LARGE_SIZE, sizeof(int), compareInt);
//
//    for (int i = 0; i < LARGE_SIZE; i++) {
//
//        EXPECT_EQ(expectedIntsOrder[i], givenIntsOrder[i]);
//    }
//}


int compareInt(const void* intA, const void* intB) {

    int a = *(int*)intA;
    int b = *(int*)intB;

    if (a < b) {
        return -1;
    }
    else if (a == b) {
        return 0;
    }
    else {
        return 1;
    }
}

int compareString(const void* stringA, const void* stringB) {

    char *a = *((char**)stringA);
    char *b = *((char**)stringB);
    int value =  std::strcmp(a, b);

    return value;
}



void populateRandCString(char *s, const int length) {
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < length; ++i) {
        s[i] = alphanum[std::rand() % (sizeof(alphanum) - 1)];
    }

    s[length] = 0;
}

char* randomCString() {

    int minLength = 1;
    int maxLength = 100;

    int length = minLength + (std::rand() % maxLength - minLength + 1);

    char* randCString = (char*) std::malloc(sizeof(char) * (length + 1));

    populateRandCString(randCString, length);

    return randCString;
}