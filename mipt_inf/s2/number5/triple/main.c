#include <stdio.h>

#define LEN 100
#define BASE 3

int power(int a, int b)
{
    int res = 1;
    for(; b; b--) res *= a;
    return(res);
}

int main()
{
    int res = 0, p = 0, c;
    char x[LEN], s;

    while(scanf("%c", &s) > 0
     && s >= '0' && s <= (BASE + '0'))
        x[p++] = s - '0';

    if(p == 0) printf("0\n");

    for(c = 0; c < p; c++)
        res += power(BASE, p - c - 1) * x[c];

    if(p != 0) printf("%d\n", res);

    return 0;
}
