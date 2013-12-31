#include <stdio.h>

int main()
{
    double power = 1;
    double res = 0;

    char c;
    int x;

    while(scanf("%c", &c) == 1)
    {
        if(c == '(') power *= 0.5;
        else if(c == ')') power /= 0.5;
        else if((c >= '0' && c <= '9') || c == '-')
        {
            ungetc(c, stdin);
            scanf("%d", &x);
            res += x * power;
        }
    }

    printf("%lf", res);

    return 0;
}
