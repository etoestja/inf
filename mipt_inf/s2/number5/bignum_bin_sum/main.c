#include <stdio.h>

#define MAXN 2000
#define BASE 2

int scan(char* x)
{
    int c;
    char s;
    for(c = 0; scanf("%c", &s) > 0 && s >= '0'
      && s <= '1'; c++)
        x[c] = s - '0';
    return(c);
}

void print(char* x, int N)
{
    int c;
    for(c = 0; c < N; c++)
        printf("%c", x[c] + '0');
}

void printR(char* x, int N)
{
    int c;
    int printed = 0;
    for(c = N - 1; c >= 0; c--)
    {
        if(printed || x[c] != 0)
        {
            printf("%c", x[c] + '0');
            printed = 1;
        }
    }
    if(!printed) printf("0");
}

char x[MAXN];
char y[MAXN];
char z[MAXN];
int xC, yC, zC = 0;

void sum()
{
    int c, carry = 0, xP = xC - 1, yP = yC - 1, zP = 0;
    while(carry || xP >= 0 || yP >= 0)
    {
        c = carry;
        if(xP >= 0) c += x[xP--];
        if(yP >= 0) c += y[yP--];

        carry = c / BASE;
        z[zP++] = c % BASE;
    }

    zC = zP;
}

int main()
{
    xC = scan(x);
    yC = scan(y);

/*    print(x, xC);
    printf("\n");
    print(y, yC);
    printf("\n");*/

    sum();

    printR(z, zC);
    printf("\n");

    return 0;
}
