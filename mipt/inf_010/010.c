#include <stdio.h>

#define NMAX (2 * 1000)

int arr[NMAX][NMAX];
int vis[NMAX];
int pairOf[NMAX];
int p[NMAX];

int N, K, C;

int getP(int v)
{
    return(v < N ? 0 : 1);
}

int dfs(int v, int p0)
{
    if(vis[v])
        return(0);

    vis[v] = 1;

    if(getP(v) != p0) //should be red
    {
        if(pairOf[v] != -1)
        {
            int j = dfs(pairOf[v], p0);
            if(j != -1)
            {
                p[pairOf[v]] = v;
                return(j);
            }
        }
    }
    else //should not be red
    {
        int j, j1,
            jmin = (getP(v) == 0 ? N     : 0),
            jmax = (getP(v) == 0 ? N + K : N);
        for(j = jmin; j < jmax; j++)
        {
            if(arr[v][j] && !vis[j])
            {
                if(pairOf[j] == -1)
                {
                    //white vertex on the other side
                    p[j] = v;
                    return(j);
                }
                else if(pairOf[j] != v)
                {
                    j1 = dfs(j, p0);
                    if(j1 != -1)
                    {
                        p[j] = v;
                        return(j1);
                    }
                }
            }
        }
    }
    return(-1);
}

int c(int v)
{
    int e, e1, e0;

    if(pairOf[v] != -1) return(0);

    for(e = 0; e < N + K; e++)
    {
        vis[e] = 0;
        p[e] = -1;
    }

    e0 = e = dfs(v, getP(v));
    if(e == -1)
        return(0);

    for(; p[e] != -1; e = p[e])
    {
        if(getP(e) == getP(e0))
        {
            pairOf[e] = p[e];
            e1 = pairOf[p[e]];
            if(e1 != -1)
            {
                pairOf[p[e]] = -1;
                pairOf[e1] = -1;
            }
            pairOf[p[e]] = e;
        }
    }

    return(1);
}

int c0()
{
    int i;
    for(i = 0; i < N; i++)
        if(c(i)) return(1);
    return(0);
}

int main()
{
    int i, j, t1, t2;
    for(i = 0; i < NMAX; i++)
    {
        pairOf[i] = -1;
        for(j = 0; j < NMAX; j++)
            arr[i][j] = 0;
    }

    scanf("%d", &N);
    scanf("%d", &K);
    scanf("%d", &C);

    for(i = 0; i < C; i++)
    {
        scanf("%d", &t1);
        scanf("%d", &t2);
        t1--;
        t2--;
        t2 += N;
        arr[t1][t2] = 1;
        arr[t2][t1] = 1;
    }

    while(c0());

    int r = 0;
    for(i = 0; i < N; i++)
        if(pairOf[i] != -1) r++;

    printf("%d\n", r);

    if(r)
    {
        for(i = 0; i < N; i++)
        {
            if(pairOf[i] != -1)
                printf("%d %d\n", i + 1, pairOf[i] + 1 - N);
        }
    }

    return(0);
}
