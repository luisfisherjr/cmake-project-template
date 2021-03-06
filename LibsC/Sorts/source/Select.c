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

void selectSort(void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*)) {

    int iMin;

    char *i_ptr;
    char *iMin_ptr;
    char *j_ptr;

    for (int i = 0; i < nItems - 1; i++) {

        i_ptr = base + (i * size);
        iMin = i;

        for (int j = i + 1; j < nItems; j++) {

            iMin_ptr = base + (iMin * size);
            j_ptr = base + (j * size);

            if (compare(iMin_ptr, j_ptr) > 0) {

                iMin = j;
            }
        }

        if (iMin != i) {

            iMin_ptr = base + (iMin * size);

            SWAP(iMin_ptr, i_ptr, size);
        }
    }
}