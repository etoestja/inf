#include <stdio.h>
#include "8f.c"

#define N 100

int main()
{
    char a[N], b[N], c[N];

    scanf("%s", a);
    scanf("%s", b);

    add(a, b, c);

    printf("%s\n",c);

    return 0;
}
