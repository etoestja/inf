#include <stdio.h>

#define M (5000 + 10)
int dp[M];
int a[M], b[M], c[M];

int main()
{
    int N, i;
    for(i = 0; i < M; i++)
    {
        dp[i] = 3600 * M;
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
    }

    scanf("%d", &N);

    for(i = 0; i < N; i++)
        scanf("%d%d%d", &(a[i + 3]), &(b[i + 3]), &(c[i + 3]));

    a[0] = b[0] = c[0] = 0;
    a[1] = b[1] = c[1] = 0;
    a[2] = b[2] = c[2] = 0;

    dp[0] = dp[1] = dp[2] = 0;

    for(i = 0; i < N + 3; i++)
    {
      dp[i + 3] = dp[i] + c[i + 1];
      if(dp[i + 2] > dp[i] + b[i + 1]) dp[i + 2] = dp[i] + b[i + 1];
      if(dp[i + 1] > dp[i] + a[i + 1]) dp[i + 1] = dp[i] + a[i + 1];
    }

    for(i = 0; i < N + 5; i++)
        printf("%d:%d\t", i, dp[i]);

    printf("\n");

    printf("%d\n", dp[N]);
}
