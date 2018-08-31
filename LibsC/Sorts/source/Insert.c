#include <stdlib.h>
#include <string.h>
#include "SortsHelper.h"

void insertSort(void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*)) {

    char *j_ptr;
    char *j1_ptr;
    char *temp_ptr = malloc(sizeof(size));

    int j;

    for (int i = 1; i < nItems; i++) {

        j_ptr = base + (i * size), size;

        memcpy(temp_ptr, j_ptr, size);

        j = i - 1;

        j_ptr = base + (j * size);

        while(j >= 0 &&  compare(j_ptr, temp_ptr) > 0) {

            j1_ptr = base + ((j + 1) * size);
            memcpy(j1_ptr, j_ptr, size);
            j--;

            j_ptr = base + (j * size);
        }

        j1_ptr = base + ((j + 1) * size);

        memcpy(j1_ptr, temp_ptr, size);
    }

    free(temp_ptr);
}