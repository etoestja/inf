#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void * p1, const void * p2)
{
    if(*((int*) p1) == *((int*) p2)) return 0;
    return(*((int*) p1) > *((int*) p2) ? 1 : -1);
}

#define NMAX 1001
int arr[NMAX];

int main()
{
    int i, N;

    scanf("%d", &N);

    for(i = 0; i < N; i++)
        scanf("%d", &(arr[i]));

    qsort(arr, N, sizeof(int), cmp_int);

    for(i = 0; i < N; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
