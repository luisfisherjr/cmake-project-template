#ifndef DOUBLELINKEDLIST_LIBRARY_H

#define DOUBLELINKEDLIST_LIBRARY_H

#ifdef __cplusplus
extern "C"
{
#endif


void* newDoubleLinkedList(const void *item);

void destroyDoubleLinkedList(void *head);

int addDoubleLinkedList(const void *head, const void *item);

int containsDoubleLinkedList(const void *head, const void *compareToItem, int (equal)(const void *, const void *));

#ifdef __cplusplus
}
#endif // __cplusplus


#endif //DOUBLELINKEDLIST_LIBRARY_H
