#include <stdio.h>

//#define p 19
//int inv[p + 1] = {-1, 1, 10, 13, 5, 4, 16, 11, 12, 17, 2, 7, 8, 3, 15, 14, 6, 9, 18};

#define p 23
int inv[p + 1] = {-1, 1, 12, 8, 6, 14, 4, 10, 3, 18, 7, 21, 2, 16, 5, 20, 13, 19, 9, 17, 15, 11, 22};

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

int c;

int fact(int a)
{
    int i, t;
    int ans = 1 % p;
    for(i = 1; i <= a; i++)
    {
        t = (i % p);
        if(t != 0) ans *= t;
        else c++;
        ans %= p;
    }
    return(ans);
}

int bin(int n, int k)
{
    int c1 = 0;
    c = 0;
    int fn = fact(n);
    c1 += c;

    c = 0;
    int f1 = fact(k);
    c1 -= c;

    c = 0;
    int f2 = fact(n - k);
    c1 -= c;

    if(c1 > 0) return(0);
    if(c1 < 0) printf("error\n");
    else return((fn * inv[f1] * inv[f2]) % p);
}

int g(n)
{
    int l, t;
    int ans = 0;
    for(l = 0; 2 * l < n + 1; l++)
    {
        t = (bin(n + 1, 2 * l) * pow1(2, l)) % p;
        ans += t;
        ans %= p;
        fprintf(stderr, "%d %d\n", l, fact(n+1));
    }

    return(ans);
}

int main()
{
#define n 10000
    printf("%d\n", g(n)); 
}
