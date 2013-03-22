#include <stdio.h>

#define NUM 5

char find[NUM] = {0x94, 0x88, 0x01, 0x00, 0x75};
char repl = 0x74;

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

        if(p == NUM)
            printf("%c", repl);
        else
            printf("%c", c);
    }

    return(0);
}
