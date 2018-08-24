#ifndef SORTS_LIBRARY_H

#define SORTS_LIBRARY_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

enum STRATEGY{BUBBLE, INSERT, SELECT,  MERGE, QUICK, RADIX};


void sorts(enum STRATEGY sortStrategy, void *base, size_t nItems, size_t size, int (*compare)(const void *, const void*));

#ifdef __cplusplus
}
#endif // __cplusplus


#endif //SORTS_LIBRARY_H
