#include <stdio.h>

int main()
{
    unsigned long long N, L, S;
    scanf("%llu", &N);
    scanf("%llu", &L);
    scanf("%llu", &S);

    printf("%s", L * L <= N * S * S ? "YES" : "NO");
    return(0);
}
