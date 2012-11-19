#include <stdio.h>

#define DEBUG 0

#define MAXN (2000 + 5)

short int arr[MAXN][MAXN];

int N, K, C;
int pairOf[MAXN];

int vis[MAXN], p[MAXN];

inline int getN(int v)
{
    return(v < N ? 0 : 1);
}

int dfs(int v, int v0)
{
    if(vis[v]) return -1;
    vis[v] = 1;
    int j, t = -1, mmin = ((getN(v) == 0) ? N : 0), mmax = ((getN(v) == 0) ? N + K : N);
    for(j = mmin; j < mmax; j++)
        if(arr[v][j])
        {
            if(DEBUG) printf("dfs from %d type %d: found vertex %d, ", v, getN(v), j);
            if(pairOf[j] == -1 && getN(j) != getN(v0))
            {
                p[j] = v;
                if(DEBUG) printf("and it is a free one\n");
                return j;
            }
            if(DEBUG) printf("starting new dfs to vertex\n");
            t = dfs(j, v0);
            if(t != -1)
            {
                p[j] = v;
                return(t);
            }
        }
    return(-1);
}


int tryBetterOne(int v)
{
    if(pairOf[v] != -1) return 0;
    int i, e, e0, flag;
    for(i = 0; i < N + K; i++)
    {
        vis[i] = 0;
        p[i] = -1;
    }

    e = e0 = dfs(v, getN(v));

    if(DEBUG) printf("betterOne from %d: ", v);

    if(DEBUG)
    {
        if(e == -1) printf(" found nothing\n");
        else printf(" found %d\n", e);
    }

    flag = 0;

    for(; e != -1; e = p[e]) // path from x to y
    {
        if(DEBUG) printf("extracting from %d, %d, ", e, p[e]);
        if(p[e] != -1)
        {
            // edge e, p[e] exists in the path
            if(pairOf[e] == p[e] && pairOf[p[e]] == e)
            {
                if(DEBUG) printf("destroying edge");
                pairOf[pairOf[e]] = -1;
                pairOf[pairOf[p[e]]] = -1;
            }
            if(!flag)
            {
                if(DEBUG) printf("connecting edge");
                pairOf[e] = p[e];
                pairOf[p[e]] = e;
                flag = 1;
            }
            else flag = 0;
        }
        if(DEBUG) printf("\n");
    }

    if(DEBUG) printf("\n\n");

    return(e0 == -1 ? 0 : 1);
}

int tryBetter()
{
    int i, res = 0;
    for(i = 0; i < N; i++)
        res |= tryBetterOne(i);
    return(res);
}

int main()
{
    int i, j;

    for(i = 0; i < MAXN; i++)
    {
        for(j = 0; j < MAXN; j++)
            arr[i][j] = 0;
        pairOf[i] = -1;
    }

    scanf("%d", &N);
    scanf("%d", &K);
    scanf("%d", &C);

    int x, y;
    for(i = 0; i < C; i++)
    {
        scanf("%d", &x);
        scanf("%d", &y);
        x--;
        y--;
        arr[x][y + N] = 1;
        arr[y + N][x] = 1;
    }

    if(DEBUG){
        for(x = 0; x < K + N; x++)
        {
            for(y = 0; y < K + N; y++)
                printf("%d ", arr[x][y]);
            printf("\n");
        }
    }
  
    while(tryBetter());
    tryBetter();

    int count = 0;

    for(i = 0; i < N; i++)
        if(pairOf[i] != -1) count++;

    printf("%d\n", count);

    for(i = 0; i < N; i++)
    {
        if(pairOf[i] != -1)
            printf("%d %d\n", i + 1, pairOf[i] - N + 1);
    }

    return(0);
}
