#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define NMAX 100000

typedef pair<int, int> edge;
typedef pair<int, int> path;

int N;
vector<edge> g[NMAX];
vector<bool> v(NMAX);

vector<edge> P(NMAX);
bool writeP;

edge md;
int mdL;

int x, y, z;
int d1, d2;

void bfsInit()
{
    v.assign(NMAX, false);
}

path bfsM(int i)
{
    bfsInit();
    cerr << "bfs from " << i + 1 << endl;
    path res;
    res.first = i;
    res.second = 0;

    queue<path> q;
    q.push(make_pair(i, 0));

    path t, t1;

    vector<edge>::iterator it;

    while(!q.empty())
    {
        t = q.front();
        q.pop();

        v[t.first] = true;

        cerr << "bfs @ " << (t.first + 1) << " len=" << t.second << endl;

        for(it = g[t.first].begin(); it != g[t.first].end(); it++)
        {
            t1 = *it;
            if(!v[t1.first])
            {
                if(writeP)
                    P[t1.first] = make_pair(t.first, t1.second);
                t1.second += t.second;

                if(t1.second > res.second)
                    res = t1;

                q.push(t1);
            }
        }
    }
    return(res);
}

void getM()
{
    writeP = false;
    path p1 = bfsM(0);

    writeP = true;
    P[p1.first] = make_pair(-1, -1);
    path p2 = bfsM(p1.first);
    md.first = p1.first;
    md.second = p2.first;
    mdL = p2.second;
}

void getXYZ()
{
    x = y = z = -1;
    edge v;
    int Lsum = 0;
    for(v = make_pair(md.second, 0); v.first != md.first; v = P[v.first])
    {
        //v.first <---> P[v.first].first
        d1 = Lsum;
        Lsum += P[v.first].second;
        d2 = Lsum;
        cerr << "Restore @ " << v.first + 1 << " <---> " << P[v.first].first + 1 << " L=" << P[v.first].second << " Lsum=" << Lsum << " ";
        cerr << "d1=" << d1 << " d2=" << d2 << endl;

        if(2 * Lsum == mdL)
        {
            z = P[v.first].first;
            return;
        }
        else if(2 * d1 < mdL && 2 * d2 > mdL)
        {
            cerr << "xy" << endl;
            x = v.first;
            y = P[v.first].first;
            return;
        }
    }
}

void printAns()
{
    if(z != -1)
    {
        cout << "IN TOWN" << endl << (z + 1) << endl;
    }
    if(x != -1 && y != -1)
    {
        cout << "ON ROAD" << endl;
        cout << (x + 1) << " " << (y + 1) << " ";
        cout << (((double) mdL) / 2. - d1) << endl;
    }
}

int main()
{
    cin >> N;
    int v1, v2, d;
    for(int i = 0; i < N - 1; i++)
    {
        cin >> v1 >> v2 >> d;
        v1--;
        v2--;
        g[v1].push_back(make_pair(v2, d));
        g[v2].push_back(make_pair(v1, d));
    }

    getM();

    cerr << "max dist " << mdL << " from " << (md.first + 1) << " to " << (md.second + 1) << endl;

    getXYZ();
    printAns();

    return(0);
}
