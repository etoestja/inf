#include <stdio.h>

const unsigned int M = 1024;
unsigned int gcd_cache[M + 2][M + 2];
unsigned int N, d, i, si, k, t, count;

unsigned int gcd(unsigned int a, unsigned int b)
{
    static unsigned int t;

    while(b)
    {
        if(a > b)
        {
            t = a;
            a = b;
            b = t;
        }

        b %= a;
    }

    return(a);
}

void fill_matrix()
{
    unsigned int i, si;
    for(i = 1; i <= M + 1; i++)
        for(si = 1; si <= M + 1; si++)
            gcd_cache[i][si] = gcd(i, si) % d;
}

void print_matrix()
{
    for(i = 0; i < N; i++)
    {
        for(si = 0; si < N; si++)
        {
            printf("%u\t", gcd_cache[i + 1][si + 1]);
        }
        printf("\n");
    }
}

//unsigned int N_count[100];

void get_count_slow()
{
    for(i = 0; i < N; i++)
    {
        for(si = 0; si < N; si++)
        {
            t = 0;

            for(k = 0; k < N; k++)
                t += gcd_cache[i + 1][k + 1] * gcd_cache[N - k + 1][N - si + 1];

            if(t % d == 0) count += 1;
        }
    }
}

int main()
{
    /*for(N = 101; N <= 200; N++)
    {
        printf("/\* N=%u *\/ {", N);
        for(d = 1; d <= 100; d++)
        {
            count = 0;
            get_count_slow();
            printf("%u", count);
            if(d < 100) printf(", ");
        }
        printf("}, \n");
    }*/

    scanf("%u%u", &N, &d);
    fill_matrix();
    count = 0;
    get_count_slow();
    printf("%u\n", count);

    /*for(N = 0; N <= 500; N++)
    {
        printf("N=%u\t", N);
        for(d = 1; d <= 10; d++)
        {
            count = 0;
            get_count_slow();
            printf("%u\t", count);
        }
        printf("\n");
    }*/

    /*N = 5;
    d = 1;
    fill_matrix();
    get_count_slow();

    printf("\n");

    N = 5;
    d = 3;
    fill_matrix();
    get_count_slow();*/
}
