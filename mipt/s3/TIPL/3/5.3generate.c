#include <stdio.h>

void print_bin(int t)
{
    int i, N = 10;
    for(i = N; i >= 0; i--)
        printf("%d", t & (1 << i) ? 1 : 0);
}

int count_bin(int t, int a)
{
    int i, N = 20, s = 0;

    for(i = N; i >= 0; i--)
        if(!!(t & (1 << i))) break;

    for(; i >= 0; i--)
        if(!!(t & (1 << i)) == a) s++;
    return(s);
}

int main()
{
    int i, N;
    scanf("%d", &N);

    for(i = 0; i <= N; i++)
    {
        if(i % 3 == 2)
        {
            printf("%d\t", i);
            print_bin(i);
//            printf("\t%d\t%d", count_bin(i, 0), count_bin(i, 1));
            printf("\n");
        }
    }
    return(0);
}
