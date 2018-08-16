#include "DoubleLinkedList.h"
#include "Node.h"

# include <stdlib.h>



// item a pointer to the item to add to the list
void * newDoubleLinkedList(const void *item) {

//    link *link_p = malloc(sizeof(void*));
    linkDLL *link_p = malloc(sizeof(linkDLL));

    link_p->item = item;
    link_p->next = link_p;
    link_p->previous = link_p;

    return link_p;
}

void destroyDoubleLinkedList(void *head) {

    linkDLL *headOfDLL = head;
    linkDLL *current = head;
    headOfDLL->previous->next = 0;

    while (current->next) {

        current = current->next;

        free(current->previous);
        current->previous = 0;
    }

    free(current);
    head = 0;
}

int addDoubleLinkedList(const void *head, const void *item) {

    linkDLL *headOfDLL = head;

    linkDLL *oldLastLink = headOfDLL->previous;
    linkDLL *newLastLink = malloc(sizeof(linkDLL));


    if (newLastLink) {

        newLastLink->item = item;

        headOfDLL->previous = newLastLink;
        newLastLink->next = headOfDLL;

        oldLastLink->next = newLastLink;
        newLastLink->previous = oldLastLink;

        return 1;
    }

    return 0;
}

int containsDoubleLinkedList(const void *head, const void *compareToItem, int (equal)(const void *, const void *)) {

    linkDLL *current_node = head;

    int index = 0;

    do {

        if (equal(current_node->item, compareToItem)) {

            return index;
        }

        current_node = current_node->next;
        index++;

    } while (current_node->next != head);

    return -1;
}