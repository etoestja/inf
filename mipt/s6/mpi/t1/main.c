#include <mpi.h>
#include <stdio.h>
#include "integrate.h"
#include "function.h"

// constants
// used only in process 0!
double eps = 1e-6;
double a = 0;
double b = 1;

// structure for children
typedef struct
{
    double a;
    double b;
    double eps;
} integrateParameters;

// print I0 -- single process implementation
double calculatePrintSingle()
{
    double I0 = integrateAuto(f, a, b, eps);
    fprintf(stderr, "I0 = %lf\n", I0);
    return(I0);
}

// main
int main(int argc, char** argv)
{
    // MPI process parameters
    int rank, size;

    // total parallel result
    double I1 = 0;

    // MPI initialization
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // print my status
    fprintf(stderr, "SIZE=%d RANK=%d\n", size, rank);

    // process 0 prints I0
    if(rank == 0)
        calculatePrintSingle();

    // parameters for this process
    integrateParameters p;

    // sending parameters
    // also filling p for process 0
    if(rank == 0)
    {
        integrateParameters p_send;

        // delta_x -- length of i'th subinterval
        double delta_x = (b - a) / size;

        // cycle through all intervals
        unsigned i;
        for(i = 0; i < size; i++)
        {
            // filling the structure
            p_send.a = a + delta_x * i;
            p_send.b = a + delta_x * (i + 1);
            p_send.eps = eps;

            // filling p for 0 process
            if(i == 0)
                p = p_send;
            else
            {
                // sending to i >= 1 process
                MPI_Send(&p_send, sizeof(p_send), MPI_BYTE, i, 1, MPI_COMM_WORLD);
            }
        }
    }
    else // rank >= 1
    {
        // receiving integrate paramters
        MPI_Status status;
        MPI_Recv(&p, sizeof(p), MPI_BYTE, 0, 1, MPI_COMM_WORLD, &status);
    }

    // at this point p contains parameters
    // both for master and child processes

    // calculating and printing partial integral
    double I_p = integrateAuto(f, p.a, p.b, p.eps);
    fprintf(stderr, "rank=%d a=%lf b=%lf eps=%lf I_p=%lf\n", rank, p.a, p.b, p.eps, I_p);

    // process 0 receives partial integrals from other ones
    // also summing and adding it's own value
    if(rank == 0)
    {
        unsigned i;
        double I_i;
        MPI_Status status;

        // receive from all processes with i >= 1
        for(i = 1; i < size; i++)
        {
            MPI_Recv(&I_i, sizeof(I_i), MPI_BYTE, i, 2, MPI_COMM_WORLD, &status);

            //add partial integral to I1
            I1 += I_i;
        }

        // add 0'th own partial integral
        I1 += I_p;

        fprintf(stderr, "I = %lf\n", I1);
    }
    else // rank >= 1
    {
        // child processes send partial integrals to master
        MPI_Send(&I_p, sizeof(I_p), MPI_BYTE, 0, 2, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return(0);
}
