#include <stdio.h>

int main()
{
    freopen("solaris.dat", "r", stdin);
    freopen("solaris.ans", "w", stdout);

    char a, b;
    int x;
    while(scanf("%c%c", &a, &b) >= 2)
        printf("%c%c", b, a);
    return(0);
}
