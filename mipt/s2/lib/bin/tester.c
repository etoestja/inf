#include <stdio.h>
#include "bsearch.h"
#include <stdlib.h>

int read_one()
{
    unsigned int i, N;
    scanf("%u", &N);
    double * arr;

    double find;
    scanf("%lf", &find);

    int index;
    scanf("%u", &index);

    arr = malloc(sizeof(double) * N);

    for(i = 0; i < N; i++)
        scanf("%lf", arr + i);

    double * res = bfind(arr, N, 0, N - 1, find);

    double c;
    if(index >= 0 && index < N) c = arr[index];

    free(arr);

    if(res == 0)
        return(index == -1 ? 0 : 1);
    else
    {
        if(index < 0 || index >= N) return(1);
        return(*res == c ? 0 : 1);
    }

    return(0);
}

int main()
{
    unsigned int i, N;
    scanf("%u", &N);
    for(i = 0; i < N; i++)
        if(read_one() == 1) return(1);
    return(0);
}
