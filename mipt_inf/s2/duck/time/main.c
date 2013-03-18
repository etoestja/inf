#include <stdio.h>

char find[4] = {0x00, 0xca, 0x9a, 0x3b};
char repl = 0x77;

int main()
{
    freopen("cracked", "wb", stdout);
    freopen("source", "rb", stdin);
    char c;
    char p = 0;
    while(scanf("%c", &c) > 0)
    {
        if(c != find[p]) p = 0;
        if(c == find[p])
            p++;

        if(p == 4)
            printf("%c", repl);
        else
            printf("%c", c);
    }

    return(0);
}
