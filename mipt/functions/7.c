#include <stdio.h>
#include "7f.c"

#define N 100

int main()
{
    int n;
    char arr[N];

    scanf("%d", &n);
    scanf("%s", arr);

    revers(arr, n);

    printf("%s\n", arr);

    return 0;
}
