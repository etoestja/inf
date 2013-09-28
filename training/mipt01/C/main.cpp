#include <stdio.h>
#include <stdlib.h>

#define NMAX 500

int N, M;
int h[NMAX][NMAX];
int visited[NMAX][NMAX];
int path[NMAX][NMAX];

inline bool getChild(int &i, int &j)
{
    int i1 = i, j1 = j, h1 = h[i][j];
    if(i > 0 && h[i - 1][j] < h1)
    {
        h1 = h[i - 1][j];
        i1 = i - 1;
        j1 = j;
    }
    if(i < N - 1 && h[i + 1][j] < h1)
    {
        h1 = h[i + 1][j];
        i1 = i + 1;
        j1 = j;
    }
    if(j > 0 && h[i][j - 1] < h1)
    {
        h1 = h[i][j - 1];
        i1 = i;
        j1 = j - 1;
    }
    if(j < M - 1 && h[i][j + 1] < h1)
    {
        h1 = h[i][j + 1];
        i1 = i;
        j1 = j + 1;
    }
    if(i1 != i || j1 != j)
    {
        i = i1;
        j = j1;
        return(1);
    }
    return(0);
}

void dfs(int i, int j)
{
    if(visited[i][j]) return;
    visited[i][j] = 1;

    int i1 = i, j1 = j;

    if(getChild(i1, j1))
    {
        dfs(i1, j1);
        path[i][j] = 1 + path[i1][j1];
    }
}

void init()
{
    for(int i = 0; i < NMAX; i++)
        for(int j = 0; j < NMAX; j++)
        {
            path[i][j] = 1;
            visited[i][j] = 0;
            h[i][j] = 0;
        }
}

void dump()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            printf("%d ", h[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    init();

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    scanf("%d", &M);

    int i, j;

    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
            scanf("%d", &(h[i][j]));

    //dump();

    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
        {
            dfs(i, j);
        }

    int max = 0, h0 = -1;

    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
        {
            if(path[i][j] >= max)
            {
                if(path[i][j] > max || h0 == -1 || h0 > h[i][j])
                    h0 = h[i][j];
                max = path[i][j];
            }
        }

    printf("%d %d\n", max, h0);

    return(0);
}

