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

int ord(int a)
{
    int i;
    for(i = 1; i < p; i++)
        if(pow1(a, i) == 1)
            return(i);
}

int main()
{
    int i;
    for(i = 1; i < p; i++)
        printf("%d %d\n", i, ord(i));
    return(0);
}
