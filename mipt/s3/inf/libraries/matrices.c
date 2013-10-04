#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "matrices.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

int allocateMatrix(matrix *a, int rows, int cols)
{
    if(a == NULL)
        return(-1);
    a->rows = rows;
    a->cols = cols;

    a->v = malloc(sizeof(mType) * (rows * cols));

    return(0);
}

void freeMatrix(matrix *a)
{
    if(a == NULL) return;

    free(a->v);

    a->v = NULL;
    a->rows = 0;
    a->cols = 0;
}

typedef struct
{
    matrix a;
    matrix b;
    matrix c;
    int r0;
    int rstep;
} multiplyMatricesThreadsArgs;

void *multiplyMatricesThread(void *args_)
{
    multiplyMatricesThreadsArgs args = *((multiplyMatricesThreadsArgs*) args_);
    multiplyMatrices(args.a, args.b, args.c, args.r0, args.rstep);
    return(NULL);
}

int multiplyMatricesThreads(matrix a, matrix b, matrix c, int threadsN)
{
    if(a.cols != b.rows)
        return(-1);
    if(c.rows != a.rows || c.cols != b.cols)
        return(-1);

    int i, res;
    pthread_t *thid = malloc(sizeof(pthread_t) * threadsN);
    multiplyMatricesThreadsArgs args;

    for(i = 0; i < threadsN; i++)
    {
        args.a = a;
        args.b = b;
        args.c = c;
        args.r0 = i;
        args.rstep = threadsN;
        res = pthread_create(&thid[i], (pthread_attr_t *) NULL, multiplyMatricesThread, &args);
        if(res != 0)
            return(-1);
    }

    // waiting
    for(i = 0; i < threadsN; i++)
        pthread_join(thid[i], (void **)NULL);

    return(0);
}

void allocateShared()
{
   int     *array;
   int     shmid;
   int     new = 1;
   char    pathname[] = "06-1a.c";
   key_t   key;

   if((key = ftok(pathname,0)) < 0){
     printf("Can\'t generate key\n");
     exit(-1);
   }

   if((shmid = shmget(key, 4*sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) < 0)
   {
      if(errno != EEXIST){
         printf("Can\'t create shared memory\n");
         exit(-1);
      } else {
         if((shmid = shmget(key, 3*sizeof(int), 0)) < 0){
            printf("Can\'t find shared memory\n");
            exit(-1);
	 }
         new = 0;
      }
   }

   if((array = (int *)shmat(shmid, NULL, 0)) == (int *)(-1)){
      printf("Can't attach shared memory\n");
      exit(-1);
   }
}

int readMatrix(matrix* a)
{
    if(a == NULL)
        return(-1);

    int m, n;
    if(scanf("%d", &m) != 1)
        return(-1);
    if(scanf("%d", &n) != 1)
        return(-1);

    if(allocateMatrix(a, m, n) != 0)
        return(-1);

    int i, j;
    char c;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
        {
            scanf("%lf", &(a->v[i * n +j]));
            if(j < n - 1)
                scanf("%c", &c);
        }

    return(0);
}

int multiplyAllocateMatrices(matrix a, matrix b, matrix *c)
{
    if(a.cols != b.rows)
        return(-1);

    if(allocateMatrix(c, a.rows, b.cols) != 0)
        return(-1);
    return(0);
}

int multiplyMatrices(matrix a, matrix b, matrix c, int r0, int rstep)
{
    if(a.cols != b.rows)
        return(-1);
    if(c.rows != a.rows || c.cols != b.cols)
        return(-1);

    int i, j, k;
    for(i = r0; i < a.rows; i += rstep)
        for(j = 0; j < b.cols; j++)
        {
            c.v[i * c.cols + j] = 0;
            for(k = 0; k < a.cols; k++)
                c.v[i * c.cols + j] += a.v[i * a.cols + k] * b.v[k * b.cols + j];
        }

    return(0);
}

void printMatrix(matrix a)
{
    printf("%d, %d\n", a.rows, a.cols);
    int i, j;
    for(i = 0; i < a.rows; i++)
    {
        for(j = 0; j < a.cols; j++)
        {
            printf("%lf", a.v[i * a.cols + j]);
            if(j < a.cols - 1)
                printf(";");
        }
        printf("\n");
    }
}
