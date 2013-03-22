#include <stdio.h>

#define M (5000 + 5)
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
        scanf("%d%d%d", &(a[i]), &(b[i]), &(c[i]));

    dp[0] = a[0];

    for(i = 0; i < N; i++)
    {
        if(i > 0 && dp[i] > a[i] + dp[i - 1]) dp[i] = a[i] + dp[i - 1];

        dp[i + 3] = dp[i + 2] + a[i + 3];
        if(dp[i + 2] > dp[i + 1] + b[i + 2]) dp[i + 2] = dp[i + 1] + b[i + 2];
        if(dp[i + 1] > dp[i] + c[i + 1]) dp[i + 1] = dp[i] + c[i + 1];
    }

    printf("%d\n", dp[N - 1]);
}
