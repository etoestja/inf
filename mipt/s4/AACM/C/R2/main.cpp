#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define NMAX 100

int arr[NMAX][NMAX];
int visited[NMAX];

int N;

void dfs(int v)
{
    if(visited[v])
        return;

    visited[v] = 1;
    cout << v << " ";

    for(int i = 0; i < N; i++)
        if(i != v && arr[i][v])
            dfs(i);
}

void find()
{
    for(int i = 0; i < N; i++)
        visited[i] = 0;

    for(int i = 0; i < N; i++)
        if(!visited[i])
        {
            dfs(i);
            cout << endl;
        }
}

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];

    find();

    return(0);
}
