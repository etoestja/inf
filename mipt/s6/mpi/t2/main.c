#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include "exact.h"
#include "config.h"

#define NOCOUT

int N, S;
double tau;
double h;

inline void applyPattern(double* arrOld, double* arrNew, int index)
{
    double K = k * tau / h / h;
    arrNew[index] = arrOld[index] + K * (arrOld[index - 1] - 2 * arrOld[index] + arrOld[index + 1]);
}

inline void swap(double** a, double** b)
{
    double* t = *a;
    *a = *b;
    *b = t;
}

void printPoint(int i, double val)
{
//    printf("T=%0.2f x=%0.2f i=%d u=%0.2f\n", T, i * h, i, val);
    printf("%0.2f\t", val);
}

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

int main(int argc, char** argv)
{
    double runBegin, runEnd;
    T = 0.1;
    k = 1;
    u_0 = 1;
    N = 100000;
    S = 1000;
    tau = T / S;
    h = l / N;

    // MPI process parameters
    int rank, size;

    // MPI initialization
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // print my status

    if(rank == 0)
    {
#ifndef NOCOUT
        printExactEnd();
#endif

        runBegin = MPI_Wtime();
    }

//    printDifferentialSingle();
//    printExact();

    int p = size;
    int M = N - 1;
    int n = 1 + (M / p);
    int n0 = M % p;
    if(rank + 1 <= n0)
        n++;

#ifndef NOCOUT
    fprintf(stderr, "SIZE=%d RANK=%d M=%d n=%d n0=%d\n", size, rank, M, n, n0);
#endif

    // this processor has n-1 active points
    // 1...n-1
    // also 0, n are shadow
    // 1, n-1 will be sent
    // 0, n will be received

    double* arrOld = malloc(sizeof(double) * (n + 1));
    double* arrNew = malloc(sizeof(double) * (n + 1));

    arrOld[0] = 0;
    arrNew[0] = 0;
    arrOld[n] = 0;
    arrNew[n] = 0;

    int i, j;
    // i for length
    // j for time

    for(i = 1; i <= n - 1; i++)
        arrOld[i] = u_0;

    for(j = 1; j <= S; j++)
    {
        for(i = 1; i <= n - 1; i++)
            applyPattern(arrOld, arrNew, i);

        // send 1, n-1
        // recv 0, n

        swap(&arrNew, &arrOld);

        processExchange(rank, size, arrOld, n);
    }

//    for(i = 1; i <= n - 1; i++)
//        printf("t=%0.2f rank=%d i=%d val=%0.2f\n", T, rank, i, arrOld[i]);

#ifndef NOCOUT
    if(rank == 0)
    {
        int k, i1;
        MPI_Status status;
        i = 0;

        printf("DIFFERENTIAL:\n");
        printPoint(0, 0);
        i++;

        for(i1 = 1; i1 <= n - 1; i1++)
        {
            printPoint(i, arrOld[i]);
            i++;
        }

        for(k = 1; k < size; k++)
        {
            int i1 = 0;
            int n1 = 0;
            MPI_Recv(arrNew, sizeof(double) * (n - 1), MPI_BYTE, k, 2, MPI_COMM_WORLD, &status);
            MPI_Get_count(&status, MPI_BYTE, &n1);
            n1 /= sizeof(double);

            for(i1 = 0; i1 < n1; i1++)
            {
                printPoint(i, arrNew[i1]);
                i++;
            }
        }

        printPoint(i, 0);
        printf("\n");
    }
    else
    {
        MPI_Send(arrOld + 1, sizeof(double) * (n - 1), MPI_BYTE, 0, 2, MPI_COMM_WORLD);
    }
#endif

    if(rank == 0)
    {
        runEnd = MPI_Wtime();
        printf("WTIME=%lf\n", runEnd - runBegin);
    }

    MPI_Finalize();

    return(0);
}

int printDifferentialSingle()
{
    double* arrOld = malloc(sizeof(double) * (N + 1));
    double* arrNew = malloc(sizeof(double) * (N + 1));
    int i, j;
    for(i = 0; i <= N; i++)
        arrOld[i] = u_0;

    arrOld[0] = 0;
    arrOld[N] = 0;

    double S = 1. / tau;

    for(i = 0; i < S; i++)
    {
        for(j = 1; j <= N - 1; j++)
            applyPattern(arrOld, arrNew, j);

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

int printExactEnd()
{
    double t, x;
    printf("EXACT:\n");
    for(x = 0; x <= l; x += h)
        printf("%0.2f\t", getExactSolution(x, T));
    printf("\n");
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
