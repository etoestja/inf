#include <stdio.h>

int main()
{
    int x, y;

    scanf("%d", &x);
    scanf("%d", &y);

    if(y > x) x = y;

    printf("%d\n", x);

    return 0;
}
