#include <mpi.h>
#include <stdio.h>
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

int getActivePoints(int rank, int size, int N)
{
    
}

int main(int argc, char** argv)
{
    // MPI process parameters
    int rank, size;

    // MPI initialization
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // print my status
    fprintf(stderr, "SIZE=%d RANK=%d\n", size, rank);

    double tau = 0.001;
    double h = 0.001;
    int N = l / h;
    int n = N / size;

    if(n * size != N)
        n++;

    if(rank == size - 1)
        n = N - (size - 1) * n;

    n += 1;

    // points for i: 0...n
    // overall points: 0...N
    double* arr1 = malloc(sizeof(double) * (n + 1));
    double* arr2 = malloc(sizeof(double) * (n + 1));

    double t = 0;
    double* arr_old = arr1;
    double* arr_new = arr2;

    arr_old[0] = 0;
    arr_old[n - 1] = 0;
    int i;
    for(i = 1; i < n; i++)
        arr_old[i] = u_0;

    while(t <= T)
    {
        for(i = 1; i <= n - 1; i++)
            arr_new[i] = arr_old[i] + k * tau / h / h * (arr_old[i - 1] - 2 * arr_old[i] + arr_old[i + 1]);

        processExchange(rank, size, arr_new, n);

        double* tmp = arr_old;
        arr_old = arr_new;
        arr_new = tmp;

        t += tau;
    }

    double* arr = malloc(sizeof(double) * (N + 1));
    if(rank == 0)
    {
        memcpy(arr, arr_old, sizeof(double) * n);
        for(i = 1; i < size; i++)
        {
            MPI_Recv(arr + i * n, i == size - 1 ? (N - (size - 1) * n))
        }
    }
}

int printExact()
{
    double t, x;
    for(t = 0; t <= T; t += 0.001)
    {
        for(x = 0; x <= l; x += 0.05)
            printf("%0.2lf\t", getExactSolution(x, t));
        printf("\n");
    }
    return(0);
}
