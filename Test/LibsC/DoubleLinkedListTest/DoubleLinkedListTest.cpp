//include to be tested
#include "DoubleLinkedList.h"
#include "DoubleLinkedListTest.hpp"

#include <string.h>
#include <string>
#include <cstddef>

//using ::testing::Return;

DoubleLinkedListTest::DoubleLinkedListTest() {}

DoubleLinkedListTest::~DoubleLinkedListTest() {};

int stringEqual(const void* stringA, const void* stringB);

void DoubleLinkedListTest::SetUp() {

    doubleLinkedList = (DoubleLinkedList*) newDoubleLinkedList(stringEqual);
};

void DoubleLinkedListTest::TearDown() {

    destroyDoubleLinkedList(doubleLinkedList);
};


TEST_F(DoubleLinkedListTest, SizeTest) {

    EXPECT_EQ(0, doubleLinkedList->size(doubleLinkedList));

    for (int i = 0; i < 4; i++) {

        doubleLinkedList->push(&stringArray[i], doubleLinkedList);

        EXPECT_EQ(i + 1, doubleLinkedList->size(doubleLinkedList));
    }

    doubleLinkedList->clear(doubleLinkedList);

    EXPECT_EQ(0, doubleLinkedList->size(doubleLinkedList));
}

TEST_F(DoubleLinkedListTest, GetTest) {


    EXPECT_EQ(nullptr, (std::string *) doubleLinkedList->get(-1, doubleLinkedList));

    for (int i = 0; i < 10; i++) {

        doubleLinkedList->push(&stringArray[i], doubleLinkedList);

        EXPECT_EQ(stringArray[i], *(std::string *) doubleLinkedList->get(i, doubleLinkedList));
    }

    EXPECT_EQ(nullptr, (std::string *) doubleLinkedList->get(11, doubleLinkedList));
}

TEST_F(DoubleLinkedListTest, ContainsTest) {

    EXPECT_EQ(-1, doubleLinkedList->contains(&stringArray[0], doubleLinkedList));

    for (int i = 0; i < 8; i++) {

        doubleLinkedList->push(&stringArray[i], doubleLinkedList);

        EXPECT_EQ(i, doubleLinkedList->contains(&stringArray[i], doubleLinkedList));
    }

    EXPECT_EQ(-1, doubleLinkedList->contains(&stringArray[8], doubleLinkedList));
}

TEST_F(DoubleLinkedListTest, QueueFunctionsOffer10PeekPoll11) {


    for (int i = 0; i < 10; i++) {

        doubleLinkedList->offer(&stringArray[i], doubleLinkedList);

        EXPECT_EQ(stringArray[i], *(std::string *) doubleLinkedList->get(i, doubleLinkedList));
    }


    for (int i = 0; i < 10; i++) {

        // expected , given
        EXPECT_EQ(stringArray[i], *(std::string *) doubleLinkedList->peekQueue(doubleLinkedList));

        // expected , given
        EXPECT_EQ(stringArray[i], *(std::string *) doubleLinkedList->poll(doubleLinkedList));
    }

    // expected , given
    EXPECT_EQ(nullptr, (std::string *) doubleLinkedList->peekQueue(doubleLinkedList));

    // expected , given
    EXPECT_EQ(nullptr, (std::string *) doubleLinkedList->poll(doubleLinkedList));
}

TEST_F(DoubleLinkedListTest, StackFunctionsPush10PeekPop11) {


    for (int i = 0; i < 10; i++) {

        doubleLinkedList->push(&stringArray[i], doubleLinkedList);

        EXPECT_EQ(stringArray[i], *(std::string *) doubleLinkedList->get(i, doubleLinkedList));
    }


    for (int i = 9; i > -1 ; i--) {

        // expected , given
        EXPECT_EQ(stringArray[i], *(std::string *) doubleLinkedList->peekStack(doubleLinkedList));

        // expected , given
        EXPECT_EQ(stringArray[i], *(std::string *) doubleLinkedList->pop(doubleLinkedList));
    }

    // expected , given
    EXPECT_EQ(nullptr, (std::string *) doubleLinkedList->peekStack(doubleLinkedList));

    // expected , given
    EXPECT_EQ(nullptr, (std::string *) doubleLinkedList->pop(doubleLinkedList));
}


int stringEqual(const void* stringA, const void* stringB) {

    std::string* a = (std::string*)stringA;
    std::string* b = (std::string*)stringB;

    if (a->compare(*b) != 0) {
        return 0;
    }
    return 1;
}