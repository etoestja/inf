#include <stdio.h>

long double r = 0;

#define BASE (1 << 32)

int main()
{
    int N, i;
    scanf("%d", &N);
    for(i = N; i >= 1; i--)
        r += ((long double) 1.) / ((long double) i);
    printf("%.40llf\n", r);

    return(0);
}
