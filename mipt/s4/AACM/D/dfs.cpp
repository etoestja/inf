#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define NMAX 100

int arr[NMAX][NMAX];
int d[NMAX], f[NMAX];
bool visited[NMAX];

int N;

int timeC;

void dfs(int v)
{
    if(visited[v]) return;

    visited[v] = true;
    d[v] = timeC++;

    for(int i = 0; i < N; i++)
        if(arr[v][i] && i != v && !visited[i])
            dfs(i);

    f[v] = timeC++;
}

void dump()
{
    cout << "==== DUMP (d, f) ====" << endl;
    for(int i = 0; i < N; i++)
    {
        cout << d[i] << "\t";
    }

    cout << endl;

    for(int i = 0; i < N; i++)
    {
        cout << f[i] << "\t";
    }

    cout << endl;
}

int main()
{
    timeC = 1;

    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];

    for(int i = 0; i < N; i++)
    {
        dfs(i);
        cout << "dfs from " << i << " finished" << endl;
        dump();
    }

    return(0);
}
