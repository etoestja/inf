#include <stdio.h>
#include <math.h>

#define EPS 1e-5
#define f(x) sin(pow(x, 2))

double a, b;

double calc(unsigned int N)
{
    double integral = 0;

    unsigned int i;
    double h = 1. / N * (b - a);

    double sum1;
    sum1 = f(a) + f(b);
    integral = h * sum1 / 2;

    sum1 = 0;
    for(i = 0; i < N; i++)
        sum1 += f(a + i * h);

    integral += h * sum1;

    return(integral);
}

int main()
{
    scanf("%lf", &a);
    scanf("%lf", &b);

    unsigned int l = 1, m;
    unsigned int ok = 0;
    double calc0, calc1;
    calc0 = calc(l);

    while(!ok)
    {
        m = l * 2;
        calc1 = calc(m);
//        printf("%u  %u  %u %lg %lg\n", l, m, r, calc0, calc1);
        if(fabs(calc0 - calc1) < EPS) ok = 1;
//        if(fabs(calc(l) - calc(m)) < EPS) ok = 1;
        else l = m;
        calc0 = calc1;
    }

    printf("%.6lg\n", calc1);
}
