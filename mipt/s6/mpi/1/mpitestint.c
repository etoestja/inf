#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define N 10

int main(int argc, char** argv)
{
    int i;
    int array[N];
    int rank, size;
    MPI_Status Status;

    for(i = 0; i < N; i++)
        array[i] = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("size=%d rank=%d pid=%d\n", size, rank, getpid());

    if(size > N)
    {
        printf("Too big size %d\n", size);
        MPI_Finalize();
        return(0);
    }
        

    if(rank == 0)
    {
        for(i = 0; i < N; i++)
            array[i] = i;
        for(i = 1; i < size; i++)
            MPI_Send(&array[i * N / size], N / size, MPI_INT, i, i, MPI_COMM_WORLD);

        fprintf(stderr, "Send ok!\n");
    }

    if(rank != 0)
    {
//        MPI_Recv(array, N / size, MPI_INT, 0, rank, MPI_COMM_WORLD, &Status);
        for(i = 0; i < N; i++)
            printf("I am process %d array[%d]=%d\n", rank, i, array[i]);
    }

    MPI_Finalize();

    return(0);
}
