#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;

using std::queue;
using std::pair;
using std::vector;

unsigned int ***started, ***len;
char **arr;
const unsigned int D = 4;

typedef pair<unsigned int, unsigned int> coord;
struct state
{
    coord c; //coord
    unsigned int a; //angle
};

int dx[D] = {0, -1, 0, 1}; //rows
int dy[D] = {1, 0, -1, 0}; //cols

int main()
{
    unsigned int r, c, i, si, ssi;
    cin >> r >> c;
    char t_char;

    coord begin;

    started = new unsigned int**[r];
    len = new unsigned int**[r];
    arr = new char*[r];

    for(i = 0; i < r; i++)
    {

        started[i] = new unsigned int*[c];
        len[i] = new unsigned int*[c];
        arr[i] = new char[c];

        for(si = 0; si < c; si++)
        {
            started[i][si] = new unsigned int[D];
            len[i][si] = new unsigned int[D];

            for(ssi = 0; ssi < D; ssi++)
            {
                started[i][si][ssi] = 0;
                len[i][si][ssi] = 0;
            }
        }
    }

    for(i = 0, si = 0; i < r;)
    {
        scanf("%c", &t_char);
        if(t_char == ' ' || t_char == 'X' || t_char == 'F' || t_char == 'S')
        {
            arr[i][si] = t_char;
            //cerr << arr[i][si];

            if(t_char == 'S')
            {
                begin.first = i;
                begin.second = si;
            }

            if(si == c - 1)
            {
                si = 0;
                i++;
                //cerr << endl;
            }
            else si++;
        }
    }

    queue<state> q;
    state t_state, t_state1;
    t_state.c = begin;
    for(i = 0; i < D; i++)
    {
        t_state.a = i;
        started[begin.first][begin.second][i] = 1;
        q.push(t_state);
    }

    vector<state> t_vect;
    vector<state>::iterator it;

    cerr << " ";
    for(i = 0; i < c; i++) cerr << i % 10;
    cerr << endl;

    for(i = 0; i < r; i++)
    {
        cerr << i;
        for(si = 0; si < c; si++)
            cerr << arr[i][si];

        cerr << endl;
    }

    while(!q.empty())
    {
        t_state = q.front();
        q.pop();

        t_vect.clear();

        t_state1 = t_state;
        t_state1.c.first += dx[t_state1.a];
        t_state1.c.second += dy[t_state1.a];

        t_vect.push_back(t_state1);

        t_state1 = t_state;
        if(t_state1.a == 0) t_state1.a = 3;
        else t_state1.a--;

        t_state1.c.first += dx[t_state1.a];
        t_state1.c.second += dy[t_state1.a];

        t_vect.push_back(t_state1);

        cerr << "i am at (" << t_state.c.first << ", " << t_state.c.second << ") a=" << t_state.a << endl;

        for(it = t_vect.begin(); it != t_vect.end(); it++)
        {
            t_state1 = *it;
            cerr << "    trying new state: (" << t_state1.c.first << ", " << t_state1.c.second << ") a=" << t_state1.a << endl;

            if(arr[t_state1.c.first][t_state1.c.second] == ' ')
            {
                if(!started[t_state1.c.first][t_state1.c.second][t_state1.a])
                {
                    cerr << "     adding." << endl;
                    started[t_state1.c.first][t_state1.c.second][t_state1.a] = 1;
                    len[t_state1.c.first][t_state1.c.second][t_state1.a] = len[t_state.c.first][t_state.c.second][t_state.a] + 1;
                    q.push(t_state1);
                }
            }
            else if(arr[t_state1.c.first][t_state1.c.second] == 'F')
            {
                cerr << "found" << endl;
                len[t_state1.c.first][t_state1.c.second][t_state1.a] = len[t_state.c.first][t_state.c.second][t_state.a] + 1;
                t_state = t_state1;
                while(!q.empty()) q.pop();
                break;
            }
        }
    }

    cerr << "found (" << t_state.c.first << ", " << t_state.c.second << ") a=" << t_state.a << endl;
    cout << len[t_state.c.first][t_state.c.second][t_state.a] << endl;
}
