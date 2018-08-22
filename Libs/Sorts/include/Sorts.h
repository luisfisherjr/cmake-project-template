#ifndef SORTS_LIBRARY_H

#define SORTS_LIBRARY_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>


extern enum STRATEGY{INSERT, BUBBLE, QUICK, RADIX, MERGE};


void sorts(enum STRATEGY sortStrategy, void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*));


#ifdef __cplusplus
}
#endif // __cplusplus


#endif //SORTS_LIBRARY_H
