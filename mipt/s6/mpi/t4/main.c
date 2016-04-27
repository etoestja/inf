#include <stdio.h>

double c = 1;

double g(double x)
{
    if(x < 0 || x > 2)
        return(0);
    return(x * (2 - x));
}

double exact(double x, double t)
{
    return(g(x - c * t));
}

int main(int argc, char** argv)
{
    const int N = 100;
    double arr1[N + 1], arr2[N + 1];

    double tau = 0.05;
    double h = 0.1;

    double T = 4;
    double X = 10;

    double t = 0;

    int i, j;

    for(i = 0; i <= N; i++)
    {
        arr1[i] = g(i * h);
        arr2[i] = 0;
    }

    t = tau;

    double* old = arr1;
    double* new = arr2;

    while(t <= T)
    {
        for(i = 1; i <= N; i++)
        {
            new[i] = old[i] - c * tau / h * (old[i] - old[i - 1]);
        }

        new[0] = 0;

        double* td = new;
        new = old;
        old = td;

        t += tau;
    }

    for(i = 0; i <= N; i++)
        printf("%lf %lf\n", old[i], exact(i * h, T));

    printf("\n");

    return(0);
}
