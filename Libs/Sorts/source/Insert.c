#include <stdlib.h>
#include "SortsHelper.h"

// used to swap memory addresses
// bytes in a and b, number of bytes swapped is determined by size
#define REPLACE(a_ptr, b_ptr, size)                                 \
do {                                                                \
    char *__a = (a_ptr), *__b = (b_ptr), __tmp;                     \
    for (size_t __size = (size); __size; __size--, __a++, __b++){   \
        *__a = *__b;                                                \
    }} while(0)

//TODO may not be doable
void insertSort(void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*)) {

    char *base_ptr = base;

    char *j_ptr;
    char *j1_ptr;
    char *temp_ptr = malloc(sizeof(size));

    int j;

    for (int i = 1; i < nItems; i++) {

        j_ptr = base_ptr + (i * size), size;

        REPLACE(temp_ptr, j_ptr, size);

        j = i - 1;

        j_ptr = base_ptr + (j * size);

        while(j >= 0 &&  compare(j_ptr, temp_ptr) > 0) {

            j1_ptr = base_ptr + ((j + 1) * size);
            REPLACE(j1_ptr, j_ptr, size);
            j--;

            j_ptr = base_ptr + (j * size);
        }

        j1_ptr = base_ptr + ((j + 1) * size);
//        REPLACE(j1_ptr, temp_ptr, size);

        REPLACE(j1_ptr, temp_ptr, size);
    }
}


//#include <stdlib.h>
//#include <string.h>
//
//// Function GenInsertSort
//void insertSort(void *base, size_t num, size_t size, int (*compare)(const void*, const void*)) {
//
//    char *temp = malloc(size);
//
//    char *i = (char*)base + size, *j;
//
//    for(; --num; i += size) {
//
//        memcpy(temp, i, size);
//        for(j = i - size; j - (char*)base >= 0 && compare(temp, j); j-=size)
//            memmove(j + size, j, size);
//        memcpy(j + size, temp, size);
//    }
//    free(temp);
//}