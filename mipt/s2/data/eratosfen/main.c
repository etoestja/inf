#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 25000002
#define C 8
unsigned char isPrimeMap[NMAX];
//unsigned char * isPrimeMap;

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

#define setFalse(i) {isPrimeMap[i / C] &= arr1[i % C];}
#define isPrime(i) (isPrimeMap[i / C] & arr2[i % C])

int main(void)
{
    long long int N, i, j, sum = 0;

//    isPrimeMap = (unsigned char*) malloc(NMAX * sizeof(unsigned char));

    fill1();

/*    for(i = 0; i < N; i++)
    {
        isPrimeMap[i] = 0xff;
        if(i % 1000 == 0) fprintf(stderr, "%lld\n", i);
    }
*/

    memset(isPrimeMap, 0xff, NMAX);

    scanf("%lld", &N);

    sum = N - 1;

    for(i = 2; i * i <= N; i++)
        if(isPrime(i))
        {
            for(j = i * i; j <= N; j += i)
                if(isPrime(j))
                {
                    sum--;
                    setFalse(j);
                }
        }

//    for(i = 2; i <= N; i++) if(isPrime(i)) sum++;

    printf("%lld\n", sum);

    return 0;
}

