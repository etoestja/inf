#define DEBUG
//#undef DEBUG

typedef double mType; // code uses %lf

typedef struct
{
    mType **v;
    unsigned rows;
    unsigned cols;
} matrix;

// allocates a->v rows x cols
// returns 0 if OK
int allocateMatrix(matrix *a, int rows, int cols);

// reads m n\n a11;a12...\na21;a22...
// used scanf
// returns 0 if OK
int readMatrix(matrix* a);

// allocates c->v a.rows x b.cols
// returns 0 if OK
int multiplyAllocateMatrices(matrix a, matrix b, matrix *c);

// multiplies a x b, stores into c
// r0 - starting row
// will calculate result for rows r0, r0+rstep, r0+2rstep...
// returns 0 if OK
int multiplyMatrices(matrix a, matrix b, matrix c, int r0, int rstep);

// prints a in the same format as described in readMatrix
// uses printf
void printMatrix(matrix a);
