#include <stdlib.h>
#include <time.h>
#include "SortsHelper.h"

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

int choosePivot(int start,int end);

int partition(void *base, size_t size, int start, int end, int (*compare)(const void *, const void*));

void quickSortHelper(void *base, size_t size, int start, int r, int (*compare)(const void *, const void*));

void quickSort(void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*)) {

    srand(time(NULL));

    quickSortHelper(base, size, 0, nItems - 1, compare);

}

void quickSortHelper(void *base, size_t size, int start, int end, int (*compare)(const void *, const void*)) {

    if (start < end) {

        int pivot = partition(base, size, start, end, compare);

        quickSortHelper(base, size, start, pivot - 1, compare);
        quickSortHelper(base, size, pivot + 1, end, compare);
    }
}

int partition(void *base, size_t size, int start, int end, int (*compare)(const void *, const void*)) {


    int pivot = start + rand() % (end - start + 1);

    char* pivot_ptr = base + (size * pivot);
    char* end_ptr = base + (size * end);

    // moves pivot to end
    SWAP(pivot_ptr, end_ptr, size);

    // pivot is at end;
    pivot_ptr = end_ptr;

    int i = start - 1;

    char *i_ptr;
    char *j_ptr;

    for(int j = start; j <= end ; j++ )  {

        j_ptr = base + (j * size);

        if (compare(j_ptr, pivot_ptr) < 0) {

            i++;
            i_ptr = base + (i * size);
            SWAP(i_ptr, j_ptr, size);
        }
    }

    i++;
    i_ptr = base + (i * size);
    SWAP(pivot_ptr, i_ptr, size);

    return i;
}

//
//key_ptr = base + (l * size);
//
//SWAP(key_ptr, pivot_ptr, size);
//
//i = l + 1;
//j = r;
//
//while (i <= j) {
//
//i_ptr = base + (size * i);
//while ((i <= r) && compare(i_ptr, key_ptr) <= 0) {
//i++;
//i_ptr = base + (size * i);
//}
//
//j_ptr = base + (size * j);
//while ((j >= l) && compare(j_ptr, key_ptr) > 0) {
//j++;
//j_ptr = base + (size * j);
//}
//
//if (i < j) {
//SWAP(i_ptr, j_ptr, size);
//}
//}
//
//SWAP(pivot_ptr, i_ptr, size);
//
//quickSortHelper(base, size, l, r, compare);