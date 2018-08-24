#include "SortsHelper.h"

// used to swap memory addresses
// bytes in a and b, number of bytes swapped is determined by size
#define SWAP(a_ptr, b_ptr, size)                                    \
    char *__a = (a_ptr), *__b = (b_ptr), __tmp;                     \
    for (size_t __size = (size); __size; __size--, __a++, __b++){   \
        __tmp =  *__a;                                              \
        *__a = *__b;                                                \
        *__b = __tmp;                                               \
    }

void selectSort(void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*)) {

    char *base_ptr = base;

    int iMin;

    char *iMin_ptr;
    char *j_ptr;

    for (int i = 0; i < nItems - 1; i++) {

        iMin = i;

        for (int j = i + 1; j < nItems; j++) {

            iMin_ptr = base_ptr + (iMin * size);
            j_ptr = base_ptr + (j * size);

            if (compare(iMin_ptr, j_ptr) > 0) {

                iMin = j;
            }
        }

        if (iMin != i) {

            SWAP(base_ptr + (iMin * size), base_ptr + (i * size), size);
        }
    }
}