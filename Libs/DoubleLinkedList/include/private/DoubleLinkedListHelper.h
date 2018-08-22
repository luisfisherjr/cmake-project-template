

#ifndef DOUBLELINKEDLIST_HELPER_H

#define DOUBLELINKEDLIST_HELPER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "DoubleLinkedList.h"
#include "Node.h"


// add element as new tail
int addLastDLL(const void *item, DoubleLinkedList *thisList);

// add element as new head
int addFirstDLL(const void *item, DoubleLinkedList *thisList);

// removes/returns tail element
void* removeLast(DoubleLinkedList *thisList);

// removes/returns head element
void* removeFirst(DoubleLinkedList *thisList);

// returns size of list
int sizeDLL(DoubleLinkedList *thisList);

// removes all elements in linked list
void clearDLL(DoubleLinkedList *thisList);

// returns first index that an element searched in appears in, -1 if not in list
int containsDLL(const void * item, DoubleLinkedList *thisList);

// returns the element at specified index, returns NULL if value not in range
void* getDLL(int index, DoubleLinkedList *thisList);

// ***stack operations***
int pushDLL(const void * item, DoubleLinkedList *thisList);
void* popDLL(DoubleLinkedList *thisList);
void* peekStackDLL(DoubleLinkedList *thisList);


// ***queue operations***
int offerDLL(const void * item, DoubleLinkedList *thisList);
void* pollDLL(DoubleLinkedList *thisList);
void* peekQueueDLL(DoubleLinkedList *thisList);


#ifdef __cplusplus
}
#endif // __cplusplus



#endif //DOUBLELINKEDLIST_HELPER_H
