//include to be tested
#include "DoubleLinkedList.h"
#include "DoubleLinkedListTest.hpp"

#include <string.h>
#include <string>

//using ::testing::Return;

DoubleLinkedListTest::DoubleLinkedListTest() {}

DoubleLinkedListTest::~DoubleLinkedListTest() {};

void DoubleLinkedListTest::SetUp() {

    stringArray[0] = "cat";
    stringArray[1] = "hat";
    stringArray[2] = "boo";
    stringArray[3] = "zoo";
    stringArray[4] = "feather";
    stringArray[5] = "leather";
    stringArray[6] = "cool";
    stringArray[7] = "pool";
    stringArray[8] = "hello";
    stringArray[9] = "fellow";

//    char stackSentenceA[] = "Hello DoubleLinkedList Head!";
//    char stackSentenceB[] = "Hello DoubleLinkedList Other Element!";

//    char *sentenceA  = (char *)malloc(sizeof(char) * 50);
//    char *sentenceB  = (char *)malloc(sizeof(char) * 50);

//    std::string sentenceA = "Hello DoubleLinkedList Head!";
//    std::string sentenceB = "Hello DoubleLinkedList Other Element!";
};

void DoubleLinkedListTest::TearDown() {

    destroyDoubleLinkedList(head);
};

int stringEqual(const void* stringA, const void* stringB);

TEST_F(DoubleLinkedListTest, CreateHead) {

    void* string_0_vptr = &stringArray[0];

    head = (linkDLL*)newDoubleLinkedList(string_0_vptr);

    // expected , given
    EXPECT_EQ(stringArray[0], *(std::string*)head->item);

    int indexOfValue = containsDoubleLinkedList(head, string_0_vptr, stringEqual);

    // expected , given
    EXPECT_EQ(0, indexOfValue);
}

TEST_F(DoubleLinkedListTest, AddElement) {

    void* string_0_vptr = &stringArray[0];
    void* string_1_vptr = &stringArray[1];
    void* string_2_vptr = &stringArray[2];
//    void* string_3_vptr = &stringArray[3];
//    void* string_4_vptr = &stringArray[4];
//    void* string_5_vptr = &stringArray[5];
//    void* string_6_vptr = &stringArray[6];
//    void* string_7_vptr = &stringArray[7];
//    void* string_8_vptr = &stringArray[8];
//    void* string_9_vptr = &stringArray[9];

    head = (linkDLL*)newDoubleLinkedList(string_0_vptr);
    addDoubleLinkedList(head, string_1_vptr);
    addDoubleLinkedList(head, string_2_vptr);
//    addDoubleLinkedList(head, string_3_vptr);
//    addDoubleLinkedList(head, string_4_vptr);
//    addDoubleLinkedList(head, string_5_vptr);
//    addDoubleLinkedList(head, string_6_vptr);
//    addDoubleLinkedList(head, string_7_vptr);
//    addDoubleLinkedList(head, string_8_vptr);
//    addDoubleLinkedList(head, string_9_vptr);

    // expected , given
    EXPECT_EQ(stringArray[0], *(std::string*)head->previous->next->item);
    EXPECT_EQ(stringArray[0], *(std::string*)head->next->previous->item);

    EXPECT_EQ(stringArray[1], *(std::string*)head->next->item);
    EXPECT_EQ(stringArray[1], *(std::string*)head->previous->previous->item);

    EXPECT_EQ(stringArray[2], *(std::string*)head->next->next->item);
    EXPECT_EQ(stringArray[2], *(std::string*)head->previous->item);
}


//int main(int argc, char *argv[]) {
//
//    char *sentenceA  = malloc(sizeof(char) * 50);
//    char *sentenceB  = malloc(sizeof(char) * 50);
//
//    char stackSentenceA[] = "Hello DoubleLinkedList Head!";
//    char stackSentenceB[] = "Hello DoubleLinkedList Other Element!";
//
//    strcpy(sentenceA, stackSentenceA);
//    strcpy(sentenceB, stackSentenceB);
//
//    link *head = newDoubleLinkedList(sentenceA);
//    addDoubleLinkedList(head, sentenceB);
//
//
//    printf("linked head value : %s\n", (char*)(head->item));
//
//    printf("linked index of string: %s , index : %d", sentenceB, containsDoubleLinkedList(head, sentenceB, stringEqual));
//
//    destroyDoubleLinkedList(head);
//    free(sentenceA);
//    free(sentenceB);
//}

int stringEqual(const void* stringA, const void* stringB) {

    std::string* a = (std::string*)stringA;
    std::string* b = (std::string*)stringB;

    if (a->compare(*b) != 0) {
        return 0;
    }
    return 1;
}