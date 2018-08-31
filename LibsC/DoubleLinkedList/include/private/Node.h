#ifndef DOUBLELINKEDLIST_NODE_H

#define DOUBLELINKEDLIST_NODE_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct node linkDLL;

struct node {
    void *item;
    linkDLL *next;
    linkDLL *previous;
};

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //DOUBLELINKEDLIST_NODE_H
