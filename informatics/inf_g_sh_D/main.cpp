#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::queue;
using std::pair;

const unsigned int M_ = 8;
unsigned int used[M_][M_][M_][M_];
unsigned int len[M_][M_][M_][M_];

typedef pair<int, int> coord;
struct state
{
    coord p1;
    coord p2;
};

const unsigned int MOV = 8;
int dx[MOV] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[MOV] = {1, -1, 1, -1, 2, -2, 2, -2};

bool coord_valid(coord x)
{
    return(x.first >= 0 && x.first < M_
           && x.second >= 0 && x.second < M_);
}

int main()
{
    state begin;
    unsigned int i, si, ssi, sssi, t;
    char c;

    for(i = 0; i < M_; i++)
        for(si = 0; si < M_; si++)
            for(ssi = 0; ssi < M_; ssi++)
                for(sssi = 0; sssi < M_; sssi++)
                {
                    used[i][si][ssi][sssi] = 0;
                    len[i][si][ssi][sssi] = 0;
                }

    cin >> c;
    begin.p1.first = c - 'a';
    cin >> begin.p1.second;
    begin.p1.second--;

    cin >> c;
    begin.p2.first = c - 'a';
    cin >> begin.p2.second;
    begin.p2.second--;

    cerr << "(" << begin.p1.first << ", " << begin.p1.second << ")" << endl;
    cerr << "(" << begin.p2.first << ", " << begin.p2.second << ")" << endl;

    state t_state = begin, t_state1;
    queue<state> q;
    q.push(t_state);
    //get_value(used, begin) = 1;
    used[begin.p1.first][begin.p1.second][begin.p2.first][begin.p2.second] = 1;

    while(!q.empty())
    {
        t_state = q.front();
        q.pop();

        if(t_state.p1 == t_state.p2)
        {
            cout << len[t_state.p1.first][t_state.p1.second][t_state.p2.first][t_state.p2.second] << endl;
            return 0;
        }

        for(i = 0; i < MOV; i++)
            for(si = 0; si < MOV; si++)
            {
                t_state1 = t_state;
                t_state1.p1.first += dx[i];
                t_state1.p1.second += dy[i];
                t_state1.p2.first += dx[si];
                t_state1.p2.second += dy[si];

                if(coord_valid(t_state1.p1) && coord_valid(t_state1.p2) &&
                   !used[t_state1.p1.first][t_state1.p1.second][t_state1.p2.first][t_state1.p2.second])
                {
                    used[t_state1.p1.first][t_state1.p1.second][t_state1.p2.first][t_state1.p2.second] = 1;
                    len[t_state1.p1.first][t_state1.p1.second][t_state1.p2.first][t_state1.p2.second] =
                        len[t_state.p1.first][t_state.p1.second][t_state.p2.first][t_state.p2.second] + 1;
                    q.push(t_state1);
                }
            }
    }

    cout << "-1" << endl;

    return 0;
}
