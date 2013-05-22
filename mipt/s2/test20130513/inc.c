#include <stdio.h>
#include <string.h>

#define MLEN (100000 + 5)

char s[MLEN];
int base;
int sLen;

int charToNum(char c)
{
    if(c >= '0' && c <= '9') return(c - '0');
    else return(c - 'A' + 10);
}

char numToChar(int c)
{
    if(c <= 9) return(c + '0');
    return(c + 'A' - 10);
}

int main()
{
    scanf("%s", s);
    scanf("%d", &base);
    sLen = strlen(s);
    

//    printf("%s %d\n", s, base);
    int p = 1;
    int i;
    int cDigit;
    for(i = sLen - 1; i >= 0; i--)
    {
        cDigit = charToNum(s[i]) + p;
        s[i] = numToChar(cDigit % base);
	p = cDigit / base;
    }

    if(p > 0)
        printf("%c", numToChar(p));

    char* sr = s;
    while(*sr == '0') sr++;

    if(strlen(sr) == 0) printf("0\n");
    else printf("%s\n", sr);

    return(0);
}
