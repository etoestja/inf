#include <stdio.h>

#define N 100

int arr[N][N];

void main()
{
    unsigned int i, si;
    for(i = 0; i < N; i++)
        for(si = 0; si < N; si++) arr[i][si] = -1;

    arr[0][N - 1] = 100;
    arr[0][1] = 1;
    arr[1][2] = 1;
    arr[2][3] = 1;
    arr[3][N - 1] = 1;

    printf("%d %d %d\n", N, 1, N);

    for(i = 0; i < N; i++)
    {
        for(si = 0; si < N; si++)
            printf("%d ", i == si ? 0 : arr[i][si]);
        printf("\n");
    }
}
