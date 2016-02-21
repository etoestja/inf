#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int i;
    char buf[100];
    int rank, size;
    MPI_Status Status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("size=%d rank=%d pid=%d\n", size, rank, getpid());

    if(rank == 0)
    {
        strcpy(buf, "Test hello string");
        MPI_Send(buf, strlen(buf) + 1, MPI_BYTE, 1, 1, MPI_COMM_WORLD);
        fprintf(stderr, "Send 1 ok!\n");
	strcpy(buf, "String 2");
        MPI_Send(buf, strlen(buf) + 1, MPI_BYTE, 1, 2, MPI_COMM_WORLD);
        fprintf(stderr, "Send 2 ok!\n");
    }

    if(rank == 1)
    {
        printf("I am process 1\n");
        MPI_Recv(buf, sizeof(buf), MPI_BYTE, 0, 1, MPI_COMM_WORLD, &Status);
        printf("String=%s\n", buf);
    }

    MPI_Finalize();

    return(0);
}
