#include <stdio.h>

long long f(unsigned long long i)
{
    return(i * (i + 1) * (2 * i + 1) / 6);
}

int main()
{
    long long n, i, s;

    scanf("%llu", &n);

    for(i = 1; f(i) <= n; i++);
//        printf("trying f(%llu)=%llu\n", i + 1, f(i + 1));

    if(f(i - 1) >= n) i--;

    s = n - f(i - 1);

    printf("%lld %lld", i * (i - 1) / 2 + (s - 1) / i + 1, (s - 1) % i + 1);

}
