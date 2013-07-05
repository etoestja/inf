#include <stdio.h>
#include "str7f.c"

#define N 1000

int main()
{
    char arr[N], c;

    scanf("%s", arr);
    scanf(" %c", &c);

    char* f = my_strchr(arr, c);

    printf("%ld %c\n", f, f ? *f : 'x');

    return 0;
}
