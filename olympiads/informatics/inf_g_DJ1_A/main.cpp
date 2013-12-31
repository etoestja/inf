#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int M_ = 100, INF = M_ * M_ * M_;
int arr[M_][M_];
bool used[M_];
int len[M_];

int main()
{
    int N, j, i, si, begin, end;
    cin >> N >> begin >> end;
    begin--;
    end--;

    for(i = 0; i < N; i++)
    {
        used[i] = 0;
        len[i] = INF;
        for(si = 0; si < N; si++)  cin >> arr[i][si];
    }

    len[begin] = 0;

    for(i = 0; i < N; i++)
    {
        j = N;
        for(si = 0; si < N; si++)
            if(!used[si] && (j == N || len[si] < len[j])) j = si;

        if(len[j] == INF) break;

        used[j] = 1;

        for(si = 0; si < N; si++)
            if(si != j && arr[j][si] >= 0 && len[si] > arr[j][si] + len[j]) len[si] = arr[j][si] + len[j];
    }

    cout << (len[end] == INF ? -1 : (int) len[end]) << endl;

    return 0;
}
