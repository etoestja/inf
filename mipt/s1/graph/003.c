#include <stdio.h>

#define MAXN (200 + 5)

int arr[MAXN][MAXN];
int vis[MAXN], visN = 0, N;

int path[MAXN];

void dfs(int v)
{
    if(vis[v]) return;
    vis[v] = 1;

    if(visN == N) return;
    path[visN++] = v;


    int i;
    for(i = 0; i < N; i++)
        if(arr[v][i])
        {
            //printf("dfs from %d to %d\n", v, i);
            dfs(i);
        }
    if(visN < N)
    {
        visN--;
        vis[v] = 0;
    }
}

char getSymbol()
{
    char c = ' ';
    while(!(c == '#' || c == '+' || c == '-'))
        scanf("%c", &c);

    return(c);
}

void reset()
{
    int i;
    for(i = 0; i < MAXN; i++)
        vis[i] = 0;
    visN = 0;
}
int main()
{
    int i, j;

    for(i = 0; i < MAXN; i++)
        for(j = 0; j < MAXN; j++)
            arr[i][j] = 0;

    scanf("%d", &N);

    char c;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < i; j++)
        {
            c = getSymbol();

//            printf("got: %c\n", c);

            arr[i][j] = (c == '+' ? 1 : 0);
            arr[j][i] = (c == '-' ? 1 : 0);
        }

        c = getSymbol();
    }

/*    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }*/

    for(i = 0; i < N; i++)
    {
        reset();
        dfs(i);
        if(visN == N) break;
    }

    for(i = 0; i < N; i++)
        printf("%d ", path[i] + 1);
    printf("\n");

    return(0);
}
