#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef double nType;

#define EPS 1e-10

//#define DEBUG

typedef struct matrix
{
    int R; //rows
    int C; //columns
    nType** ptr; //ptr to matrix
} matrix;

void getInverseDestroy(matrix *m, matrix *dest);
void printMatrices(matrix* A, matrix * B);
void mallocCp(matrix* dest, matrix* src);
void cpMatrix(matrix* dest, matrix* src);

//multiply a row i by a number
void eop1(matrix* m, int i, nType number)
{
    int j;
    for(j = 0; j < m->C; j++)
        m->ptr[i][j] *= number;
}

//subtract row i1 multiplied by number from i2
void eop2(matrix *m, int i1, nType number, int i2)
{
    int j;
    for(j = 0; j < m->C; j++)
        m->ptr[i2][j] -= m->ptr[i1][j] * number;
}

//swap rows i1 and i2
void eop3(matrix *m, int i1, int i2)
{
    int j;
    nType t;
    for(j = 0; j < m->C; j++)
    {
        t = m->ptr[i1][j];
        m->ptr[i1][j] = m->ptr[i2][j];
        m->ptr[i2][j] = t;
    }
}

//returns argmax of abs of element in row
int getMaxInRow(matrix *m, int i)
{
    int j, res = 0;
    for(j = 1; j < m->C; j++)
        if(fabs(m->ptr[i][j]) > fabs(m->ptr[i][res]))
            res = j;
    return(res);
}

void getIdentityMatrix(matrix *dest, int N)
{
    dest->R = N;
    dest->C = N;
    int i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            dest->ptr[i][j] = 0;

    for(i = 0; i < N; i++)
        dest->ptr[i][i] = 1;
}

inline int isZero(nType n)
{
    return(fabs(n) < EPS);
}

void mallocMatrix(matrix* m, int R, int C)
{
    m->R = R;
    m->C = C;
    int i;
    m->ptr = malloc(sizeof(nType*) * R);
    for(i = 0; i < R; i++)
        m->ptr[i] = malloc(sizeof(nType) * C);
}

void freeMatrix(matrix *m)
{
    int i;
    for(i = 0; i < m->R; i++)
        free(m->ptr[i]);
    free(m->ptr);
    m->R = 0;
    m->C = 0;
}

void getInverseCopy(matrix* m, matrix *dest, matrix *mem)
{
    int destroyFlag = 0;
    if(mem == NULL)
    {
        mem = malloc(sizeof(matrix));
        mallocCp(mem, m);
        cpMatrix(mem, m);
        destroyFlag = 1;
    }

    getInverseDestroy(mem, dest);
    if(destroyFlag)
    {
        freeMatrix(mem);
        free(mem);
    }
}

void getInverseDestroy(matrix *m, matrix *dest)
{
    getIdentityMatrix(dest, m->R);
    int i;
    int j;

    int si;

    nType temp;

    for(i = 0; i < m->R; i++)
    {
        j = getMaxInRow(m, i);
        if(isZero(m->ptr[i][j]))
        {
            dest->R = 0;
            dest->C = 0;
            return;
        }
        temp = m->ptr[i][j];
        
        if(temp != 1)
        {
            #ifdef DEBUG
                fprintf(stderr, "dividing row %d by %lf\n", i + 1, temp);
            #endif
            eop1(m,    i, ((nType) 1.) / temp);
            eop1(dest, i, ((nType) 1.) / temp);
            #ifdef DEBUG
                printMatrices(m, dest);
            #endif
        }

        for(si = 0; si < m->R; si++)
        {
            if(si != i)
            {
                temp = m->ptr[si][j];
                if(temp != 0)
                {
                    #ifdef DEBUG
                      fprintf(stderr, "subtracting row %d multiplied by %lf from row %d\n", i + 1, temp, si + 1);
                    #endif
                    eop2(m,    i, temp, si);
                    eop2(dest, i, temp, si);
                    #ifdef DEBUG
                        printMatrices(m, dest);
                    #endif
                }
            }
        }
    }

    int k;
    for(k = 0; k < m->R; k++)
        for(i = 0; i < m->R; i++)
        {
            //0...1...0
            //....j....
            j = getMaxInRow(m, i);
            if(i != j)
            {
                #ifdef DEBUG
                    fprintf(stderr, "swapping rows %d and %d\n", i + 1, j + 1);
                #endif
                eop3(m,    i, j);
                eop3(dest, i, j);
                #ifdef DEBUG
                    printMatrices(m, dest);
                #endif
            }
        }
}

void fillMatrix(matrix *M)
{
    int i, j;
    double Re, Im;
    for(i = 0; i < M->R / 2; i++)
        for(j = 0; j < M->C / 2; j++)
        {
            scanf("%lf", &Re);
            scanf("%lf", &Im);

            M->ptr[i][j] = Re;
            M->ptr[i][j + M->R / 2] = Im;
            M->ptr[i + M->R / 2][j] = -Im;
            M->ptr[i + M->R / 2][j + M->R / 2] = Re;
        }
}

void printMatrices(matrix* A, matrix * B)
{
    int i, j;
    for(i = 0; i < A->R; i++)
    {
        printf("\t(\t");
        for(j = 0; j < A->C; j++)
            printf("%.2lf\t", A->ptr[i][j]);
        printf(")  (\t");
        for(j = 0; j < B->C; j++)
            printf("%.2lf\t", B->ptr[i][j]);
        printf(")\n");
    }
}

void printMatrix(matrix *M)
{
    int i, j;
    for(i = 0; i < M->R / 2; i++)
    {
        for(j = 0; j < M->C / 2; j++)
            printf("%lf %lf\t", M->ptr[i][j], M->ptr[i, j + M->C / 2]);
        printf("\n");
    }
}

inline void mallocMul(matrix* A, matrix* B, matrix* C)
{
    mallocMatrix(C, A->R, B->C);
}

void mulMatrix(matrix* A, matrix* B, matrix* C)
{
    int i, j, si;
    nType acc;
    for(i = 0; i < C->R; i++)
        for(j = 0; j < C->C; j++)
        {
            acc = 0;
            for(si = 0; si < A->C; si++)
                acc += A->ptr[i][si] * B->ptr[si][j];

            C->ptr[i][j] = acc;
        }
}

void mallocCp(matrix* dest, matrix* src)
{
    mallocMatrix(dest, src->R, src->C);
}

void cpMatrix(matrix* dest, matrix* src)
{
    int i, j;
    for(i = 0; i < src->R; i++)
        for(j = 0; j < src->C; j++)
            dest->ptr[i][j] = src->ptr[i][j];
}

int main(int argc, char** argv)
{
/*    printf("argc=%d\n", argc);
    int ss;
    for(ss = 0; ss < argc; ss++)
        printf("argv#%d=%s\n", ss, argv[ss]);
*/

    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);

    int N;
    scanf("%d", &N);
    matrix *M1 = malloc(sizeof(matrix)), *M2 = malloc(sizeof(matrix));
    mallocMatrix(M1, 2 * N, 2 * N);
    mallocMatrix(M2, 2 * N, 2 * N);

    fillMatrix(M1);

    #ifdef DEBUG
        fprintf(stderr, "A=\n");
        printMatrix(M1);
    #endif

    getInverseCopy(M1, M2, NULL);

    if(M2->R == 0 || M2->C == 0)
        return(1);

    printMatrix(M2);

    freeMatrix(M1);
    freeMatrix(M2);

    return(0);
}
