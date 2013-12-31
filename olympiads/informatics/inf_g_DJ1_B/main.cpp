#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

const int M_ = 100, INF = M_ * M_ * M_;
int arr[M_][M_];
bool used[M_];
int p[M_];
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
        p[i] = N;
        len[i] = INF;
        for(si = 0; si < N; si++)  cin >> arr[i][si];
    }

    len[begin] = 0;
    p[begin] = -1;

    for(i = 0; i < N; i++)
    {
        j = N;
        for(si = 0; si < N; si++)
            if(!used[si] && (j == N || len[si] < len[j])) j = si;

        if(len[j] == INF) break;

        used[j] = 1;

        for(si = 0; si < N; si++)
            if(si != j && arr[j][si] >= 0 && len[si] > arr[j][si] + len[j])
            {
                len[si] = arr[j][si] + len[j];
                p[si] = j;
            }
    }

    //cout << (len[end] == INF ? -1 : (int) len[end]) << endl;
    if(p[end] == N) cout << "-1" << endl;
    else
    {
        vector<int> t_vect;
        for(j = end; j != -1; j = p[j]) t_vect.push_back(j + 1);

        vector<int>::reverse_iterator rit;
        for(rit = t_vect.rbegin(); rit != t_vect.rend(); rit++) cout << (*rit) << " ";
        cout << endl;
    }

    return 0;
}
