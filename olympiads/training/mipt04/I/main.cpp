#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

typedef pair< pair<int, int>, int> pc;

vector<pc> pcs;
vector<int> sockets;

int typeaf, typebf;

int n, a, b, c = 0, a0, b0;

long long pcUsed = 0, power = 0;

inline void addA(pc p)
{
    sockets[typeaf] = p.second;
    a--;
    typeaf++;

    pcUsed++;
    power += p.first.first;
}

inline void addB(pc p)
{
    sockets[typebf] = p.second;
    b--;
    typebf++;

    pcUsed++;
    power += p.first.first;
}

void fill3()
{
    pc p;
    for(int i = 0; i < n; i++)
    {
        p = pcs[i];

        if(p.first.second != 3) continue;

        if(a > 0)
            addA(p);
        else if(b > 0)
            addB(p);
        else
            return;
    }
}

int main()
{
    cin >> n >> a >> b;

    a0 = a;
    b0 = b;

    sockets.resize(a + b, -1);

    typeaf = 0;
    typebf = a;

    int t, w;

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &t);
        scanf("%d", &w);
        pc tpc;
        tpc.second = i;
        tpc.first.second = t;
        tpc.first.first = w;
        pcs.push_back(tpc);
    }

    sort(pcs.begin(), pcs.end());

    pc p;

    for(int i = 0; i < n; i++)
    {
        if(a + b <= c)
            break;

        if(i == n) break;

        p = pcs[i];
        if(p.first.second == 1 && a > 0)
            addA(p);
        if(p.first.second == 2 && b > 0)
            addB(p);
        if(p.first.second == 3)
            c++;
    }

    fill3();

    cout << pcUsed << " " << power << endl;

    for(int i = 0; i < a0 + b0; i++)
    {
        if(sockets[i] != -1)
        {
            cout << sockets[i] << " " << (i + 1) << endl;
        }
    }

    return 0;
}

