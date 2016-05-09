#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exact.h"
#include "constants.h"
#include "diff_single.h"

double* single_res = NULL;

void get_differential_single()
{
    double arr1[N + 1], arr2[N + 1];

    double t = 0;

    int i, j;

    for(i = 0; i <= N; i++)
    {
//        printf("x = %lf g = %lf\n", i * h, g(i * h));
        arr1[i] = g(i * h);
        arr2[i] = 0;
    }

    t = tau;

    double* aold = arr1;
    double* anew = arr2;

    while(t <= T)
    {
        for(i = 1; i <= N; i++)
        {
            anew[i] = aold[i] * (1 - c * tau / h) + c * tau / h * aold[i - 1];
        }

        anew[0] = 0;

        double* td = anew;
        anew = aold;
        aold = td;

        t += tau;
    }

    single_res = (double*) malloc(sizeof(double) * (N + 1));
    memcpy(single_res, aold, sizeof(double) * (N + 1));

//    for(i = 0; i <= N; i++)
//        printf("x = %0.2lf diff %0.2lf exact %0.2lf\n", i * h, old[i], exact(i * h, T));

    printf("\n");

    return;
}
