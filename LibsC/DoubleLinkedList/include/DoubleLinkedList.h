#ifndef DOUBLELINKEDLIST_LIBRARY_H

#define DOUBLELINKEDLIST_LIBRARY_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "Node.h"

typedef struct DoubleLinkedList DoubleLinkedList;

struct DoubleLinkedList {

    // pointer to the head of the list
    void *head;

    // number of nodes in list
    int nodeCount;

    // used to compare elements
    int (*comparator)(const void *, const void *);

    // ***linked list operations***

    // returns size of list
    int (*size)(DoubleLinkedList *thisList);

    // removes all elements in linked list
    void (*clear)(DoubleLinkedList *thisList);

    // returns first index that an element searched in appears in, -1 if not in list
    int (*contains)(const void *item, DoubleLinkedList *thisList);

    // returns the element at specified index, returns NULL if value not in range
    void* (*get)(int index, DoubleLinkedList *thisList);

    // ***stack operations*** FILO
    int (*push)(const void * item, DoubleLinkedList *thisList);
    void* (*pop)(DoubleLinkedList *thisList);
    void* (*peekStack)(DoubleLinkedList *thisList);


    // ***queue operations*** FIFO
    int (*offer)(const void * item, DoubleLinkedList *thisList);
    void* (*poll)(DoubleLinkedList *thisList);
    void* (*peekQueue)(DoubleLinkedList *thisList);

};

// create a new double linked list, comparator is needed for contains to work correctly
void* newDoubleLinkedList(int (*comparator)(const void *, const void *));

// destroy double linked list, does not destroy the items in the list as they are referenced using pointers
void destroyDoubleLinkedList(DoubleLinkedList *linkedList);

#ifdef __cplusplus
}
#endif // __cplusplus


#endif //DOUBLELINKEDLIST_LIBRARY_H
