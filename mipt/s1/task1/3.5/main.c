#include <stdio.h>

int main()
{
    unsigned long long i, N, ans = 1;

    scanf("%llu", &N);

    if(N < 2) return 1;

    for(i = 2; i * i <= N; i++)
        if(N % i == 0)
        {
            ans = 0;
            break;
        }

    printf("%s\n", ans ? "YES" : "NO");

    return 0;
}
