#include <stdio.h>

int N, M, res, i;

int fact2[4] = {1, 1, 2, 720};
//next one is bigger than 1e9 so fact(fact2) mod M = 0

int main()
{
    scanf("%d", &N);
    scanf("%d", &M);
    if(N >= 4) printf("0\n");
    else
    {
        res = 1;
        for(i = 1; i <= fact2[N]; i++)
        {
            res *= i % M;
            res %= M;
        }
        printf("%d\n", res);
    }
    return(0);
}
