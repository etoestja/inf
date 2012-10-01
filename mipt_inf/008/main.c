#include <stdio.h>

int main()
{
    int openers = 0, answer = 1;

    char c;

    while(scanf("%c", &c) == 1)
    {
        if(c == '(') openers++;
        else if(c == ')')
        {
            if(openers <= 0) answer = 0;
            openers--;
        }
    }

    if(openers) answer = 0;

    printf("%s", answer ? "YES" : "NO");

    return 0;
}
