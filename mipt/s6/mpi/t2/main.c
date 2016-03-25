#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include "exact.h"
#include "config.h"

void processExchange(int rank, int size, double* arr, int n)
{
    if(rank % 2 == 0)
    {
        MPI_Status status;
        if(rank != size - 1)
            MPI_Sendrecv(arr + (n - 1), 1, MPI_DOUBLE,
                rank + 1, 1,
                arr + n, 1, MPI_DOUBLE,
                rank + 1, 2,
                MPI_COMM_WORLD, &status);
        if(rank != 0)
            MPI_Sendrecv(arr + 1, 1, MPI_DOUBLE,
                rank - 1, 3,
                arr, 1, MPI_DOUBLE,
                rank - 1, 4,
                MPI_COMM_WORLD, &status);
    }
    else
    {
        MPI_Status status;
        if(rank != 0)
            MPI_Sendrecv(arr + 1, 1, MPI_DOUBLE,
                rank - 1, 2,
                arr, 1, MPI_DOUBLE,
                rank - 1, 1,
                MPI_COMM_WORLD, &status);
        if(rank != size - 1)
            MPI_Sendrecv(arr + (n - 1), 1, MPI_DOUBLE,
                rank + 1, 4,
                arr + n, 1, MPI_DOUBLE,
                rank + 1, 3,
                MPI_COMM_WORLD, &status);
    }
}

int N;
double tau;
double h;

int main(int argc, char** argv)
{
    N = 10;
    tau = 0.001;
    h = l / N;
    // MPI process parameters
    int rank, size;

/*    // MPI initialization
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // print my status
    fprintf(stderr, "SIZE=%d RANK=%d\n", size, rank);
*/

    printDifferentialSingle();
    printExact();

    return(0);
}

inline void applyPattern(double* arrOld, double* arrNew, int index, double K)
{
    arrNew[index] = arrOld[index] + K * (arrOld[index - 1] - 2 * arrOld[index] + arrOld[index + 1]);
}

inline void swap(double** a, double** b)
{
    double* t = *a;
    *a = *b;
    *b = t;
}

int printDifferentialSingle()
{
    double* arrOld = malloc(sizeof(int) * (N + 1));
    double* arrNew = malloc(sizeof(int) * (N + 1));
    int i, j;
    for(i = 0; i <= N; i++)
        arrOld[i] = u_0;

    arrOld[0] = 0;
    arrOld[N] = 0;

    double S = 1. / tau;

    for(i = 0; i < S; i++)
    {
        for(j = 1; j <= N - 1; j++)
            applyPattern(arrOld, arrNew, j, k * tau / h / h);

        arrNew[0] = 0;
        arrNew[N] = 0;

        printf("%0.2f\t", tau * i);
        for(j = 0; j <= N; j++)
            printf("%0.2lf\t", arrNew[j]);
        printf("\n");

        swap(&arrNew, &arrOld);
    }

    return(0);
}

int printExact()
{
    double t, x;
    for(t = 0; t <= T; t += tau)
    {
        printf("%0.2f\t", t);
        for(x = 0; x <= l; x += h)
            printf("%0.2lf\t", getExactSolution(x, t));
        printf("\n");
    }
    return(0);
}
