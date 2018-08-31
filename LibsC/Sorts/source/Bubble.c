#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

void bubbleSort(void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*)) {

    char *a_ptr;
    char *b_ptr;

    for (int i = 0; i < nItems - 1; i++) {

        for (int j = 0; j < nItems - i - 1; j++) {

            a_ptr = base + (j * size);
            b_ptr = base + ((j + 1) * size);

            if (compare(a_ptr, b_ptr) > 0) {

                SWAP(a_ptr, b_ptr, size);
            }
        }
    }
}