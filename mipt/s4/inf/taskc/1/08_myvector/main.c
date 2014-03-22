#include <stdio.h>
#include "myvector.h"

#define N 100

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
    if(myvectorIteratorSetBegin(&itBegin, &a))
        fprintf(stderr, "Error creating iterator\n");

    if(myvectorIteratorSetEnd(&itEnd, &a))
        fprintf(stderr, "Error creating iterator\n");

    MYVECTOR_TYPE value;
    for(it = itBegin; myvectorIteratorCmp(&it, &itEnd) == MICR_LESS; myvectorIteratorPP(&it))
    {
        if(myvectorIteratorGet(&it, &value))
            fprintf(stderr, "Can't get value from iterator\n");
        printf("%d\n", value);
    }

    return 0;
}

