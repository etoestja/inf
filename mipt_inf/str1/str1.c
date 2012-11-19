#include <stdio.h>
#include "str1f.c"

#define N 1000

int main()
{
    char arr[N];

    scanf("%s", arr);
    printf("%d\n", my_strlen(arr));

    return 0;
}
