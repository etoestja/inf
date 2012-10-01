#include <stdio.h>

#define M (5000 + 5)
int dp[M];
int a[M], b[M], c[M];

int main()
{
    int N, i;
    for(i = 0; i < M; i++)
    {
        dp[i] = -1;
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
    }

    scanf("%d", &N);

    for(i = 1; i <= N; i++)
        scanf("%d%d%d", &(a[i]), &(b[i]), &(c[i]));

    dp[0] = 0;

    for(i = 0; i <= N; i++)
    {
        dp[i + 3] = dp[i] + c[i + 1];
        if(dp[i + 2] > dp[i] + b[i + 1] || dp[i + 2] == -1) dp[i + 2] = dp[i] + b[i + 1];
        if(dp[i + 1] > dp[i] + a[i + 1] || dp[i + 1] == -1) dp[i + 1] = dp[i] + a[i + 1];
    }

    for(i = 0; i < N + 5; i++)
        fprintf(stderr, "%d:%d\t", i, dp[i]);

    fprintf(stderr, "\n");

    printf("%d\n", dp[N]);
}

