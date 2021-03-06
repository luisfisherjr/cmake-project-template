#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SortsHelper.h"

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(void *base, size_t size, int l, int m, int r, int (*compare)(const void *, const void*));

void mergeSortHelper(void *base, size_t size, int l, int r, int (*compare)(const void *, const void*));

void mergeSort(void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*)) {

    int l = 0;
    int r = nItems - 1;

    mergeSortHelper(base, size, l, r, compare);
}


void mergeSortHelper(void *base, size_t size, int l, int r, int (*compare)(const void *, const void*)) {

    if (l < r) {
        
        int m = l + (r - l) / 2; //Same as (l+r)/2 but avoids overflow for large l & h //TODO review this

        mergeSortHelper(base, size, l, m, compare);
        mergeSortHelper(base, size, m + 1, r, compare);

        merge(base, size, l, m, r, compare);
    }
}

void merge(void *base, size_t size, int l, int m, int r, int (*compare)(const void *, const void*)) {

    int leftSize = m - l + 1;
    int rightSize = r - m;

    char *base_ptr = base;

    // base pointers to temp holders
    char *leftBase_ptr = malloc(size * leftSize);
    char *rightBase_ptr = malloc(size * rightSize);

//    printf("\n");
//    printf("leftSide: \n");
    for(int i = 0; i < leftSize; i++) {
        memcpy(leftBase_ptr + (size * i), base_ptr + (size * (l + i)), size);
//        printf(" %d", *(int*)(leftBase_ptr + (size * i)));
    }

//    printf("\n");
//    printf("rightSide: \n");
    for(int i = 0; i < rightSize; i++) {
        memcpy(rightBase_ptr + (size * i), base_ptr + (size * (m + i + 1)), size);
//        printf(" %d", *(int*)(rightBase_ptr + (size * i)));
    }
//    printf("\n");

    int leftIndex = 0;
    int rightIndex = 0;
    int baseIndex = l;

    char* left_ptr;
    char* right_ptr;
    char* combined_ptr;

    while (leftIndex < leftSize && rightIndex < rightSize) {

        combined_ptr = base_ptr + (size * baseIndex);
        left_ptr = leftBase_ptr + (size * leftIndex);
        right_ptr = rightBase_ptr + (size * rightIndex);

        if (compare(left_ptr, right_ptr) <= 0) {

            memcpy(combined_ptr, left_ptr, size);
            leftIndex++;
        } else {

            memcpy(combined_ptr, right_ptr, size);
            rightIndex++;
        }

        baseIndex++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (leftIndex < leftSize) {

        combined_ptr = base_ptr + (size * baseIndex);
        left_ptr = leftBase_ptr + (size * leftIndex);

        memcpy(combined_ptr, left_ptr, size);

        leftIndex++;
        baseIndex++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (rightIndex < rightSize) {

        combined_ptr = base_ptr + (size * baseIndex);
        right_ptr = rightBase_ptr + (size * rightIndex);

        memcpy(combined_ptr, right_ptr, size);

        rightIndex++;
        baseIndex++;
    }

    free(leftBase_ptr);
    free(rightBase_ptr);
}