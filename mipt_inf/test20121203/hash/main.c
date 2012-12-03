#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int current;
    int next;
} Data;


#define NMAX (100000 + 3)
            //100003
#define MMAX 200000000
#define KMAX 10

Data ht[NMAX][KMAX];

int hash(int a)
{
    return(a % NMAX);
}

void list_update(Data * list, int ncurrent, int nnext)
{
    int i;
    for(i = 0; list[i].current != -1; i++)
    {
        if(list[i].current == ncurrent)
        {
            list[i].next = nnext;
            return;
        }
    }

    Data a;
    a.current = ncurrent;
    a.next = nnext;

    list[i] = a;
}

int list_get(Data * list, int c)
{
    int i;
    for(i = 0; list[i].current != -1; i++)
    {
        if(list[i].current == c)
            return(list[i].next);
    }
    return(-1);
}

int main(void)
{
    int current, prev, i, j;

    for(i = 0; i < NMAX; i++)
    {
        for(j = 0; j < KMAX; j++)
            ht[i][j].current = -1;
    }

    i = 0;

    while(scanf("%d", &current) > 0 && current >= 1 && current <= MMAX)
    {
        if(i != 0)
        {
//            fprintf(stderr, "adding hash %lld: %lld => %lld\n", hash(prev), prev, current);
            //add to list info: there is _current_ after _prev_
            list_update(ht[hash(prev)], prev, current);
        }
        prev = current;
        i++;
    }

    if(i > 0)
    {
        int res = list_get(ht[hash(current)], current);
        pcrintf("%d\n", res);
    }
    else
        printf("-1\n");

    return 0;
}

