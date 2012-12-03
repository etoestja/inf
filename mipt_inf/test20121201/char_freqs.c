#include <stdio.h>

#define NMAX 255

int ans[NMAX];

int main()
{
    int i;
    for(i = 0; i < NMAX; i++)
        ans[i] = 0;

    char c;
    while(scanf("%c", &c) > 0 && c != '\r' && c != '\n' && c != 0)
        ans[(unsigned char) c]++;

    for(i = 0; i < NMAX; i++)
        if(ans[i])
            printf("%c %d\n", (char) i, ans[i]);

    return 0;
}
