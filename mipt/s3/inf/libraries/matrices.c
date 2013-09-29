#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

int allocateMatrix(matrix *a, int rows, int cols)
{
    if(a == NULL)
        return(-1);
    a->rows = rows;
    a->cols = cols;

    a->v = malloc(sizeof(mType*) * rows);

    int i;
    for(i = 0; i < rows; i++)
        a->v[i] = malloc(sizeof(mType) * cols);

    return(0);
}

void freeMatrix(matrix *a)
{
    if(a == NULL) return;

    int i;
    for(i = 0; i < a->rows; i++)
        free(a->v[i]);

    free(a->v);

    a->v = NULL;
    a->rows = 0;
    a->cols = 0;
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
            scanf("%lf", &(a->v[i][j]));
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
            c.v[i][j] = 0;
            for(k = 0; k < a.cols; k++)
                c.v[i][j] += a.v[i][k] * b.v[k][j];
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
            printf("%lf", a.v[i][j]);
            if(j < a.cols - 1)
                printf(";");
        }
        printf("\n");
    }
}
