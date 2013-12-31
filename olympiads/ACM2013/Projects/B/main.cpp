#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#define N 16
#define L 255

//#define DEBUG

char arr[N];
int used[N];
int len;
int cti[L];
char itc[N];
string str;

char intToChar(int a)
{
    if(a < 10)
        return('0' + a);
    else return('A' + a - 10);
}

int chatToInt(char c)
{
    if(c <= '9')
        return(c - '0');
    else return(c - 'A' + 10);
}

void fillt()
{
    for(int i = 0; i < N; i++)
    {
        itc[i] = intToChar(i);
        cti[itc[i]] = i;
    }
}

void init()
{
    for(int i = 0; i < N; i++)
    {
        used[i] = 0;
        arr[i] = -1;
    }

    for(int i = 0; i < len; i++)
        arr[i] = str[i];
}

void printArr()
{
    for(int i = 0; i < len; i++)
    {
        cout << itc[arr[i]];
    }
    cout << endl;
}

bool fillLast(int start)
{
    int can;
    for(int i = start; i < len; i++)
    {
        can = 0;
        for(int j = 0; j < N; j++)
        {
            if(!used[j])
            {
                used[j] = 1;
                arr[i] = j;
                can = 1;
                break;
            }
        }
        if(!can)
            return(false);
    }
    return(true);
}

bool solve_blen()
{
    int i;
    for(i = 1; i < N; i++)
        if(!used[i])
            break;
    if(i < N)
    {
        init();
        used[i] = 1;
        if(fillLast(0));
        {
            cout << itc[i];
            printArr();
            return(true);
        }
    }
    return(false);
}

bool solve_clen()
{
    int pos, current;
    bool can;
    for(pos = len - 1; pos >= 0; pos--)
    {
#ifdef DEBUG
        cout << "pos=" << pos << endl;
#endif

        for(current = str[pos] + 1; current < N; current++)
        {
#ifdef DEBUG
            cout << " current=" << itc[current] << endl;
#endif
            init();
            can = true;
            for(int i = 0; i < pos; i++)
            {
                if(used[str[i]])
                {
                    can = false;
                    break;
                }
                used[str[i]] = 1;
            }
            if(used[current])
                can = false;
            used[current] = 1;
            arr[pos] = current;
            if(!can) continue;
            if(fillLast(pos + 1))
            {
                printArr();
                return(true);
            }
            else continue;
        }
    }
    return(false);
}

void solve()
{
    if(solve_clen())
    {
#ifdef DEBUG
        cout << "solve clen" << endl;
#endif
        return;
    }
    else
    {
#ifdef DEBUG
        cout << "solve blen" << endl;
#endif
        solve_blen();
    }
}

void input()
{
    cin >> str;
    len = str.length();
    for(int i = 0; i < len; i++)
        str[i] = cti[str[i]];
}


int main()
{
    fillt();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    input();
    solve();
    return(0);
}
