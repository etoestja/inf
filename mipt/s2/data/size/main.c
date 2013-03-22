#include <stdio.h>

char x;

long double convert(long double a)
{
    if(x == 'f')
        return((float) a);
    else if(x == 'l')
        return((long double) a);
    else if(x == 'd')
        return((double) a);
}

int test()
{
    long double y = 0.5;
    long double d = 2;
    int r;
    for(r = 0; convert(1 + y) != 1; r++)
        y /= d;
    return(r);
}

int main()
{
    scanf("%c", &x);
    printf("%d\n", test());
    return(0);
}
