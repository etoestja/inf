#include <stdio.h>
#include "2f.c"
#include <string.h>

#define MAXN 1000

int main()
{
    char str[MAXN];
    int v;

    scanf("%s", str);

    v = my_atoi(str);

    printf("%d", v);
}
