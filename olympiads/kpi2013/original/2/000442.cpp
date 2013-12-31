#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int N, t;

#define HASHN 100000
#define RANDC 100

int hash(int k)
{
    if(k >= 0)
        return(abs(k) % HASHN);
    else
        return((RANDC - k) % HASHN);
}

vector<int> HT[HASHN];

void update()
{
    vector<int>::iterator it;
    int h = hash(t);

    for(it = HT[h].begin(); it != HT[h].end(); it++)
    {
        if((*it) == t)
        {
            HT[h].erase(it);
            return;
        }
    }
    HT[h].push_back(t);
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

void dumpSizes()
{
    for(unsigned int i = 0; i < HASHN; i++)
    {
        if(HT[i].size() != 0)
        {
            cerr << "size[" << i << "]=" << HT[i].size() << endl;
        }
    }
}

int main()
{
    scanf("%d", &N);

    //cout << sizeof(vector<int>) << endl;

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        update();
        //dumpSizes();
    }

    for(int i = 0; i < HASHN; i++)
    {
        if(HT[i].size() == 1)
        {
            res[resN++] = HT[i][0];
            //cout << "adding" << endl;
        }
        else if(HT[i].size() == 2)
        {
            res[resN++] = HT[i][0];
            //cout << "adding" << endl;
            res[resN++] = HT[i][1];
            //cout << "adding" << endl;
        }
    }

    sort2();

    cout << res[0] << " " << res[1] << endl;

	return 0;
}
