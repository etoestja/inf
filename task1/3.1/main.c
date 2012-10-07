#include <stdio.h>

int main()
{
    unsigned long long n, i;
    long long current, max;

    scanf("%llu", &n);

    if(n)
        scanf("%lld", &max);

    for(i = 1; i < n; i++)
    {
        scanf("%lld", &current);
        if(current > max) max = current;
    }

    printf("%lld\n", max);

    return 0;
}
