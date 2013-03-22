#include <stdio.h>

int main()
{
    int d = 0, l = 0;
    char c;

    for(; scanf("%c", &c) > 0;)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) l++;
        else if(c >= '0' && c <= '9') d++;
    }

    printf("Digits=%d\nLetters=%d\n", d, l);

    return(0);
}
