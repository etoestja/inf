#define DEBUG
//#undef DEBUG

typedef double mType; // code uses %lf

typedef struct
{
    mType *v;
    unsigned rows;
    unsigned cols;
    int transposed;
    int useShared;
    int shmid;
} matrix;

// allocates a->v rows x cols
// returns 0 if OK
int allocateMatrix(matrix *a, int rows, int cols, int useShared, char* sharedName);

// frees a->v and sets it to 0
// sets a->cols, a->rows to 0
void freeMatrix(matrix *a);

// reads m n\n a11;a12...\na21;a22...
// used scanf
// second argument transposes matrix
// returns 0 if OK
int readMatrix(matrix* a, int transpose, int useShared, char* sharedName);

// allocates c->v a.rows x b.cols
// returns 0 if OK
int multiplyAllocateMatrices(matrix a, matrix b, matrix *c, int useShared, char* sharedName);

// multiplies a x b, stores into c.
// b must be transposed (increases performance)
// r0 - starting row
// will calculate result for rows r0, r0+rstep, r0+2rstep...
// returns 0 if OK
int multiplyMatrices(matrix a, matrix b, matrix c, int r0, int rstep);

// same as multiplyMatrices
// uses threadsN threads
int multiplyMatricesThreads(matrix a, matrix b, matrix c, int threadsN);

// same as multiplyMatrices
// uses processesN processes
int multiplyMatricesProcesses(matrix a, matrix b, matrix c, int processesN);

// prints a in the same format as described in readMatrix
// uses printf
void printMatrix(matrix a);
