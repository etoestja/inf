#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const long long int M_ = 500, TIME = 1440, INF = M_ * M_ * TIME;
int arr[M_][M_], used[M_];
long long int mass[M_][M_], len[M_];

unsigned int N, M;

void cl()
{
    unsigned int i, si;
    for(i = 0; i < M_; i++)
    {
        used[i] = 0;
        len[i] = INF;
    }

    len[0] = 0;
}

bool check(long long int m)
{
    cl();

    unsigned int i, j, si;
    for(i = 0; i < N; i++)
    {
        j = N;
        for(si = 0; si < N; si++)
           if(!used[si] && (j == N || len[si] < len[j])) j = si;

        if(len[j] == INF) break;
        used[j] = 1;

        for(si = 0; si < N; si++)
           if(si != j && arr[j][si] >= 0 && mass[j][si] >= m &&
             len[si] > len[j] + arr[j][si])
                len[si] = len[j] + arr[j][si];
    }

    return(len[N - 1] <= TIME);
}

int main()
{
    unsigned int i, j, si, t1, t2;

    cin >> N >> M;

    for(i = 0; i < N; i++)
        for(si = 0; si < N; si++)
        {
            arr[i][si] = -1;
            mass[i][si] = 0;
        }

    for(i = 0; i < M; i++)
    {
        cin >> t1 >> t2;
        t1--;
        t2--;
        cin >> arr[t1][t2] >> mass[t1][t2];
        mass[t1][t2] -= 3000000;
        mass[t1][t2] /= 100;

        arr[t2][t1] = arr[t1][t2];
        mass[t2][t1] = mass[t1][t2];
    }

    long long int l = 0, r = 10000000, m = (l + r) / 2;

    while(l != m && r != m)
    {
        if(check(m)) l = m;
        else r = m;

        m = (l + r) / 2;
    }

    m = 0;
    if(check(l)) m = l;
    if(check(r)) m = r;

    cout << m << endl;

    return 0;
}
