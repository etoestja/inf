#include <iostream>
#include <vector>
#include <string.h>

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
        if(!strcmp(arr[hash(x)][i], x))
        {
            return(i)
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

    if(!arr[hash(x)][p1])

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
    
    
    char x[200];
    cin >> x;
    cout << hash(x) << endl;
    return 0;
}
