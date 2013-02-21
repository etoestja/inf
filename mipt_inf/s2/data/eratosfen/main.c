#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 25000000
#define C 8
unsigned char isPrimeMap[NMAX];

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

int i_perc_C = 0;

void update_perc()
{
    i_perc_C++;
    if(i_perc_C >= C) i_perc_C = 0;
}

unsigned char arr1[C], arr2[C];

void fill1()
{
    int i;
    for(i = 0; i < C; i++)
    {
        arr1[i] = ~((long unsigned int) (1 << ((C - 1) - (i % C))));
        arr2[i] = ~arr1[i];
//        printf("%llu, %llu\n", arr1[i], arr2[i]);
    }
}

void setFalse(long i)
{
    isPrimeMap[i / C] &= arr1[i % C];
}

int isPrime(long i)
{
    return(isPrimeMap[i / C] & arr2[i % C]);
}

int main(void)
{
    long int N, i, j;

    fill1();

    memset(isPrimeMap, 0xff, NMAX);

    i_perc_C = 2 % C;

    scanf("%ld", &N);
    for(i = 2; i <= N; i++)
    {
        if(isPrime(i))
            for(j = i * i; j <= N; j += i)
                setFalse(j);
    }

    long long sum = 0;
    
    for(i = 2; i <= N; i++)
        if(isPrime(i)) sum++;

    printf("%lld\n", sum);

    return 0;
}

