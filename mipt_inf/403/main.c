#include <stdio.h>

int main(void)
{
    long long a, b, r;
    char c, c1;

    scanf("%lld", &a);
    scanf("%c", &c1);
    scanf("%c", &c);
    scanf("%c", &c1);
    scanf("%lld", &b);

    if(c == '*')
        r = a * b;
    else if(c == '/')
        r = a / b;
    else if(c == '+')
        r = a + b;
    else if(c == '-')
        r = a - b;
    else r = 0;

    printf("%lld\n", r);

    return 0;
}

