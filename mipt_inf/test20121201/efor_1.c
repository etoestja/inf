#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long int A, B, N, i, ans = 0;

    scanf("%lld", &A);
    scanf("%lld", &B);
    scanf("%lld", &N);

    for(i = 1; i < N; i++)
        if(((i % A) == 0) || ((i % B) == 0))
            ans += i;

    printf("%lld", ans);

    return 0;
}
