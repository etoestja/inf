#include <stdio.h>
#include "str3f.c"

#define N 1000

int main()
{
    char arr[N], arr1[N];

    scanf("%s", arr);
    scanf("%s", arr1);

    printf("%d\n", my_strcmp(arr, arr1));

    return 0;
}
