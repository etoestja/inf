#include <stdio.h>
#include "4f.c"

int main()
{
    int x, y;
    char c;

    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%c", &c);

    draw_rectangle(y, x, c);

    return 0;
}
