#include <stdio.h>

//n < 1000

#define NMAX (1000 + 1)
#define NLMAX 1024
#define NCMAX 3
#define base 10

typedef short unsigned int tn;

tn arr[NCMAX][NLMAX];

void zero(tn a[NLMAX])
{
    unsigned i;
    for(i = 0; i < NLMAX; i++)
        a[i] = 0;
}

void print(tn a[NLMAX])
{
    unsigned i;
    for(i = NLMAX; i; i--)
        if(a[i - 1]) break;

    for(; i; i--)
        printf("%d", a[i-1]);
}

int main()
{
    unsigned i, si, N, t, carry = 0;
    for(i = 0; i < NCMAX; i++)
        zero(arr[i]);

    scanf("%u", &N);

    i = 0;

    arr[(i++) % NCMAX][0] = 1;
    arr[(i++) % NCMAX][0] = 1;

    for(; i <= N; i++)
    {
        carry = 0;
        for(si = 0; si < NLMAX; si++)
        {
            t = arr[(i - 1) % NCMAX][si] + arr[(i - 2) % NCMAX][si] + carry;
            carry = t / base;
            t %= base;
            arr[i % NCMAX][si] = t;
        }
    }

    i--;
    print(arr[i % NCMAX]);
    
    return 0;
}
