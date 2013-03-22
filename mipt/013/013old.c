#include <stdio.h>

#define NMAX (500 + 1)
#define DIM 3

int tswap;
#define swap(x, y)  {tswap = x; x = y; y = tswap;}
#define nswap(x, y) {if(x < y) swap(x, y);}

int N;
int arr[NMAX][NMAX];

int box[NMAX][DIM];

int leaf[NMAX], used[NMAX];

void sort3(int arr[DIM])
{
    nswap(arr[0], arr[1]);
    nswap(arr[1], arr[2]);
    nswap(arr[0], arr[1]);
}

int smaller(int a[DIM], int b[DIM])
{
    int i;
    for(i = 0; i < DIM; i++)
        if(a[i] >= b[i]) return 0;
    return(1);
}

void dfs(int vertex)
{
    if(used[vertex]) return;

    used[vertex] = 1;

    int j, go = 0;

    for(j = 0; j < N; j++)
    {
        if(arr[vertex][j])
        {
            dfs(j);
            go = 1;
        }
    }

    if(!go) leaf[vertex] = 1;
}

int main()
{
    int t, i, j;
    scanf("%d", &N);

    for(i = 0; i < NMAX; i++)
        for(j = 0; j < NMAX; j++)
            arr[i][j] = 0;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < DIM; j++)
            scanf("%d", &(box[i][j]));
        sort3(box[i]);
        for(j = 0; j < DIM; j++)
            printf("%d ", box[i][j]);
        printf("\n");
    }

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
        {
            if(smaller(box[i], box[j]) && i != j) arr[i][j] = 1;
        }

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
//            printf("%d ", arr[i][j]);
            used[j] = 0;
        }
//        printf("\n");
        dfs(i);
    }

    int leafCount = 0;

    for(i = 0; i < N; i++)
    {
        if(leaf[i]) leafCount++;
    }

    printf("%d\n", leafCount);

    return(0);
}
