#include <stdio.h>

typedef struct matrix2
{
    // ( a1  b1 )
    // ( a2  b2 )
    long long int a1;
    long long int b1;
    long long int a2;
    long long int b2;
} matrix2;

// (Fn  ) = (1 1)(Fn-1)
// (Fn-1)   (1 0)(Fn-2)

// (Fn+1) = (1 1)(Fn  ) = (1 1)^2 (Fn-1)
// (Fn  )   (1 0)(Fn-1)   (1 0)   (Fn-2)

long long N, K;

long long mulK(long long x, long long y)
{
    return((x * y) % K);
}

long long sumK(long long x, long long y)
{
    return((x + y) % K);
}

matrix2 mul(matrix2 x, matrix2 y)
{

    // ( xa1  xb1 )( ya1  yb1 )
    // ( xa2  xb2 )( ya2  yb2 )
    matrix2 res;
    res.a1 = sumK(mulK(x.a1, y.a1), mulK(x.b1, y.a2));
    res.b1 = sumK(mulK(x.a1, y.b1), mulK(x.b1, y.b2));

    res.a2 = sumK(mulK(x.a2, y.a1), mulK(x.b2, y.a2));
    res.b2 = sumK(mulK(x.a2, y.b1), mulK(x.b2, y.b2));
    return(res);
}

matrix2 fastmul(matrix2 x, long long y)
{
    if(y <= 1) return(x);

    if(y % 2 == 0)
    {
        matrix2 half = fastmul(x, y / 2);
        return(mul(half, half));
    }
    else
        return(mul(fastmul(x, y - 1), x));
}

void printMatrix(matrix2 x)
{
    printf("( %lld %lld )\n( %lld %lld )\n", x.a1, x.b1, x.a2, x.b2);
}

int main(void)
{
    scanf("%lld", &N);
    scanf("%lld", &K);

    if(N == 1)
        printf("%lld\n", 1 % K);
    else if(N == 2)
        printf("%lld\n", 1 % K);
    else
    {
        matrix2 fibmatrix;
        // (Fn  ) = (1 1)(Fn-1)
        // (Fn-1)   (1 0)(Fn-2)
    //    fibmatrix.a1 = 1;
    //    fibmatrix.b1 = 1;
    //    fibmatrix.a2 = 1;
    //    fibmatrix.b2 = 0;
        fibmatrix.a1 = 1;
        fibmatrix.b1 = 1;
        fibmatrix.a2 = 1;
        fibmatrix.b2 = 0;

        //printMatrix(fibmatrix);

        fibmatrix = fastmul(fibmatrix, N - 2);

        printf("%lld\n", sumK(fibmatrix.a1, fibmatrix.b1));

        //printMatrix(fibmatrix);
    }
    return 0;
}

