#include <stdio.h>

long double r = 0;

int main()
{
    int N, i;
    scanf("%d", &N);
    for(i = 1; i <= N; i++)
        r += 1. / i;
    printf("%.40llf\n", r);

    return(0);
}
