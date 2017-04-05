#include <stdio.h>

const int D = 10;
int cost[D] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int N;

void use_digit(int d)
{
    N -= cost[d];
    printf("%d", d);
}

int main()
{
    scanf("%d", &N);
    max_nmb = 0;
    for(int i = 0; i < D; i++)
        for(int j = 0; j < D; j++)
            for(int k = 0; k < D; k++)
            {
                int cst = cost[i] + cost[j] + cost[k];
                int nmb = 100 * i + 10 * j + k;
                if(cst <= M && nmb > max_nmb)
                {
                    max_nmb = nmb;
                }
            }
     printf();
}
