#include <stdio.h>
#include <math.h>

long double sum = 0;
long double value;
long double x;
int N;

long double factorial(int k)
{
    long double res = 1;
    int i;
    for(i = 1; i <= k; i++)
        res *= i;
    return(res);
}

void getSum()
{
    sum = 0;
    int i;
    for(i = 0; i <= N; i++)
    {
//        printf("i=%d\tfact=%llf\n", i, factorial(i));
        sum += pow(x, i) / factorial(i);
    }
}

void getValue()
{
    value = pow(M_E, x);
}

int main()
{
    scanf("%llf", &x);
    scanf("%d", &N);

    getSum();
    getValue();

    printf("%llf\n", value);
    printf("%llf\n", sum);

    return(0);
}
