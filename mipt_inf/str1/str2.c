#include <stdio.h>
#include "str2f.c"

#define N 1000

int main()
{
    char arr[N], dest[N];

    scanf("%s", arr);
    my_strncpy(dest, arr, my_strlen(arr) + 1);
    printf("%s %d %d\n", dest, my_strlen(arr), my_strlen(dest));

    return 0;
}
