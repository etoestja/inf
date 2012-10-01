#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int M_ = 100, INF = M_ * M_ * M_;
int arr[M_][M_], pr[M_], len[M_], used[M_];

int main()
{
    int N, i, si, j, t1, t2;
    cin >> N;

    for(i = 0; i < N; i++)
    {
        cin >> pr[i];

        used[i] = 0;
        len[i] = INF;

        for(si = 0; si < N; si++) arr[i][si] = -1;
    }

    len[0] = 0;

    cin >> j;
    for(i = 0; i < j; i++)
    {
       cin >> t1 >> t2;
       t1--;
       t2--;

       arr[t1][t2] = pr[t1];
       arr[t2][t1] = pr[t2];
    }

    for(i = 0; i < N; i++)
    {
        j = N;
        for(si = 0; si < N; si++)
            if(!used[si] && (j == N || len[si] < len[j])) j = si;

        if(len[j] == INF) break;
        used[j] = 1;

        for(si = 0; si < N; si++)
            if(si != j && arr[j][si] >= 0 && len[si] > len[j] + arr[j][si])
                len[si] = len[j] + arr[j][si];
    }

    cout << (len[N - 1] == INF ? -1 : len[N - 1]) << endl;

    return 0;
}
