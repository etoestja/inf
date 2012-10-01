#include <stdio.h>

double read()
{
    double res = 0;

    int x;
    char c = 0;

    scanf("%d", &x);
    scanf("%c", &c);

    if(c == '(')
    {
        res = read() / 2.;
    //    scanf("%c", &c);
        res += read() / 2.;
        scanf("%c", &c);
    }
    else res = x;

    return(res);
}

int main()
{
    printf("%lf", read());

    return 0;
}
