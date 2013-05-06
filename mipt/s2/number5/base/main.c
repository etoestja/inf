#include <stdio.h>

#define MAXN 1000
#define MAXD 11

//x[i][j]=a0a1a2...
unsigned char x[MAXN][MAXD], y[MAXN][MAXD], z[MAXN][MAXD];

void print_one(char* p)
{
    int i = 0;
    for(i = MAXD - 1; i >= 0; i--)
        if(*(p + i)) break;
    for(; i >= 0; i--)
    {
        printf("%c", *(p + i) < 10 ?
            *(p + i) + '0' : *(p + i) - 10 + 'a');
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int i;
    unsigned char *ptr;
    char c;

    int j;
    for(i = 0; i < MAXN; i++)
        for(j = 0; j < MAXD; j++)
            x[i][j] = 0;

    for(i = 0; i < N; i++)
    {
        ptr = x[i];
        while(scanf("%c", &c) > 0 && c != '\n')
        {
            if(c == '*' || c == '+')
                ptr = y[i];
            else if(c == '=')
                ptr = z[i];
            else if(c >= '0' && c <= '9')
            {
                *ptr = c - '0';
                ptr++;
            }
            else if(c >= 'a' && c <= 'z')
            {
                *ptr = c + 10 - 'a';
                ptr++;
            }

            fprintf(stderr, "added: %d\n", *(ptr - 1));
        }
    }

    for(i = 0; i < N; i++)
    {
        print_one(x[i]);
        printf("_");
        print_one(y[i]);
        printf("=");
        print_one(z[i]);
        printf("\n");
    }
}
