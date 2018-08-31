#include <stdlib.h>
#include <time.h>
#include <printf.h>
#include <string.h>

#include "SortsHelper.h"

#include "stdio.h"

// used to swap memory addresses
// bytes in a and b, number of bytes swapped is determined by size
#define SWAP(a_ptr, b_ptr, size)                                    \
do {                                                                \
char *__a = (a_ptr), *__b = (b_ptr), __tmp;                         \
    for (size_t __size = (size); __size; __size--, __a++, __b++){   \
        __tmp =  *__a;                                              \
        *__a = *__b;                                                \
        *__b = __tmp;                                               \
    }} while(0)

typedef struct quickSortNode quickSortNode ;

struct quickSortNode {
    void *item;
    long long unsigned order;
};


static inline int compareQuickSortNode(const void *first, const void *second, int (*compare)(const void *, const void*)) {

    quickSortNode *a = *(quickSortNode**)first;
    quickSortNode *b = *(quickSortNode**)second;

    int order = compare(a->item, b->item);

    if (order != 0) return order;

    return (a->order < b->order) ? -1 : 1;
}

static int partition(void *nodes, size_t nodeSize, int start, int end, int (*compare)(const void *, const void*));

static void quickSortHelper(void *nodes, size_t nodeSize, int start, int end, int (*compare)(const void *, const void*));

void quickSortStable(void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*)) {

    size_t nodePointerSize = sizeof(quickSortNode*);
    srand(time(NULL));

    quickSortNode **nodes = malloc(nodePointerSize * nItems);
    char bytes[size * nItems];

    for (int i = 0; i < nItems; i++) {

        nodes[i] = malloc(sizeof(quickSortNode));
        nodes[i]->item = base + (size * i);
        nodes[i]->order = i;
    }

    quickSortHelper(nodes, nodePointerSize, 0, nItems - 1, compare);

    for (int i = 0; i < nItems; i++) {

        memcpy(bytes + (size * i), nodes[i]->item, size);
        free(nodes[i]);
    }

    free(nodes);
    memcpy(base, bytes, size * nItems);
}

static void quickSortHelper(void *nodes, size_t nodeSize, int start, int end, int (*compare)(const void *, const void*)) {

    if (start < end) {

        int pivot = partition(nodes, nodeSize, start, end, compare);

        quickSortHelper(nodes, nodeSize, start, pivot - 1, compare);
        quickSortHelper(nodes, nodeSize, pivot + 1, end, compare);
    }
}

static int partition(void *nodes, size_t nodeSize, int start, int end, int (*compare)(const void *, const void*)) {


    int pivot = start + rand() % (end - start + 1);

    char* pivot_ptr = nodes + (nodeSize * pivot);
    char* end_ptr = nodes + (nodeSize * end);

    // moves pivot to end
    SWAP(pivot_ptr, end_ptr, nodeSize);

    // pivot is at end;
    pivot_ptr = end_ptr;

    int i = start - 1;

    char *i_ptr;
    char *j_ptr;

    for(int j = start; j <= end ; j++ )  {

        j_ptr = nodes + (j * nodeSize);

        if (compareQuickSortNode(j_ptr, pivot_ptr, compare) < 0) {

            i++;
            i_ptr = nodes + (i * nodeSize);
            SWAP(i_ptr, j_ptr, nodeSize);
        }
    }

    i++;
    i_ptr = nodes + (i * nodeSize);
    SWAP(pivot_ptr, i_ptr, nodeSize);

    return i;
}