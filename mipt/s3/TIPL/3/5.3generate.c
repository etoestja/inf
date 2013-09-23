#include <stdio.h>

void print_bin(int t)
{
    int i, N = 20;
    for(i = N; i >= 0; i--)
        printf("%d", t & (1 << i) ? 1 : 0);
}

int main()
{
    int i, N;
    scanf("%d", &N);

    for(i = 0; i <= N; i++)
    {
        if(i % 3 == 2)
        {
            printf();
        }
    }
}
