#include <stdio.h>
#include <string.h>

enum state {LOOKINGFOR, INWORD};

char cap(char c)
{
    if(c >= 'a' && c <= 'z') return(c + ('A' - 'a'));
    return(c);
}

int main()
{
    int state = LOOKINGFOR;

    char c;

    for(; scanf("%c", &c) > 0 && (c && c != '\n' && c != '\r');)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if(state == LOOKINGFOR)
            {
                state = INWORD;
                c = cap(c);
            }
        }
        else
            if(state == INWORD)
                state = LOOKINGFOR;
        printf("%c", c);
    }

    printf("\n");

    return(0);
}
