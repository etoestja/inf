#include <stdio.h>
#include <queue>

#define NMAX 1001

#define DEBUG

using std::queue;

int N, M;

int arr[NMAX][NMAX];
int vis[NMAX];
int c[NMAX];
int wins[NMAX];

void bfs()
{
    if(vis[v]) return;
    vis[v] = 1;
    c[v] = color;

    int i;
    int pres0 = 0, pres1 = 0;

#ifdef DEBUG
    printf("dfs at %d color=%d\n", v + 1, color);
#endif

    for(i = 0; i < N; i++)
    {
        if(!vis[i] && arr[v][i])
        {
            dfs(i, color ? 0 : 1);
#ifdef DEBUG
    printf("dfs at %d color=%d wins[%d]=%d\n", v + 1, color, i + 1, wins[i]);
#endif
            if(wins[i] == 0)
                pres0 = 1;
            if(wins[i] == 1)
                pres1 = 1;
        }
    }
    if(color == 0)
    {
        wins[v] = !pres0;
#ifdef DEBUG
    printf("dfs at %d color=%d wins[%d]=%d COLOR0\n", v + 1, color, v + 1, wins[v]);
#endif
    }
    if(color == 1)
    {
        wins[v] = pres1;
#ifdef DEBUG
    printf("dfs at %d color=%d wins[%d]=%d COLOR1\n", v + 1, color, v + 1, wins[v]);
#endif
    }
}

int main()
{
    scanf("%d", &N);
    scanf("%d", &M);

    int i, j, t1, t2;

    for(i = 0; i < NMAX; i++)
    {
        for(j = 0; j < NMAX; j++)
            arr[i][j] = 0;
        vis[i] = 0;
        c[i] = 0;
    }

    for(i = 0; i < M; i++)
    {
        scanf("%d", &t1);
        scanf("%d", &t2);
        t1--; t2--;
        arr[t1][t2] = 1;
        arr[t2][t1] = 1;
    }

    dfs(0, 0);

    printf("%s\n", wins[0] == 0 ? "Vladimir" : "Nikolay");

    return(0);
}
