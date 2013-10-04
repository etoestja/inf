#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

#define INPUT  "input.txt"
#define OUTPUT "output.txt"

matrix a, b, c;

void doReopen()
{
    freopen(INPUT,  "r", stdin);
    freopen(OUTPUT, "w", stdout);
}

int main()
{
    doReopen();

    readMatrix(&a, 0);
    readMatrix(&b, 1);

#ifdef MULTDEBUG
    printf("A ");
    printMatrix(a);
    printf("\nB ");
    printMatrix(b);
    printf("\nC ");
#endif

    multiplyAllocateMatrices(a, b, &c);
#ifdef MULTTHREADS
    multiplyMatricesThreads(a, b, c, 4);
#endif

#ifdef MULTSIMPLE
    multiplyMatrices(a, b, c, 0, 1);
#endif

#ifdef MULTPRINT
    printMatrix(c);
#endif

    freeMatrix(&a);
    freeMatrix(&b);
    freeMatrix(&c);

    return(0);
}
