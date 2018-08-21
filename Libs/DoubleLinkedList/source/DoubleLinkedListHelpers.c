#include <stdlib.h>

#include "DoubleLinkedListHelpers.h"



int addLastDLL(const void *item, DoubleLinkedList *thisList) {

    linkDLL *headOfDLL  = thisList->head;

    linkDLL *newLastLink = malloc(sizeof(linkDLL));

    if (newLastLink) {

        if (headOfDLL) {

            linkDLL *oldLastLink = headOfDLL->previous;

            newLastLink->item = item;

            headOfDLL->previous = newLastLink;
            newLastLink->next = headOfDLL;

            oldLastLink->next = newLastLink;
            newLastLink->previous = oldLastLink;

            thisList->nodeCount++;

        }
        else {

            newLastLink->item = item;
            newLastLink->next = newLastLink;
            newLastLink->previous = newLastLink;

            thisList->head = newLastLink;
            thisList->nodeCount++;
        }

        return 1;
    }

    return 0;
}



int addFirstDLL(const void *item, DoubleLinkedList *thisList) {

    int isAdded = addLastDLL(thisList, item);

    if (isAdded) {

        thisList->head = ((linkDLL*)thisList->head)->previous;
    }

    return isAdded;

}

// removes and destroys last link in list before the head, returns item
void* removeLast(DoubleLinkedList *thisList) {

    if (thisList->nodeCount < 1) return NULL;

    void *item = NULL;
    linkDLL *toRemove = thisList->head;

    if (thisList->nodeCount > 1) {

        toRemove = toRemove->previous;

        toRemove->previous->next = toRemove->next;
        toRemove->next->previous = toRemove->previous;
    }
    else {

        thisList->head = NULL;
    }

    thisList->nodeCount--;
    item = toRemove->item;
    free(toRemove);

    return item;
}

// removes and destroys head, returns item
void* removeFirst(DoubleLinkedList *thisList) {

    thisList->head = ((linkDLL*)thisList->head)->next;

    return removeLast(thisList);
}

int sizeDLL(DoubleLinkedList *thisList) {
    return thisList->nodeCount;
}

int containsDLL(const void * item, DoubleLinkedList *thisList) {

    linkDLL *head = thisList->head;
    linkDLL *current_node = head;

    int index = 0;

    do {

        if (thisList->comparator(item, current_node->item)) {

            return index;
        }

        current_node = current_node->next;
        index++;

    } while (current_node->next != head);

    return -1;
}

void* getDLL(int index, DoubleLinkedList *thisList) {

    int nodeCount = thisList->nodeCount;

    if (index < nodeCount && index > -1) {

        linkDLL *current_node = thisList->head;

        int currentIndex = 0;

        if (index < (nodeCount / 2)) {

            while (currentIndex < index) {

                current_node = current_node->next;
                currentIndex++;

            }

        }
        else {

            currentIndex = nodeCount - index;

            while (currentIndex >= 0) {

                current_node = current_node->previous;
                currentIndex--;

            }

        }

        return current_node->item;
    }

    // out of range
    return 0;
}


void clearDLL(DoubleLinkedList *thisList) {

    linkDLL *headOfDLL = thisList->head;
    linkDLL *current = thisList->head;

    if (!headOfDLL) return;

    headOfDLL->previous->next = 0;

    // frees memory of linkDLL structs
    while (current->next) {

        current = current->next;

        free(current->previous);
        current->previous = 0;
    }

    free(current);
}

int pushDLL(const void * item, DoubleLinkedList *thisList) {

    return addLastDLL(item, thisList);
}

void* popDLL(DoubleLinkedList *thisList) {

    return removeLast(thisList);
}

void* peekStackDLL(DoubleLinkedList *thisList) {

    return getDLL(thisList->nodeCount - 1, thisList);
}



int offerDLL(const void * item, DoubleLinkedList *thisList) {

    return addLastDLL(item, thisList);
}

void* pollDLL(DoubleLinkedList *thisList) {

    return removeFirst(thisList);
}

void* peekQueueDLL(DoubleLinkedList *thisList) {

    return getDLL(0, thisList);
}