#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::vector;
using std::queue;

unsigned int last_digit(unsigned int N)
{
    return(N % 10);
}

unsigned int first_digit(unsigned int N)
{
    return(N / 1000);
}

unsigned int s_left(unsigned int N)
{
    unsigned int first = first_digit(N);
    N -= first * 1000;
    N *= 10;
    N += first;
    return(N);
}

unsigned int s_right(unsigned int N)
{
    unsigned int last = last_digit(N);
    N /= 10;
    N += 1000 * last;
    return(N);
}

struct c
{
    unsigned int v;
    vector<int> path;
};

bool used[10000];

int main()
{
    unsigned int n1, n2, i, k;
    cin >> n1 >> n2;

    for(i = 1111; i <= 9999; i++) used[i] = 0;

    queue<c> q;
    c t_c, t_c1;

    t_c.v = n1;
    t_c.path.clear();
    q.push(t_c);

    used[n1] = 1;

    while(!q.empty())
    {
        t_c = q.front();
        q.pop();

        if(t_c.v == n2) break;

        if(last_digit(t_c.v) > 1)
        {
            t_c1.v = t_c.v - 1;
            if(!used[t_c1.v])
            {
                used[t_c1.v] = 1;
                t_c1.path = t_c.path;
                t_c1.path.push_back(0);
                q.push(t_c1);
            }
        }

        if(first_digit(t_c.v) < 9)
        {
            t_c1.v = t_c.v + 1000;
            if(!used[t_c1.v])
            {
                used[t_c1.v] = 1;
                t_c1.path = t_c.path;
                t_c1.path.push_back(1);
                q.push(t_c1);
            }
        }

        t_c1.v = s_left(t_c.v);
        if(!used[t_c1.v])
        {
            used[t_c1.v] = 1;
            t_c1.path = t_c.path;
            t_c1.path.push_back(2);
            q.push(t_c1);
        }

        t_c1.v = s_right(t_c.v);
        if(!used[t_c1.v])
        {
            used[t_c1.v] = 1;
            t_c1.path = t_c.path;
            t_c1.path.push_back(3);
            q.push(t_c1);
        }
    }

    vector<int>::iterator it;
    k = n1;
    cout << n1 << endl;
    for(it = t_c.path.begin(); it != t_c.path.end(); it++)
    {
        if((*it) == 0) k--;
        else if((*it) == 1) k += 1000;
        else if((*it) == 2) k = s_left(k);
        else if((*it) == 3) k = s_right(k);
        cout << k << endl;
    }

    return 0;
}
