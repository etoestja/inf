#include <stdio.h>

#define p 23

int pow1(int a, int n)
{
    if(n == 0) return(1 % p);
    else if(n % 2 == 0)
    {
        int m = pow1(a, n / 2);
        return((m * m) % p);
    }
    else return((a * pow1(a, n - 1)) % p);
}

int prime(int a, int b)
{
    int t;
    for(t = 2; t <= a && t <= b; t++)
        if(((a % t) == 0) && ((b % t) == 0)) return(0);
    return(1);
}

int phi(int n)
{
    int i;
    int ans = 0;
    for(i = 1; i < n; i++)
        if(prime(i, n)) ans++;
    return(ans);
}

#define N 70

int main()
{
    int i;
    for(i = 2; i < N; i++)
        if(phi(i) == 8)
            printf("%d\n", i);
    return(0);
}
