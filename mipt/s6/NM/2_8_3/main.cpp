#include <cstdio>
#include <math.h>
#include <strings.h>

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

// get next time step
// depends on maximum of u on layer p
double get_tau(int p)
{
    double res = h * h / 2;
    int mmax = 0;

    // finding maximum
    for(int m = 1; m <= M; m++)
    {
        if(fabs(u[p][mmax]) < fabs(u[p][m]))
            mmax = m;
    }

    res /= pow(u[p][mmax], 2);

    // coefficient < 1
    res *= 7. / 8;

    // filling time array
    t[p + 1] = t[p] + res;

    return(res);
}

// print solution layer
void print_layer(int p, double tau)
{
    printf("%d\t%lf\t%lf\t", p, t[p], tau);
    for(int m = 0; m <= M; m++)
    {
        printf("%0.2lf ", u[p][m]);
    }
    printf("\n");
}

int main()
{
    // set solution array elements to zero
    bzero(u, sizeof(u));
    bzero(t, sizeof(t));

    // Initialize u when t = 0
    for(int m = 0; m <= M; m++)
        u[0][m] = h * m;

    // print header
    printf("Layer\tTime\tTime_step\tData\n");
    print_layer(0, 0);

    for(int p = 0; t[p] <= T; p++)
    {
        // get next time step
        double tau = get_tau(p);

        // fill solution (min x and max x)
        u[p + 1][0] = t[p + 1];
        u[p + 1][M] = 1 + pow(t[p + 1], 2);

        // fill solution (intermediate x)
        for(int m = 1; m <= M - 1; m++)
            u[p + 1][m] = u[p][m] + tau * pow(u[p][m] / h, 2) * (u[p][m + 1] - 2 * u[p][m] + u[p][m - 1]) + tau * pow(m * h, 2) + tau * t[p];

        // print result
        print_layer(p + 1, tau);
    }
}
