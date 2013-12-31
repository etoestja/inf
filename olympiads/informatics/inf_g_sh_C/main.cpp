#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::endl;

using std::queue;
using std::pair;

const unsigned int M_ = 100;
unsigned int N, M;
unsigned int arr[M_][M_], arr1[M_][M_];

typedef pair<int, int> coord;

int main()
{
    unsigned int i, si, ssi;
    cin >> N >> M;

    queue<coord> q;
    coord t_coord, t_coord1;
    for(i = 0; i < N; i++)
        for(si = 0; si < M; si++) arr1[i][si] = 0;

    for(i = 0; i < N; i++)
        for(si = 0; si < M; si++)
        {
            cin >> arr[i][si];
            if(arr[i][si])
            {
                t_coord.first = i;
                t_coord.second = si;
                q.push(t_coord);
                //cout << "1 at (" << t_coord.first << ", " << t_coord.second << ")" << endl;
            }
        }

    const unsigned int c = 4;
    int dy[c] = {1, -1, 0, 0};
    int dx[c] = {0, 0, -1, 1};

    while(!q.empty())
    {
        t_coord = q.front();
        q.pop();

        //cout << "extracted (" << t_coord.first << ", " << t_coord.second << ")" << endl;

        for(i = 0; i < c; i++)
        {
            //t_coord1 = t_coord;
            t_coord1.first = t_coord.first + dx[i];
            t_coord1.second = t_coord.second + dy[i];

            //cout << "trying (" << t_coord1.first << ", " << t_coord1.second << ")... ";

            if(t_coord1.first >= 0 && t_coord1.first < N && t_coord1.second >= 0 && t_coord1.second < M)
            {
                //cout << "coords ok ";
                if((arr[t_coord1.first][t_coord1.second] == 0) && (arr1[t_coord1.first][t_coord1.second] == 0))
                {
                    //cout << "adding";
                    arr1[t_coord1.first][t_coord1.second] = arr1[t_coord.first][t_coord.second] + 1;
                    q.push(t_coord1);
                }
            }
            //cout << endl;
        }

        /*for(ssi = 0; ssi < N; ssi++)
        {
            for(si = 0; si < M; si++)
                cout << arr1[ssi][si] << " ";
            cout << endl;
        }
        cout << endl;*/
    }

    for(i = 0; i < N; i++)
    {
        for(si = 0; si < M; si++)
            cout << arr1[i][si] << " ";
        cout << endl;
    }

    return 0;
}
