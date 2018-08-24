

#ifndef SORTS_HELPER_H

#define SORTS_HELPER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>
void bubbleSort(void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*));

void insertSort(void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*));

void selectSort(void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*));

void mergeSort(void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*));

void quickSort(void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*));

//void radixSort(void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*));


#ifdef __cplusplus
}
#endif // __cplusplus



#endif //SORTS_HELPER_H
