#include <stdio.h>
#include <stdlib.h>

#define NMAX 250001
int isPrimeMap[NMAX];

//void binPrint(char a)
//{
//    int i;
//    for(i = 7; i >= 0; i--)
//        printf("%d", (a & (1 << i)) ? 1 : 0);
//}

//void binPrintAll()
//{
//    int i, K = 10;
//    for(i = 0; i < K; i++)
//    {
//        printf("01234567");
//    }

//    printf("\n");

//    for(i = 0; i < K; i++)
//    {
//        binPrint(isPrimeMap[i]);
//    }
//    printf("\n");
//}

void setFalse(long i)
{
    isPrimeMap[i / 8] &= ~(1 << (7 - (i % 8)));
}

int isPrime(long i)
{
    return(isPrimeMap[i / 8] & (1 << (7 - (i % 8))));
}

int main(void)
{
    long int N, i, j;

    for(i = 0; i < NMAX; i++)
    {
        isPrimeMap[i] = 0xff;
    }

    scanf("%ld", &N);
    for(i = 2; i < N; i++)
    {
        if(isPrime(i))
        {
            for(j = i + i; j < N; j += i)
            {
                setFalse(j);
            }
        }
    }

    long long sum = 0;

    for(i = 2; i < N; i++)
    {
        if(isPrime(i)) sum += i;
    }

    printf("%lld\n", sum);

    return 0;
}

