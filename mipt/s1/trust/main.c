#include <stdio.h>

#define NMAX (1000 + 5)
#define KMAX (100000 + 5)

int arr[NMAX][NMAX]; //indexes [0...N-1]
int N, K, X, Y, M;

int A[KMAX], B[KMAX], C[KMAX]; //indexes [0...K-1]

int visited[NMAX];

void dfs(int vertex)
{
    if(visited[vertex]) return;

    visited[vertex] = 1;

    if(vertex == X) return;

    int j;
    for(j = 0; j < N; j++)
        if(arr[vertex][j])
            dfs(j);
}

int main()
{
    int i, j;

    for(i = 0; i < NMAX; i++)
    {
        for(j = 0; j < NMAX; j++) arr[i][j] = 0;
        visited[i] = 0;
    }

    scanf("%d", &N);
    scanf("%d", &K);

    for(i = 0; i < K; i++)
    {
        scanf("%d", &(A[i]));
        scanf("%d", &(B[i]));
        scanf("%d", &(C[i]));
        A[i]--;
        B[i]--;
        C[i]--;
    }

    scanf("%d", &M);
    scanf("%d", &X);
    scanf("%d", &Y);

    M--;
    X--;
    Y--;

    for(i = 0; i < N; i++)
    {
        arr[i][i] = 1;
        arr[i][M] = 1;
    }

    for(j = 0; j < N; j++)
        for(i = 0; i < K; i++)
//            A tells B that B can trust C
//            B trust= C if B trusts A
            if(arr[B[i]][A[i]])
                arr[B[i]][C[i]] = 1;

    dfs(Y);
    printf("%s\n", visited[X] ? "YES" : "NO");

    return(0);
}
