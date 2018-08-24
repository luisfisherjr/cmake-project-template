#include <stdlib.h>

#include "Sorts.h"
#include "SortsHelper.h"

void sorts(enum STRATEGY sortStrategy, void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*)) {

    switch (sortStrategy) {

        case BUBBLE:
            bubbleSort(base, nItems, size, compare);
            break;

        case SELECT:
            selectSort(base, nItems, size, compare);
            break;

        case SELECT_STABLE:
            selectSortStable(base, nItems, size, compare);
            break;

        case INSERT:
            insertSort(base, nItems, size, compare);
            break;
            
        case MERGE:
            mergeSort(base, nItems, size, compare);
            break;
            
        case QUICK:
            quickSort(base, nItems, size, compare);
            break;

        case RADIX:
            quickSort(base, nItems, size, compare);
            break;
    }
}