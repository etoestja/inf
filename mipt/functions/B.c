#include <stdio.h>
#include "Bf.c"

int main()
{
    int w, h;

    scanf("%d%d", &w, &h);

    fill_rectangle(w, h);

    return 0;
}
