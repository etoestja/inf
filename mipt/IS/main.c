#include <stdio.h>

#define M 24

#define MAXP 2
int P[MAXP] = {2, 3};

//24 = 6*4 = 2^3 * 3

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);

    long long x, y;
    scanf("%lld", &x);
    scanf("%lld", &y);

    x += y;
    y = M;

    fprintf(stderr, "a*%lld=b*%lld\n", x, y);

    int p, i;
    for(p = 0; p < MAXP; p++)
        while(((x % P[p]) == 0) && ((y % P[p]) == 0))
        {
            x /= P[p];
            y /= P[p];
        }

    // ax = by => b = x

    fprintf(stderr, "a*%lld=b*%lld\n", x, y);
    fprintf(stderr, "a=%lld\n", y);

    printf("%lld\n", y * 2);

    return(0);
}
