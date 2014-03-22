#include <stdio.h>
#include "myvector.h"

#define N 10

#define print_all(a) {\
    if(myvectorIteratorSetBegin(&itBegin, &a))\
        fprintf(stderr, "Error creating iterator\n");\
    \
    if(myvectorIteratorSetEnd(&itEnd, &a))\
        fprintf(stderr, "Error creating iterator\n");\
    \
    for(it = itBegin; myvectorIteratorCmp(&it, &itEnd) == MICR_LESS; myvectorIteratorPP(&it))\
    {\
        if(myvectorIteratorGet(&it, &value))\
            fprintf(stderr, "Can't get value from iterator\n");\
        printf("%d\t", value);\
    }\
    printf("\n");\
}

int main(void)
{
    myvector a;
    if(myvectorCreate(&a, N))
    {
        fprintf(stderr, "Error creating array\n");
    }

    int i;
    for(i = 0; i < N; i++)
        if(myvectorAssign(&a, i, i))
            fprintf(stderr, "Error assigning %d\n", i);

    myvectorIterator itBegin, itEnd, it;
    MYVECTOR_TYPE value;

    print_all(a);

    myvectorResize(&a, N / 2);

    print_all(a);

    if(myvectorAssign(&a, N / 2, 1))
        fprintf(stderr, "Can't assign I!\n");

    myvectorResize(&a, N);

    if(myvectorAssign(&a, N / 2, 1))
        fprintf(stderr, "Can't assign II!\n");

    print_all(a);

    MYVECTOR_TYPE *valuePtr;
    if(myvectorAt(&a, N / 2 + 10, &valuePtr))
        fprintf(stderr, "At I failed!\n");
    else
        printf("got %d\n", *valuePtr);

    if(myvectorAt(&a, N / 2 + 1, &valuePtr))
        fprintf(stderr, "At I failed!\n");
    else
        printf("got %d\n", *valuePtr);

    return 0;
}

