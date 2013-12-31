#include <stdio.h>

#define NMAX (100 + 1)

int arr[NMAX][NMAX][NMAX];
int N, M, K;

int main()
{
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &K);

    int i, j, k;

    for(i = 1; i <= N; i++)
        for(j = 1; j <= M; j++)
            for(k = 1; k <= K; k++)
                scanf("%d", &(arr[i][j][k]));
    int t;

    for(i = 0; i < NMAX; i++)
        for(j = 0; j < NMAX; j++)
        {
            arr[i][j][0] = 0;
            arr[i][0][j] = 0;
            arr[0][i][j] = 0;
        }

    for(i = 1; i <= N; i++)
    {
        for(j = 1; j <= M; j++)
        {
            for(k = 1; k <= K; k++)
            {
                t =  arr[i][j][k];
                t -= arr[i - 1][j][k] + arr[i][j - 1][k] + arr[i][j][k - 1];
                t += arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] + arr[i][j - 1][k - 1];
                t -= arr[i - 1][j - 1][k - 1];
                printf("%d ", t);
            }
            printf("\n");
        }
        printf("\n");
    }
           

    return(0);
}
