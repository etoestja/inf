#include <stdio.h>
#include "bsearch.h"

int main()
{
    const unsigned int N = 4;
    double arr[] = {0, 1, 2, 3, 5};
    double f;
    scanf("%lf", &f);
    double * res = bfind(arr, N, 0, N - 1, f);
    printf("%d <=> %lf <=> %d\n", res, res == 0 ? 0 : *res, res - arr);
    return(0);
}
