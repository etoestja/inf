#include <stdio.h>
#include <math.h>

#define EPS 1e-5
#define f(x) sin(pow(x, 2))

int main()
{
    double integral = 0;
    double a, b;
    scanf("%lf", &a);
    scanf("%lf", &b);

    unsigned int i, N = (unsigned int) ((1 / EPS)
        * 4 * (b - a) * (b - a)) + 5;
//    printf("N=%u\n", N);
    double h = 1. / N * (b - a);

    double sum1;
    sum1 = f(a) + f(b);
    integral = h * sum1 / 2;

    sum1 = 0;
    for(i = 0; i < N; i++)
        sum1 += f(a + i * h);

    integral += h * sum1;

    printf("%.6lg\n", integral);

    return(0);
}
