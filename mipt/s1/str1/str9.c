#include <stdio.h>
#include "str9f.c"

#define N 1000

int main()
{
    char arr[N], substr[N];

    scanf("%s", arr);
    scanf("%s", substr);

    char* f = my_strstr(arr, substr);

    printf("%ld %s\n", f, f ? f : "-NULL-");

    return 0;
}
