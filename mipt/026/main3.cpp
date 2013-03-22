#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::queue;
using std::pair;

const unsigned N = 2000000, INF = N + 1;

typedef pair<unsigned, unsigned> value; //first is for number, second if for path

unsigned len[N], prev[N];

int main()
{
    unsigned n, i, ans;

    for(i = 0; i < N; i++) len[i] = INF;

    cin >> n;

    prev[n] = INF;

    queue<value> q;
    q.push(value(n, 0));

    value t, t1;

    while(!q.empty())
    {
        t = q.front();
        q.pop();

        if(len[t.first] > t.second)
        {
            len[t.first] = t.second;
            if((t.first % 2) == 0)
            {
                q.push(value(t.first / 2, t.second + 1));
                prev[t.first / 2] = t.first;
            }
            if(t.first < n + 5)
            {
                q.push(value(t.first + 1, t.second + 1));
                prev[t.first + 1] = t.first;
            }
            if(t.first > 0)
            {
                q.push(value(t.first - 1, t.second + 1));
                prev[t.first - 1] = t.first;
            }
        }

    }

    cout << len[0] << endl;
//    for(unsigned prev1 = prev[0]; prev1 != 0; prev1 = prev[prev1]) cout << prev1 << "\t";
    cout << endl;


    return 0;
}
