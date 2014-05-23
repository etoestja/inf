#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

#define NMAX 100

int arr[NMAX][NMAX];
int d[NMAX], f[NMAX];
bool visited[NMAX];

int type[NMAX][NMAX];

enum _type{EDGE_TREE = 0, EDGE_BACK, EDGE_FORWARD, EDGE_CROSS};
const char* _typeN[] = {"tree", "back", "forward", "cross"};

int N;

int timeC;

bool contains(vector<int> &a, int b)
{
    for(vector<int>::iterator it = a.begin(); it != a.end(); it++)
        if(*it == b)
            return(true);
    return(false);
}

void dfs(int v, vector<int> prevVisited)
{
    cout << "dfs from " << v << endl;
    if(visited[v]) return;

    visited[v] = true;
    d[v] = timeC++;

    int K = prevVisited.size();
    for(int i = 0; i < K - 1; i++)
    {
        if(arr[prevVisited[i]][v]) type[prevVisited[i]][v] = EDGE_FORWARD;
    }

    vector<int> prevVisitedV = prevVisited;
    prevVisitedV.push_back(v);

    for(int i = 0; i < N; i++)
        if(arr[v][i] && i != v)
        {
            if(!visited[i])
            {
                type[v][i] = EDGE_TREE;
                dfs(i, prevVisitedV);
            }
            else if(contains(prevVisited, i))
                type[v][i] = EDGE_BACK;
        }

    f[v] = timeC++;
}

void prepare()
{
    timeC = 1;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            type[i][j] = EDGE_CROSS;

    for(int i = 0; i < N; i++)
        visited[i] = false;
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

void printEdges()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            if(arr[i][j])
            {
                cout << "(" << (i + 1) << "," << (j + 1) << ")\t" << _typeN[type[i][j]] << " ";
                if(d[i] < d[j] && d[j] < f[j] && f[j] < f[i])
                    cout << "T or F";
                if(d[j] <= d[i] && d[i] < f[i] && f[i] <= f[j])
                    cout << "B";
                if(d[j] < f[j] && f[j] < d[i] && d[i] < f[i])
                    cout << "C";
                cout << endl;
            }
        cout << endl;
    }
}

int main()
{
    cin >> N;

    prepare();

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];

    for(int i = 0; i < N; i++)
    {
        dfs(i, vector<int>());
        cout << "dfs from " << i << " finished" << endl;
        dump();
    }

    printEdges();

    return(0);
}
