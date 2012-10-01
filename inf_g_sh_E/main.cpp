#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;

using std::queue;
using std::pair;
using std::string;
using std::stringstream;

const unsigned int M_ = 100 + 2;
unsigned int arr[M_][M_], len[M_][M_], start[M_][M_], been[M_][M_];

typedef pair<unsigned int, unsigned int> coord;

string print_coord(coord x)
{
    stringstream ss;
    ss << "(" << x.first << ", " << x.second << ")";
    return(ss.str());
}

int main()
{
    unsigned int i, si, N, M;

    for(i = 0; i < M_; i++)
        for(si = 0; si < M_; si++)
        {
            arr[i][si] = 1;
            len[i][si] = 0;
            start[i][si] = 0;
            been[i][si] = 0;
        }

    cin >> N >> M;

    for(i = 1; i <= N; i++)
        for(si = 1; si <= M; si++)
        {
            cin >> arr[i][si];
        }

    coord t_coord, t_coord1;
    t_coord.first = 1;
    t_coord.second = 1;

    const unsigned int c = 4;
    int dx[c] = {0, 0, 1, -1};
    int dy[c] = {1, -1, 0, 0};

    start[1][1] = 1;
    been[1][1] = 1;

    queue<coord> q;
    q.push(t_coord);

    while(!q.empty())
    {
        t_coord = q.front();
        q.pop();

        cerr << "i am at " << print_coord(t_coord) << endl;

        for(i = 0; i < c; i++)
        {
            cerr << "trying (" << dx[i] << ", " << dy[i] << ")" << endl;

            for(t_coord1 = t_coord; arr[t_coord1.first + dx[i]][t_coord1.second + dy[i]] == 0 /*&&
                !been[t_coord1.first + dx[i]][t_coord1.second + dy[i]]*/;
                t_coord1.first += dx[i], t_coord1.second += dy[i])
            {
                been[t_coord1.first + dx[i]][t_coord1.second + dy[i]] = 1;
            }

            if(arr[t_coord1.first + dx[i]][t_coord1.second + dy[i]] == 2)
            {
                t_coord1.first += dx[i];
                t_coord1.second += dy[i];
                len[t_coord1.first][t_coord1.second] = len[t_coord.first][t_coord.second] + 1;
                while(!q.empty()) q.pop();
                break;
            }
            else if(arr[t_coord1.first + dx[i]][t_coord1.second + dy[i]] == 1 && !start[t_coord1.first][t_coord1.second])
            {
                start[t_coord1.first][t_coord1.second] = 1;
                len[t_coord1.first][t_coord1.second] = len[t_coord.first][t_coord.second] + 1;
                cerr << "adding" << print_coord(t_coord1) << endl;
                q.push(t_coord1);
            }
        }
    }

    cerr << "found" << print_coord(t_coord1) << endl;
    cout << len[t_coord1.first][t_coord1.second] << endl;

    return 0;
}
