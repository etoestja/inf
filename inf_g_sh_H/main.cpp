#include <iostream>
#include <queue>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::queue;
using std::pair;
using std::vector;
using std::string;

typedef pair<unsigned int, unsigned int> coord;

const unsigned int M_ = 1000 + 2, D = 4;
char arr[M_][M_];
coord prev[M_][M_];
unsigned int len[M_][M_];

int dx[D] = {0, 0, 1, -1};
int dy[D] = {1, -1, 0, 0};
string n[D] = {"E", "W", "S", "N"};


struct state
{
    coord c;
    //string path;
    unsigned int l;
};

int main()
{
    unsigned int i, si, N, M;
    coord begin, end;

    cin >> N >> M;
    cin >> begin.first >> begin.second;
    cin >> end.first >> end.second;

    for(i = 0; i < M_; i++)
        for(si = 0; si < M_; si++)
        {
            arr[i][si] = '#';
            len[i][si] = 0;
            prev[i][si].first = 0;
            prev[i][si].second = 0;
        }

    for(i = 1; i <= N; i++)
    {
        for(si = 1; si <= M; si++)
        {
            cin >> arr[i][si];
            if(arr[i][si] == '.') arr[i][si] = 1;
            else if(arr[i][si] == 'W') arr[i][si] = 2;
        }
    }

    //cerr << "input ok N=" << N << " M=" << M << " begin=(" << begin.first
        //<< ", " << begin.second << ") end=(" << end.first << ", " << end.second << ")" << endl;

    if(end == begin)
    {
        cout << "0" << endl;
        return 0;
    }

    queue<state> q;
    state t_state, t_state1;

    t_state.c = begin;
    t_state.l = 0;

    q.push(t_state);

    string path_min;
    int len_min = -1;

    while(!q.empty())
    {
        t_state = q.front();
        q.pop();

        //cerr << "i am at (" << t_state.c.first << ", " << t_state.c.second << ") path=" << t_state.path << endl;

        if(t_state.l > len[t_state.c.first][t_state.c.second]) continue;

        for(i = 0; i < D; i++)
        {
            t_state1 = t_state;
            t_state1.c.first += dx[i];
            t_state1.c.second += dy[i];
            t_state1.l = len[t_state.c.first][t_state.c.second] + arr[t_state1.c.first][t_state1.c.second];
            //t_state1.path.append(n[i]);

            if(t_state1.c == end)
            {
                if(len_min == -1 || (len_min > t_state1.l))
                {
                    prev[t_state1.c.first][t_state1.c.second] = t_state.c;
                    len[t_state1.c.first][t_state1.c.second] = t_state1.l;
                    len_min = len[t_state1.c.first][t_state1.c.second];
                    //path_min = t_state1.path;
                }
                break;
            }
            else if(arr[t_state1.c.first][t_state1.c.second] != '#')
            {
                if(len[t_state1.c.first][t_state1.c.second] == 0 || (len[t_state1.c.first][t_state1.c.second] > t_state1.l))
                {
                    prev[t_state1.c.first][t_state1.c.second] = t_state.c;
                    len[t_state1.c.first][t_state1.c.second] = t_state1.l;
                    q.push(t_state1);
                }
            }
        }
    }

    cout << len_min << endl;
    if(len_min != -1)
    {
        vector<string> t_vector;
        coord t_coord;

        int dx1, dy1;

        for(t_coord = end; t_coord != begin; t_coord = prev[t_coord.first][t_coord.second])
        {
            dx1 = t_coord.first - prev[t_coord.first][t_coord.second].first;
            dy1 = t_coord.second - prev[t_coord.first][t_coord.second].second;
            for(i = 0; i < D; i++)
            {
                if(dx1 == dx[i] && dy1 == dy[i]) t_vector.push_back(n[i]);
            }
        }

        vector<string>::reverse_iterator rit;
        for(rit = t_vector.rbegin(); rit != t_vector.rend(); rit++)
        {
            cout << (*rit);
        }
        cout << endl;
    }

    return 0;
}
