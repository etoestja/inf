#include <stdio.h>

int main()
{
    unsigned long long f1 = 1, f2 = 1, t, i, n;

    scanf("%llu", &n);

    for(i = 3; i <= n; i++)
    {
        t = f2;
        f2 = f1 + f2;
        f1 = t;
    }

    printf("%llu\n", f2);

    return 0;
}
