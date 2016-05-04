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

const double tau = 0.04;
int P		= 25;

double ut1[MAXM], ut2[MAXM];

// diagonal element
// dF_m/du_m
#define B(m) (1. / tau - 2 * u_s[m] * (u_s[m + 1] + u_s[m - 1]) + 6 * pow(u_s[m] / h, 2))

// dF_m/du_{m-1}
#define A(m) (m > 0 ? (-pow(u_s[m] / h, 2)) : 0)

// dF_m/du_{m+1}
#define C(m) (m < M ? (-pow(u_s[m] / h, 2)) : 0)

#define b(m, p) -(pow(m * h, 2) + tau * p)

int main()
{
    // initializing u t = 0
    for(int m = 0; m <= M; m++)
        u[0][m] = m * h;

    for(int p = 0; p * tau < T; p++)
    {
        double* u_s, *u_s1;
        u_s = ut1;
        u_s1 = ut2;
        memcpy(u_s, u[p], MAXM * sizeof(double));
        for(int s = 0; s <= 10; s++)
        {
            double alpha[MAXM + 1], beta[MAXM + 1];
            alpha[2] = -C(1) / B(1);
            beta[2] = b(1, p) / B(1);

            int l = M - 1;
            for(int k = 2; k < l; k++)
            {
                alpha[k + 1] = -C(k) / (A(k) * alpha[k] + B(k));
                beta[k + 1] = - (b(k, p) - A(k) * beta[k]) / (A(k) * alpha[k] + B(k));
            }

            u_s1[0] = p * tau;
            u_s1[M] = 1 + pow(p * tau, 2);

            u_s1[l] = -(A(l) * beta[l] - b(l, p)) / (alpha[l] * A(l) - B(l));

            for(int k = l; k >= 2; k--)
                u_s1[k - 1] = alpha[k] * u_s1[k] + beta[k];

            // l1-norm
            double norm = 0;
            for(int k = 1; k <= M - 1; k++)
            {
                double delta = A(k) * u_s1[k - 1] + B(k) * u_s1[k] + C(k) * u_s1[k + 1] - b(k, p);
                delta = fabs(delta);
                norm += delta;
            }

            double* temp = u_s;
            u_s = u_s1;
            u_s1 = temp;
        }

        memcpy(u[p + 1], u_s, MAXM * sizeof(double));
    }
    
}
