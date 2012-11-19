#include <stdio.h>
#include <string.h>

enum state {LOOKINGFOR, PISPUNCT};

char punctList[] = ".,:;!?";

int isPunct(char c)
{
    char *s;
    for(s = punctList; *s; s++) if(*s  == c) return(1);
    return(0);
}

int main()
{
    int state = LOOKINGFOR;

    char c, pC;

    for(; scanf("%c", &c) > 0 && c;)
    {
        if(state == PISPUNCT)
        {
            if(c == ' ') printf("%c", pC);
            else printf("%c ", pC);
        }

        if(isPunct(c))
        {
            if(state == LOOKINGFOR)
                state = PISPUNCT;
        }
        else
        {
            if(state == PISPUNCT)
                state = LOOKINGFOR;
            printf("%c", c);
        }

        pC = c;
    }

    return(0);
}
