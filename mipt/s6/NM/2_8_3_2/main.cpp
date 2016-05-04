#include <cstdio>
#include <math.h>
#include <strings.h>
#include <string.h>

// Size of fixed-size solution array
#define MAXM 1000
#define MAXN 5000

// Solution array
double u[MAXN][MAXM];

// Time array
// t[i] = tau_0 + ... + tau_{i - 1}
double t[MAXN];

// Maximum time
#define T 1

// Space
const double h	= 0.05;	// x step
int M		= 20;	// 1 / h

// Time
const double tau = 0.04;
int P		= 25;

// u_s = current state of Newton method
// u_s1 = delta_x for netwon method
double u_s[MAXM], u_s1[MAXM];

// Matrix F_x
// || B(1) C(1) 0 ... 0 ||
// || A(2) B(2) C(2) .0 ||
// ...
// || 0 ... 0 A(l) B(l) ||

// diagonal element
// dF_m/du_m
#define B(m) (1. / tau - 2 * u_s[m] * (u_s[m + 1] + u_s[m - 1]) + 6 * pow(u_s[m] / h, 2))

// dF_m/du_{m-1}
#define A(m) (m >= 2 ? (-pow(u_s[m] / h, 2)) : 0)

// dF_m/du_{m+1}
#define C(m) (m <= (M - 2) ? (-pow(u_s[m] / h, 2)) : 0)

// F(u_s)
#define b(m, p) (-((u_s[m] - u[p][m]) / tau - pow(u_s[m] / h, 2) * (u_s[m + 1] - 2 * u_s[m] + u_s[m - 1]) - pow(m * h, 2) - tau * p))

// print solution layer
void print_layer(int p, int s)
{
    printf("%d\t%lf\t%d\t", p, p * tau, s);
    for(int m = 0; m <= M; m++)
    {
        printf("%0.2lf ", u[p][m]);
    }
    printf("\n");
}

int main()
{
    // initializing u t = 0
    for(int m = 0; m <= M; m++)
        u[0][m] = m * h;

    printf("Layer\tTime\tNwtIter\tData\n");
    print_layer(0, 0);

    // for tridiagonal matrix alrorithm
    double eps = 1e-3;

    // p = time
    for(int p = 0; p * tau <= T; p++)
    {
        // copy solution for time=p as starting point for Netwon method
        memcpy(u_s, u[p], MAXM * sizeof(double));

        // fill x = 0 and x = 1
        u_s[0] = p * tau;
        u_s[M] = 1 + pow(p * tau, 2);

        // Netwon method iterations
        // F = finite difference equations
        // Solving F(x) = 0
        // F_x(x) * delta_x = - F(x)
        int s;
        for(s = 0; ; s++)
        {
            // set delta_x to zero
            bzero(u_s1, sizeof(u_s1));

            // tridiagonal matrix alrorithm
            // solving F_x(x) * delta_x = - F(x)
            // delta_x = u_s1
            // x       = u_s

            double alpha[MAXM + 1], beta[MAXM + 1];
            alpha[2] = -C(1) / B(1);
            beta[2] = b(1, p) / B(1);

            // l = size of the matrix (l x l)
            int l = M - 1;

            for(int k = 2; k < l; k++)
            {
                alpha[k + 1] = -C(k) / (A(k) * alpha[k] + B(k));
                beta[k + 1] = (b(k, p) - A(k) * beta[k]) / (A(k) * alpha[k] + B(k));
            }

            // l'th element
            u_s1[l] = -(A(l) * beta[l] - b(l, p)) / (alpha[l] * A(l) + B(l));

            // going backwards
            for(int k = l; k >= 2; k--)
                u_s1[k - 1] = alpha[k] * u_s1[k] + beta[k];

            // adding delta_x to x
            for(int k = 1; k <= M - 1; k++)
                u_s[k] += u_s1[k];

            // l1-norm (stopping criteria)
            double  F_norm = 0;
            double dx_norm = 0;
            for(int k = 1; k <= M - 1; k++)
            {
                F_norm += fabs(b(k, p));
                dx_norm += fabs(u_s1[k]);

//                double delta = A(k) * u_s1[k - 1] + B(k) * u_s1[k] + C(k) * u_s1[k + 1] - b(k, p);
//                printf("%lf %lf %lf %lf %lf delta %lf\n", A(k), B(k), C(k), b(k, p), delta);
            }
            //printf("p %d s %d norm %lf delta %lf\n", p, s, F_norm, dx_norm);

            // stopping criteria
            if(F_norm < eps || dx_norm < eps)
                break;
        }

        // copying Netwon Method solution as u^{p+1}
        memcpy(u[p + 1], u_s, MAXM * sizeof(double));

        print_layer(p + 1, s);
    }
}
