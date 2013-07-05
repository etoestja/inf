#include <stdio.h>

unsigned long long f(long long n)
{
    if(n <= 0) return 0;
    else if(n == 1 || n == 2) return 1;
    else return(f(n - 1) + f(n - 2));
}

int main()
{
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", f(n));
}
