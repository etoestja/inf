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

    readMatrix(&a);
    readMatrix(&b);

#ifdef DEBUG
    printf("A ");
    printMatrix(a);
    printf("\nB ");
    printMatrix(b);
    printf("\nC ");
#endif

    multiplyAllocateMatrices(a, b, &c);
    multiplyMatrices(a, b, c, 0, 23);

    printMatrix(c);

    return(0);
}
