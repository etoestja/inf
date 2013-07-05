#include <stdio.h>

#define NMAX 100
int arr[NMAX][NMAX], colors[NMAX], able, N, M;

int inv(int color)
{
    return(color == 1 ? 2 : 1);
}

void dfs(int vertex, int color)
{
    if(colors[vertex] != 0 || !able)
        return;

    colors[vertex] = color;

    int i;

    for(i = 0; i < N; i++)
    {
        if(arr[vertex][i] && i != vertex)
        {
            if(colors[i] == color) able = 0;
            else dfs(i, inv(color));
        }
    }
}

int main()
{
    int i, j, t1, t2;

    able = 1;

    for(i = 0; i < NMAX; i++)
    {
        for(j = 0; j < NMAX; j++)
            arr[i][j] = 0;
        colors[i] = 0;
    }

    scanf("%d", &N);
    scanf("%d", &M);

    for(i = 0; i < M; i++)
    {
        scanf("%d", &t1);
        scanf("%d", &t2);
        t1--;
        t2--;
        arr[t1][t2] = arr[t2][t1] = 1;
    }

    for(i = 0; i < N; i++)
        dfs(i, 1);

    printf("%s\n", able ? "YES" : "NO");
    if(able)
    {
        for(i = 0; i < N; i++)
        {
            if(colors[i] == 2) printf("%d ", i + 1);
        }
    }

    printf("\n");

    return 0;
}
