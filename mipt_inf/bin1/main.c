#include <stdio.h>

int main(void)
{
    unsigned int a, b, r;
    char c;

    scanf("%d%c%d", &a, &c, &b);

    r = (c == '^' ? a & b : a | b);

    printf("%d", r ? 1 : 0);

    return 0;
}

