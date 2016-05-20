#include <stdio.h>
#include <math.h>

#define q 2

double fact(int k)
{
    double res = 1;
    int j;
    for(j = 1; j <= k; j++)
        res *= j;
    return(res);
}

double S(int N)
{
    double res = 0;
    int i;
    for(i = 0; i <= N - 2; i++)
        res += pow(q, i) / fact(i);
    return(res);
}

double S1(int N)
{
    double res = q - N - N * (q - 1) * pow(q, N - 1) / fact(N - 1);
    res /= (N - 1);
    res /= (q - 1);
    return(res);
}

int main()
{
    printf("%lf\n", S(5));
    printf("%lf\n", S1(5));
}
