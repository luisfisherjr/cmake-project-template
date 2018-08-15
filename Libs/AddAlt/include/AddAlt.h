#ifndef ADDALT_LIBRARY_H

#define ADDALT_LIBRARY_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>

int addAlt(int a, int b);

int printAdd(int a, int b) {
    printf("%d + %d = %d", a, b, (a + b));
};



#ifdef __cplusplus
}
#endif // __cplusplus


#endif //ADDALT_LIBRARY_H
