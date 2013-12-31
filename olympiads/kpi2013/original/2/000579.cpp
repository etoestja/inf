#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int N, t;

unsigned int HASHN = 1650101;
#define RANDC 11234

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
    resN = 0;
    HT.assign(HASHN, false);
    last.reserve(HASHN);
}

bool input_process()
{
    scanf("%d", &N);

    //cout << sizeof(bool) + sizeof(int) << endl;

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        update();
        //dumpSizes();
    }

    for(unsigned int i = 0; i < HASHN; i++)
    {
        if(HT[i])
            res[resN++] = last[i];
    }

	return(resN == 2);
}

void output()
{
    sort2();

    cout << res[0] << " " << res[1] << endl;
}

int main()
{
    init();
    input_process();
    output();
    return 0;
}
