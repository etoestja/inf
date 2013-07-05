#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int N, t;

#define HASHN 1600101
#define RANDC 100

inline int hash(int k)
{
    if(k >= 0)
        return(k % HASHN);
    else
        return((RANDC - k) % HASHN);
}

vector<bool> HT;
vector<int> last;
int h;

inline void update()
{
    h = hash(t);
    if(HT[h] == 0)
        last[h] = t;
    HT[h] = HT[h] ^ 1;
}

int res[2];
int resN = 0;

void sort2()
{
    int k = res[0];
    if(res[0] > res[1])
    {
        res[0] = res[1];
        res[1] = k;
    }
}

void init()
{
    HT.assign(HASHN, false);
    last.reserve(HASHN);
}

int main()
{
    init();
    scanf("%d", &N);

    //cout << sizeof(bool) + sizeof(int) << endl;

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        update();
        //dumpSizes();
    }

    for(int i = 0; i < HASHN; i++)
    {
        if(HT[i])
            res[resN++] = last[i];
    }

    sort2();

    cout << res[0] << " " << res[1] << endl;

	return 0;
}
