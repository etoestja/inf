#include <stdio.h>

int n;

#define NMAX (100 + 5)

long long table[NMAX][NMAX];

long long options(int nleft, int currentValue)
{
    if(table[nleft][currentValue] != -1) return table[nleft][currentValue];

    long long result = 0;
    int useN;

    for(useN = 0; currentValue * useN <= nleft; useN++)
        result += options(nleft - currentValue * useN, currentValue - 1);
    table[nleft][currentValue] = result;
    return(result);
}

void tableInit()
{
    int i, j;
    for(i = 0; i < NMAX; i++)
        for(j = 0; j < NMAX; j++)
            table[i][j] = -1;
    for(i = 0; i < NMAX; i++)
    {
        table[i][0] = 0;
        table[0][i] = 1;
    }
}

int main(void)
{
    tableInit();

    scanf("%d", &n);
    printf("%lld\n", options(n, n));

    return 0;
}

