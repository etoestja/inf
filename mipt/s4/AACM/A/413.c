#include <stdio.h>

#define p 23
#define x 5

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

int g(n)
{
    return((pow1(6, n + 1) + pow1(19, n + 1)) / 2);
}

int main()
{
#define n 10000
    printf("%d\n", g(n)); 
}
