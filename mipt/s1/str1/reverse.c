#include <stdio.h>
#include <string.h>

enum state {LOOKINGFOR, INWORD};

#define N 1001

void printR(char *str, int L)
{
    int i;
    for(i = L - 1; i >= 0; i--)
        printf("%c", str[i]);
}

int main()
{
    int state = LOOKINGFOR;

    char c;

    char word[N];
    int wordL = 0;

    for(; scanf("%c", &c) > 0 && (c && c != '\n' && c != '\r');)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if(state == LOOKINGFOR)
            {
                state = INWORD;
                wordL = 0;
            }
            word[wordL++] = c;
        }
        else
        {
            if(state == INWORD)
            {
                state = LOOKINGFOR;
                printR(word, wordL);
                wordL = 0;
            }
            printf("%c", c);
        }
    }

    if(wordL)
        printR(word, wordL);

    printf("\n");

    return(0);
}
