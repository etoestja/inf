#include <stdio.h>

int g(int n)
{
    int a = 1;
    int b = 3;

    if(n == 0) return(a);
    if(n == 1) return(b);

    int i, bt;
    for(i = 2; i <= n; i++)
    {
        bt = 2 * b + a;
        a = b;
        b = bt;
    }

    return(b);
}

int main()
{
    int i;
    int N = 10;
    for(i = 0; i <= N; i++)
        printf("%d: %d\n", i, g(i));
    return(0);
}
