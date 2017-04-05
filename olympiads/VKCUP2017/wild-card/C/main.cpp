#include <stdio.h>

const int D = 10;
int cost[D] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

#define MAXN 100005
int res[MAXN];
int N;

int P = 0;
void use_digit(int d)
{
    N -= cost[d];
    res[P] = d;
    P++;
//    printf("%d", d);
}

int main()
{
    scanf("%d", &N);
    while(N >= 2)
    {
        if(N == 3)
        {
            use_digit(7);
        }
        else use_digit(1);
        
    }
    for(int i = P - 1; i >= 0; i--)
        printf("%d", res[i]);
    printf("\n");
    return(0);
/*    for(int i = 0; i < D; i++)
        for(int j = 0; j < D; j++)
            {
                printf("%d%d -> %d\n", i, j, cost[i] + cost[j]);
            }*/
}
