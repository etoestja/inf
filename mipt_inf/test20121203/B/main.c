#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char c;
    int d, i = 0, s1 = 0, s2 = 0;

    while(scanf("%c", &c) > 0 && c >= '0' && c <= '9')
    {
        d = c - '0';
        if(i % 2 == 0) s1 += d;
        else s2 += d;

        i++;
    }

    if(s1 > s2) d = s1 - s2;
    else d = s2 - s1;

    printf("%s", d % 11 == 0 ? "YES" : "NO");

    return 0;
}

