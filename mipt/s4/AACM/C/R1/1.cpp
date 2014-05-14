#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define NMAX 100

int arr[NMAX][NMAX];
int color[NMAX];
int visited[NMAX];

#define nextColor(x) ((x + 1) % 2)

int N;

int dfs(int v, int startColor)
{
    if(visited[v])
        return(startColor != color[v]);

    visited[v] = 1;
    color[v] = startColor;

    for(int i = 0; i < N; i++)
        if(i != v && arr[i][v])
        {
            if(dfs(i, nextColor(startColor)))
                return(1);
        }

    return(0);
}

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];

    for(int i = 0; i < N; i++)
        visited[i] = 0;

    bool ans = true;

    for(int i = 0; i < N; i++)
        if(!visited[i])
        {
            if(dfs(i, 0)) ans = false;
            break;
        }

    cout << (ans ? "YES" : "NO") << endl;

    return(0);
}
