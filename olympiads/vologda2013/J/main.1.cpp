#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <cstdio>

using namespace std;

#define P 29989
#define X 27283
#define LMAX 11

struct word
{
    char* x;
    vector<char*> syns;
};

int hash(char* x)
{
    int L = strlen(x) - 1;
    int res = 0;
    for(; L >= 0; L--)
    {
        res *= X;
        res %= P;
        res += x[L];
        res %= P;
        if(res < 0) res = -res;
    }
    return(res);
}

unsigned M, Q, i;

vector<word> arr[X];

unsigned find(char* x)
{
    for(unsigned i = 0; i < arr[hash(x)].size(); i++)
    {
        if(!(strcmp(arr[hash(x)][i].x, x)))
        {
            return(i);
        }
    }
    return(-1);
}

bool exists_link(char* x, char* y)
{
    vector<char*>::iterator it;
    for(it = arr[hash(x)][find(x)].syns.begin(); it != arr[hash(x)][find(x)].syns.end(); it++)
    {
        if(!strcmp(*it, y)) return(1);
    }
    return(0);
}

void addlink(char* x, char* y)
{
    int p1;
    word w1;
    w1.x = x;
    if((p1 = find(x)) == -1)
    {
        arr[hash(x)].push_back(w1);
        p1 = arr[hash(x)].size() - 1;
    }
    if(!exists_link(x, y)) arr[hash(x)][p1].syns.push_back(y);

    int p2;
    word w2;
    w2.x = y;
    if((p2 = find(y)) == -1)
    {
        arr[hash(y)].push_back(w2);
        p2 = arr[hash(y)].size() - 1;
    }
    if(!exists_link(y, x)) arr[hash(y)][p2].syns.push_back(x);

}

int main()
{
    scanf("%u", &M);
    scanf("%u", &Q);
    char x[LMAX], y[LMAX];
    for(int i = 0; i < M; i++)
    {
        scanf("%s", x);
        scanf("%s", y);
        addlink(x, y);
    }

    unsigned K, j;

    char* ty;

    queue<char*> myqueue;
    vector<char*> tmpvec;
    vector<char*>::iterator it;

    for(int i = 0; i < Q; i++)
    {
        scanf("%s", x);
        scanf("%u", &K);

        while(!myqueue.empty()) myqueue.pop();
        myqueue.push(x);
        tmpvec.clear();
        while(!myqueue.empty() && j < K)
        {
            y = myqueue.front();
            myqueue.pop();
            if(strcmp(x, y))
            {
                tmpvec.push_back(y);
            }
            for(it = arr[hash(y)][find(y)].syns.begin(), it != arr[hash(y)][find(y)].syns.end(); it++)
            {
                myqueue.push(*it);
            }
        }
    }

    return 0;
}
