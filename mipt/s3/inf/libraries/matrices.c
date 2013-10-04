#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "matrices.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

int allocateMatrix(matrix *a, int rows, int cols, int useShared, char* sharedName)
{
    if(a == NULL)
        return(-1);
    a->rows = rows;
    a->cols = cols;
    a->transposed = 0;
    a->useShared = useShared;

    int rsize = (rows * cols) * sizeof(mType);

    if(useShared)
    {
        key_t key;

        if((key = ftok(sharedName, 0)) < 0)
            return(-1);

        if((a->shmid = shmget(key, rsize, 0666|IPC_CREAT|IPC_EXCL)) < 0)
        {
        if(errno != EEXIST)
            return(-1);
        else
            if((a->shmid = shmget(key, rsize, 0)) < 0)
                return(-1);
        }

        if((a->v = (mType*) shmat(a->shmid, NULL, 0)) == (mType *)(-1))
            return(-1);
    }
    else
        a->v = malloc(rsize);

    return(0);
}

void freeMatrix(matrix *a)
{
    if(a == NULL) return;

    if(a->useShared)
        shmdt(a->v);
    else
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
#ifdef DEBUG
    fprintf(stderr, "thread created\t*a=%p\t*b=%p\t*c=%p\tr0=%d\trstep=%d\n", &(args.a), &(args.b), &(args.c), args.r0, args.rstep);
#endif
    multiplyMatrices(args.a, args.b, args.c, args.r0, args.rstep);

#ifdef DEBUG
    fprintf(stderr, "thread finished\t*a=%p\t*b=%p\t*c=%p\tr0=%d\trstep=%d\n", &(args.a), &(args.b), &(args.c), args.r0, args.rstep);
    fprintf(stderr, "*a->v=%p\t*b->v=%p\t*c->v=%p\n", args.a.v, args.b.v, args.c.v);
#endif
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
    multiplyMatricesThreadsArgs* args = malloc(sizeof(multiplyMatricesThreadsArgs) * threadsN);

    for(i = 0; i < threadsN; i++)
    {
        args[i].a = a;
        args[i].b = b;
        args[i].c = c;
        args[i].r0 = i;
        args[i].rstep = threadsN;
        res = pthread_create(&thid[i], (pthread_attr_t *) NULL, multiplyMatricesThread, &(args[i]));
        if(res != 0)
            return(-1);
    }

    // waiting
    for(i = 0; i < threadsN; i++)
        pthread_join(thid[i], (void **)NULL);

    free(thid);
    free(args);

    return(0);
}

int multiplyMatricesProcesses(matrix a, matrix b, matrix c, int processesN)
{
    if(a.cols != b.rows)
        return(-1);
    if(c.rows != a.rows || c.cols != b.cols)
        return(-1);

    int i, res;
    pid_t *pids = malloc(sizeof(pid_t) * processesN);
    int *statuses = malloc(sizeof(int) * processesN);

    for(i = 0; i < processesN; i++)
    {
        if((pids[i] = fork()) != 0)
        {
            // parent
        }
        else
        {
            // child
#ifdef DEBUG
            fprintf(stderr, "process created\t*a=%p\t*b=%p\t*c=%p\tr0=%d\trstep=%d\n", &a, &b, &c, i, processesN);
#endif
            c.v = (mType*) shmat(c.shmid, NULL, 0);
            multiplyMatrices(a, b, c, i, processesN);
#ifdef DEBUG
            fprintf(stderr, "process ended\t*a=%p\t*b=%p\t*c=%p\tr0=%d\trstep=%d\n", &a, &b, &c, i, processesN);
#endif
            exit(1);
        }
    }

    // waiting
    for(i = 0; i < processesN; i++)
        waitpid(pids[i], &(statuses[i]), 0);

    free(pids);
    free(statuses);

    return(0);
}

int readMatrix(matrix* a, int transpose, int useShared, char* sharedName)
{
    if(a == NULL)
        return(-1);

    int m, n;
    if(scanf("%d", &m) != 1)
        return(-1);
    if(scanf("%d", &n) != 1)
        return(-1);

    if(allocateMatrix(a, m, n, useShared, sharedName) != 0)
        return(-1);

    a->transposed = transpose;

    int i, j;
    char c;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
        {
            scanf("%lf", transpose ? &(a->v[j * n + i]) : &(a->v[i * n + j]));
            if(j < n - 1)
                scanf("%c", &c);
        }

    return(0);
}

int multiplyAllocateMatrices(matrix a, matrix b, matrix *c, int useShared, char* sharedName)
{
    if(a.cols != b.rows)
        return(-1);

    if(allocateMatrix(c, a.rows, b.cols, useShared, sharedName) != 0)
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
                c.v[i * c.cols + j] += a.v[i * a.cols + k] * b.v[j * b.cols + k];//b.v[k * b.cols + j];
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
            printf("%lf", a.transposed ? a.v[j * a.cols + i] : a.v[i * a.cols + j]);
            if(j < a.cols - 1)
                printf(";");
        }
        printf("\n");
    }
}
