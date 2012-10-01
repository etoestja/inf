#include <iostream>
#include <vector>
#include <queue>
//#include <map>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::vector;
using std::queue;
//using std::map;

const long long base = 10;
typedef vector<unsigned short> long_;

const unsigned int DIG = 10;
unsigned int k;
bool allowed[DIG];
//map<long_, bool> used;
long_ X;

unsigned int digits_num(long long x)
{
    for(r = 0; x; x /= 10) r++;

    return(r);
}

bool d(long_ x)
{
    if(x.size() < digits_num(k)) return(0);
    else
    {

    }
}

void print_long(long_ x)
{
    long_::iterator it;
    for(it = x.begin(); it != x.end(); it++) cout << *it;
}

int main()
{
    unsigned int D, i, m;

    for(i = 0; i < DIG; i++) allowed[i] = 0;

    char c;
    for(c = cin.get(); c >= '0' && c <= '9'; c = cin.get()) X.push_back(c - '0');

    cin >> k >> D;

    for(i = 0; i < D; i++)
    {
        cin >> m;
        allowed[m] = 1;
    }

    long_ t, t1;
    if(d(t))
    {
        print_long(X);
        //print_long(t);
        cout << endl;
        return 0;
    }

    queue<long_> q;
    q.push(t);

    bool found = false;

    while(!q.empty())
    {
        t = q.front();
        q.pop();

        for(i = 0; i < DIG; i++)
        {
            if(allowed[i])
            {
                t1 = t;
                t1.push_back(i);
                if(d(t1))
                {
                    while(!q.empty()) q.pop();
                    found = true;
                    break;
                }
                /*else if(!used[t1])*/ q.push(t1);
            }
        }
    }

    if(found)
    {
        print_long(X);
        print_long(t);
        cout << endl;
    }
    else cout << "-1" << endl;

    return 0;
}
