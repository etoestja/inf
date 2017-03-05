#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using std::sort;
using std::find;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;

#define NMAX 200005

vector<int> adj[NMAX];

vector<int> u2[NMAX];

int N;

int color[NMAX];

struct i2
{
    int vertex;
    int distance;
};

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
        color[i] = 0;
    for(int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < N; i++)
    {
        queue<i2> q;
        i2 vd;
        vd.vertex = i;
        vd.distance = 0;
        q.push(vd);
        int vis[NMAX];
        for(int j = 0; j < N; j++)
            vis[j] = 0;
        while(!q.empty())
        {
            vd = q.front();
            vis[vd.vertex] = 1;
            //cout << "i = " << i << " vd = " << vd.vertex << " dst = " << vd.distance << endl;
            if(vd.distance >= 0 && vd.distance < 2)
            {
                for(int j = 0; j < N; j++)
                {
                    if(find(adj[vd.vertex].begin(), adj[vd.vertex].end(), j) != adj[vd.vertex].end() && !vis[j])
                    {
                        i2 vd1;
                        vd1.distance = vd.distance + 1;
                        vd1.vertex = j;
                        u2[i].push_back(j);
                        q.push(vd1);
                        //cout << "i = " << i << " vd = " << vd.vertex << " dst = " << vd.distance << " add j = " << j << endl;
                    }
                }
            }
            q.pop();
        }
    }

    int maxk = 0;

    queue<int> q;
    q.push(0);
    int vis[NMAX];
    for(int j = 0; j < N; j++)
        vis[j] = 0;
    while(!q.empty())
    {
        int i = q.front();
        q.pop();
        //cout << "i = " << i << endl;
        if(vis[i])
            continue;
        vis[i] = 1;

        int clr = 1;

        vector<int> vv;

        for(int j = 0; j < u2[i].size(); j++)
        {
            vv.push_back(color[u2[i][j]]);
            //cout << "i = " << i << " j = " << j << " color = " << color[u2[i][j]] << endl;
        }
        sort(vv.begin(), vv.end(), std::less<int>());

        for(int j = 0; j < vv.size(); j++)
        {
            //cout << "i = " << i << " j = " << j << " clr = " << vv[j] << endl;
            if(vv[j] == clr)
                clr++;
        }

        if(clr > maxk)
            maxk = clr;
        color[i] = clr;

        for(int j = 0; j < adj[i].size(); j++)
        {
            q.push(adj[i][j]);
        }
    }

/*    for(int i = 0; i < N; i++)
    {
        cout << "NODE " << i << endl << "ADJ: ";
        for(int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl << "U2: ";
        for(int j = 0; j < u2[i].size(); j++)
        {
            cout << u2[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << maxk << endl;
    for(int i = 0; i < N; i++)
    {
        cout << color[i] << " ";
    }

    cout << endl;
    return(0);
}
