#include <stdlib.h>
#include <stdio.h>

#define NAMEMAX (29 + 5)
#define NMAX (10000 + 5)

typedef struct
{
    char name[NAMEMAX];
    int k;
} theOne;

theOne arr[NMAX];
int N;

int onesCMP1(const void* tA, const void* tB)
{
    theOne *a = (theOne*) tA;
    theOne *b = (theOne*) tB;

    return(strcmp(a->name, b->name));
}

int onesCMP2(const void* tA, const void* tB)
{
    theOne *a = (theOne*) tA;
    theOne *b = (theOne*) tB;

    int t;

    if(a->k != b->k)
        return(a->k < b->k);
    else return(strcmp(a->name, b->name));
}

void print()
{
    int i;
    for(i = 0; i < N; i++)
        printf("%s %d\n", arr[i].name, arr[i].k);
}

int main()
{
    scanf("%d", &N);
    int i;
    for(i = 0; i < N; i++)
    {
        scanf("%s", arr[i].name);
        scanf("%d", &(arr[i].k));
    }

    qsort(arr, N, sizeof(theOne), onesCMP1);
    print();

    printf("\n");

    qsort(arr, N, sizeof(theOne), onesCMP2);
    print();

    return(0);
}
