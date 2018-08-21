#include <stdlib.h>

#include "DoubleLinkedList.h"
#include "DoubleLinkedListHelpers.h"

void * newDoubleLinkedList(int (*comparator)(const void *, const void *)) {

    DoubleLinkedList *linkedList = malloc(sizeof(DoubleLinkedList));

    linkedList->comparator = comparator;
    linkedList->head = NULL;
    linkedList->nodeCount = 0;

    //*** list functions ***
    linkedList->size = sizeDLL;
    linkedList->clear = clearDLL;
    linkedList->contains = containsDLL;
    linkedList->get = getDLL;

    //*** stack functions ***
    linkedList->push = pushDLL;
    linkedList->pop = popDLL;
    linkedList->peekStack = peekStackDLL;

    //*** queue functions ***
    linkedList->offer = offerDLL;
    linkedList->poll = pollDLL;
    linkedList->peekQueue = peekQueueDLL;

    return linkedList;
}

void destroyDoubleLinkedList(DoubleLinkedList *linkedList) {

    clearDLL(linkedList);
    free(linkedList);
}