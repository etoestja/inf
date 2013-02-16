#include <stdio.h>

#define MAXN 1000

int scan(char* x)
{
    int c;
    char s;
    for(c = 0; scanf("%c", &s) > 0 &&
        (s == '1' || s == '$' || s == '0'); c++)
    {
        if(s != '$') x[c] = s - '0';
        else x[c] = -1;
    }
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
            if(x[c] == -1)
                printf("$");
            else
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
    int q;
    while(carry || xP >= 0 || yP >= 0)
    {
        c = carry;
        if(xP >= 0) c += x[xP--];
        if(yP >= 0) c += y[yP--];

        if(c == -3)
        {
            carry = -1;
            q = 0;
        }
        else if(c == -2)
        {
            carry = -1;
            q = 1;
        }
        else if(c == -1)
        {
            carry = 0;
            q = -1;
        }
        else if(c == 0)
        {
            carry = 0;
            q = 0;
        }
        else if(c == 1)
        {
            carry = 0;
            q = 1;
        }
        else if(c == 2)
        {
            carry = 1;
            q = -1;
        }
        else if(c == 3)
        {
            carry = 1;
            q = 0;
        }
        else printf("err %d\n", c);
        z[zP++] = q;
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

