#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define NMAX 100

int N;
double arr[NMAX][NMAX];

double r[NMAX];
int p[NMAX];

void init(int s)
{
    for(int i = 0; i < N; i++)
    {
        p[i] = -1;
        r[i] = 0;
    }

    r[s] = 1;
}

void dump()
{
    for(int i = 0; i < N; i++)
        cout << "r[" << i << "]=" << r[i] << endl;
}

void solve(int s, int t)
{
    init(s);

    for(int i = 0; i < N; i++)
        for(int u = 0; u < N; u++)
            for(int v = 0; v < N; v++)
            {
                double *r0 = &(r[v]);
                double r1 = r[u] * arr[u][v];
                if(*r0 < r1)
                {
                    *r0 = r1;
                    p[v] = u;
                }
            }

    for(int k = t; k != -1; k = p[k])
        cout << k << " ";
    cout << endl;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];

    int s, t;
    cin >> s >> t;
    solve(s, t);

    dump();

    return(0);
}
