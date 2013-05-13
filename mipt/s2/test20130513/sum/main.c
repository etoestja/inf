#include <stdio.h>
#include <stdint.h>

int main()
{
    uint16_t h = 0;
    char c;
    char b;
    while(scanf("%c", &c) > 0 && c != '\n')
    {
        b = h & 1;
        h >>= 1;
        h += b << (15);
        h += c;
    }

    printf("%d\n", h);

    return(0);
}
