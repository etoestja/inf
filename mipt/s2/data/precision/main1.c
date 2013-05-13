#include <stdio.h>

long double r = 0;

#define BASE (1 << 32)

int main()
{
    int N, i;
    scanf("%d", &N);
    for(i = 1; i <= N; i++)
        r += ((long double) 1.) / ((long double) i);
    printf("%.40llf\n", r);

    return(0);
}
