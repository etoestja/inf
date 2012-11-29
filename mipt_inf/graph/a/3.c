#include <stdio.h>

#define NMAX 100

int arr[NMAX][NMAX];

int main()
{
    int i, j, N, M, t1, t2;

    for(i = 0; i < NMAX; i++)
        for(j = 0; j < NMAX; j++)
            arr[i][j] = 0;

    scanf("%d", &N);
    scanf("%d", &M);

    for(i = 0; i < M; i++)
    {
        scanf("%d", &t1);
        scanf("%d", &t2);
        arr[t1][t2] = arr[t2][t1] = 1;
    }

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;

}
