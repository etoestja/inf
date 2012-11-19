#include <stdio.h>

#define MAXPRIMES 30000

int primes[MAXPRIMES];
int primesCounter = 0;

int main(void)
{
    int i, j, isPrime;

    primes[primesCounter++] = 2;

    for(i = 3; primesCounter < MAXPRIMES; i++)
    {
        isPrime = 1;
        for(j = 0; j < primesCounter && i >= primes[j]; j++)
            if(i % primes[j] == 0)
            {
                isPrime = 0;
                break;
            }
        if(isPrime) primes[primesCounter++] = i;
    }

    for(i = 0; i < primesCounter; i++)
        printf("%d ", primes[i]);

    printf("\n");

    return 0;
}

