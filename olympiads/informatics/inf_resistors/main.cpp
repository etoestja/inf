#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::queue;
using std::string;

struct c
{
    unsigned int used;
    long double value;
};

string binary_print(unsigned int N)
{
    int i;
    string res;
    for(i = 7; i >= 0; i--)
        res.append((N & (1 << i)) ? "1" : "0");

    return(res);
}

vector<long double> values;
queue<c> q;
vector<c> cs;
unsigned int N;
long double n, min_dist, res;

int main()
{
    unsigned int i;

    c t_c, t_c1, t_c2;

    long double t;
    cin >> N >> n;
    for(i = 0; i < N; i++)
    {
        cin >> t;
        if(!i)
        {
            min_dist = fabs(t - n);
            res = t;
        }

        values.push_back(t);
        t_c.value = t;
        t_c.used = 1 << i;
        q.push(t_c);
        cs.push_back(t_c);
    }

    vector<c>::iterator it1;
    unsigned int end;

    while(!q.empty())
    {
        t_c = q.front();
        q.pop();

        if(fabs(t_c.value - n) < min_dist)
        {
            min_dist = fabs(t_c.value - n);
            res = t_c.value;
            if(min_dist == 0)
            {
                end = 0;
                while(!q.empty()) q.pop();
            }
        }

        end = cs.size();
        for(i = 0; i < end; i++)
        {
            if((cs[i].used & t_c.used) == 0)
            {
                t_c1.used = cs[i].used | t_c.used;
                t_c2.used = t_c1.used;
                t_c1.value = cs[i].value + t_c.value;
                t_c2.value = cs[i].value * t_c.value / t_c1.value;

                for(it1 = cs.begin(); it1 != cs.end(); it1++)
                    if((*it1).used == t_c1.used && (*it1).value == t_c1.value) break;

                if(it1 == cs.end())
                {
                    /*cout << "min_dist=" << min_dist << " res=" << res << "; "
                        << "curr" << " value=" << t_c.value << " used=" << binary_print(t_c.used) << "; adding value=" << t_c1.value
                        << " used=" << binary_print(t_c1.used) << endl;*/
                    q.push(t_c1);
                    cs.push_back(t_c1);
                }

                for(it1 = cs.begin(); it1 != cs.end(); it1++)
                    if((*it1).used == t_c2.used && (*it1).value == t_c2.value) break;

                if(it1 == cs.end())
                {
                    /*cout << "min_dist=" << min_dist << " res=" << res << "; "
                        << "curr" << " value=" << t_c.value << " used=" << binary_print(t_c.used) << "; adding value=" << t_c2.value
                        << " used=" << binary_print(t_c2.used) << endl;*/
                    q.push(t_c2);
                    cs.push_back(t_c2);
                }
            }
        }
    }

    cout.precision(20);
    cout << res << endl;

    return 0;
}
