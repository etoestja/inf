#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    unsigned long long N, L, S;
    scanf("%llu", &N);
    scanf("%llu", &L);
    scanf("%llu", &S);

    printf("%s\n", L * L <= N * S * S ? "YES" : "NO");
    return(0);
}
