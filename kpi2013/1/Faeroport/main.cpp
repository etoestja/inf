#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define NMAX 100005

//#define DEBUG
#undef DEBUG

typedef pair<long long, long long> edge;
typedef pair<long long, long long> path;

long long N;
vector<edge> g[NMAX];
vector<bool> v(NMAX);

vector<edge> P(NMAX);
bool writeP;

edge md;
long long mdL;

long long x, y, z;
long long d1, d2;

void bfsInit()
{
    v.assign(NMAX, false);
}

path bfsM(long long i)
{
    bfsInit();
#ifdef DEBUG
    cerr << "bfs from " << i + 1 << endl;
#endif
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

#ifdef DEBUG
        cerr << "bfs @ " << (t.first + 1) << " len=" << t.second << endl;
#endif

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
    long long Lsum = 0;
    for(v = make_pair(md.second, 0); v.first != md.first; v = P[v.first])
    {
        //v.first <---> P[v.first].first
        d1 = Lsum;
        Lsum += P[v.first].second;
        d2 = Lsum;
#ifdef DEBUG
        cerr << "Restore @ " << v.first + 1 << " <---> " << P[v.first].first + 1 << " L=" << P[v.first].second << " Lsum=" << Lsum << " ";
        cerr << "d1=" << d1 << " d2=" << d2 << endl;
#endif

        if(2 * Lsum == mdL)
        {
            z = P[v.first].first;
            return;
        }
        else if(2 * d1 < mdL && 2 * d2 > mdL)
        {
#ifdef DEBUG
            cerr << "xy" << endl;
#endif
            x = v.first;
            y = P[v.first].first;
            return;
        }
    }
}

void printAns()
{
    if(N == 1)
        z = 0;

    if(z != -1)
    {
        cout << "IN TOWN" << endl << (z + 1) << endl;
    }
    else if(x != -1 && y != -1)
    {
        cout.precision(10);
        cout << "ON ROAD" << endl;
        cout << (x + 1) << " " << (y + 1) << " ";
        cout << (((double) mdL) / 2. - d1) << endl;
    }
}


int main()
{
    cin >> N;
    long long v1, v2, d;
    for(long long i = 0; i < N - 1; i++)
    {
        cin >> v1 >> v2 >> d;
        v1--;
        v2--;
        g[v1].push_back(make_pair(v2, d));
        g[v2].push_back(make_pair(v1, d));
    }

    getM();

#ifdef DEBUG
    cerr << "max dist " << mdL << " from " << (md.first + 1) << " to " << (md.second + 1) << endl;
#endif

    getXYZ();
    printAns();

    return(0);
}
