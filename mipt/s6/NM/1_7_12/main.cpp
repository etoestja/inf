#include <iostream>
#include <stdio.h>
#include <math.h>

// Equation
// y'' - P2(x) y = f(x)
double P2(double x)
{
    return(cos(2 * M_PI * x));
}

double f(double x)
{
    return(-4 * M_PI * M_PI * sin(2 * M_PI * x) - 0.5 * sin(4 * M_PI * x));
}

double exact(double x)
{
    return(sin(2 * M_PI * x));
}

// /Equation

// step
double h;

// Matrix coefficients
#define A(n) (1 / h / h)
#define C(n) (1 / h / h)
#define D(n) (f(n * h))
#define B(n) (-2 / h / h - P2(n * h))

#define NMAX 10000
int N = 0;

// alpha, beta, gamma
// see text solution
double a[NMAX], b[NMAX], c[NMAX];

// getting coefficients
void calcABC()
{
    a[1] = - A(0) / B(0);
    b[1] = D(0) / B(0);
    c[1] = -C(0) / B(0);

    int n;
    for(n = 1; n <= N - 3; n++)
    {
        c[n + 1] = - C(n) * c[n] / (C(n) * a[n] + B(n));
        a[n + 1] = - A(n) / (C(n) * a[n] + B(n));
        b[n + 1] = (D(n) - C(n) * b[n]) / (C(n) * a[n] + B(n));
    }

    a[N - 1] = 0;
    b[N - 1] = (D(N - 2) - C(N - 2) * b[N - 2]) / (C(N - 2) * a[N - 2] + B(N - 2));
    c[N - 1] = -(C(N - 2) * c[N - 2] + A(N - 2)) / (C(N - 2) * a[N - 2] + B(N - 2));
}

double Eta[NMAX], Ksi[NMAX];

void calcKsiEta()
{
    Eta[N - 1] = b[N - 1];
    Ksi[N - 1] = c[N - 1];

    int n;
    for(n = N - 3; n >= 0; n--)
    {
        Ksi[n + 1] = Ksi[n + 2] * a[n + 1] + c[n + 1];
        Eta[n + 1] = Eta[n + 2] * a[n + 1] + b[n + 1];
    }
}

double y[NMAX];
double delta[NMAX];

// does the solution fit equations?
void checkSolution()
{
    delta[0] = D(0) - A(0) * y[1] - B(0) * y[0] - C(0) * y[N - 1];
    delta[N - 1] = D(N - 1) - A(N - 1) * y[0] - B(N - 1) * y[N - 1] - C(N - 1) * y[N - 2];

    int n;
    for(n = 1; n <= N - 2; n++)
    {
        delta[n] = D(n) - A(n) * y[n + 1] - B(n) * y[n] - C(n) * y[n - 1];
    }

    int i;
    for(i = 0; i < N; i++)
    {
        printf("Equation %d delta=%lf\n", i, delta[i]);
    }
}

int getSolution(int N_)
{
    N = N_;
    h = 1. / N;
    calcABC();
    calcKsiEta();

    double zeta = D(N - 1) - C(N - 1) * b[N - 1];
    double mu = A(N - 1);
    double eta = C(N - 1) * c[N - 1] + B(N - 1);

    y[N - 1] = (zeta - mu * Eta[1]) / (mu * Ksi[1] + eta);

    int i;
    for(i = 0; i <= N - 2; i++)
        y[i] = Eta[i + 1] + Ksi[i + 1] * y[N - 1];

/*    checkSolution();

    for(i = 0; i < N; i++)
    {
        printf("x=%lf\ty=%lf\n", i * h, y[i]);
    }*/

    return(0);
}

double getNormDiff(int N_)
{
    getSolution(N_);
    int i;
    double res = 0;
    for(i = 0; i < N; i++)
    {
        double t = fabs(exact(i * h) - y[i]);
        if(t > res) res = t;
    }
    printf("%d\t%.9lf\n", N, res);
    return(res);
}

int main()
{
    int p;
    printf("N\tnorm_diff\n");
    for(p = 5; p <= 800; p++)
        getNormDiff(p);
    return(0);
}
