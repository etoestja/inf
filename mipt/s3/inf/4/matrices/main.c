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

    readMatrix(&a, 0, 0, NULL);
    readMatrix(&b, 1, 0, NULL);

#ifdef MULTPROCESSES
    multiplyAllocateMatrices(a, b, &c, 1, "main.c");
    multiplyMatricesProcesses(a, b, c, 4);
#endif

#ifdef MULTTHREADS
    multiplyAllocateMatrices(a, b, &c, 0, NULL);
    multiplyMatricesThreads(a, b, c, 4);
#endif

#ifdef MULTSIMPLE
    multiplyAllocateMatrices(a, b, &c, 0, NULL);
    multiplyMatrices(a, b, c, 0, 1);
#endif

#ifdef MULTPRINT
#ifdef MULTDEBUG
    printf("A ");
    printMatrix(a);
    printf("\nB ");
    printMatrix(b);
    printf("\nC ");
#endif
    printMatrix(c);
#endif

    freeMatrix(&a);
    freeMatrix(&b);
    freeMatrix(&c);

    return(0);
}
