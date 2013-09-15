#include <stdio.h>

#define NMAX 257

//#define DEBUG

int arr[NMAX];
int knight[NMAX];
int r;
int N;

int count()
{
    int i, r = 0;
    for(i = 0; i < N; i++)
        if(knight[i] == 1) r++;
    return(r);
}

void try(int first)
{
    int i;
    knight[0] = first;
    for(i = 0; i < N; i++)
    {
        if(knight[i] == 1) knight[i + 1] = arr[i];
        else knight[i + 1] = arr[i] == 0 ? 1 : 0;
    }

#ifdef DEBUG
    printf("c=%d\n", count());
#endif

    if(knight[N] == knight[0])
    {
        if(r > count())
            r = count();
    }
#ifdef DEBUG
    else printf("no\n");
#endif
}

int main()
{
    int i, t;

    scanf("%d", &N);

    r = N + 1;

    for(i = 0; i < N; i++)
        scanf("%d", arr + N - i - 1);

#ifdef DEBUG
    for(i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
#endif

    try(0);
    try(1);

    printf("%d\n", r);

    return(0);
}
