#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <queue>

using std::cin;
using std::cout;
using std::endl;

using std::cerr;

using std::vector;
using std::pair;
using std::map;

using std::queue;

using std::stringstream;
using std::string;

// no plan, no backup...

void read();
void solve();
void write();

typedef unsigned long long int num_t;
typedef pair<num_t, num_t> coord_t;

const unsigned int dK = 4;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

const unsigned int dK_bad = 8;
int dx_bad[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy_bad[] = {1, 0, -1, 0, 1, -1, 1, -1};

coord_t size, A, B, first_bad;
num_t K;
map<coord_t, bool> bad;

bool result = false;

void read_coord_t(coord_t &arg)
{
    cin >> arg.first >> arg.second;
}

string write_coord_t(const coord_t arg)
{
    stringstream t_ss;
    t_ss << arg.first << " " << arg.second;
    return(t_ss.str());
}

bool valid_coord_t(const coord_t arg)
{
    return(arg.first > 0 && arg.second > 0 && arg.first <= size.first && arg.second <= size.second && (bad.find(arg) == bad.end()));
}

void read()
{
    bad.clear();

    read_coord_t(size);
    read_coord_t(A);
    read_coord_t(B);

    cin >> K;

    coord_t t_coord;
    for(num_t i = 0; i < K; i++)
    {
        if(i == 0) first_bad = t_coord;

        read_coord_t(t_coord);
        bad[t_coord] = 1;
    }
}

void solve_slow()
{
    queue<coord_t> q;

    coord_t t1, t2;

    q.push(A);

    while(!q.empty())
    {
        t1 = q.front();
        q.pop();

        if(t1 == B)
        {
            result = true;
            break;
        }

        for(unsigned int i = 0; i < dK; i++)
        {
            t2 = t1;
            t2.first += dx[i];
            t2.second += dy[i];

            if(valid_coord_t(t2))
            {
                q.push(t2);
                bad[t2] = true;

                if(t2 == B)
                {
                    result = true;
                    break;
                }
            }
        }
    }
}

void solve_fast_minmax(coord_t& min_r, coord_t& max_r, coord_t& arg)
{
    if(arg.first < min_r.first) min_r.first = arg.first;
    if(arg.second < min_r.second) min_r.second = arg.second;

    if(arg.first > max_r.first) max_r.first = arg.first;
    if(arg.second > max_r.second) max_r.second = arg.second;
}

bool solve_fast_inrange(coord_t min_r, coord_t max_r, coord_t arg)
{
    return(arg.first >= min_r.first && arg.first <= max_r.first && arg.second >= min_r.second && arg.second <= max_r.second);
}

void solve_fast()
{
    result = true;

    if(A == B) return;

    queue<coord_t> q;

    map<coord_t, bool> bad_used;

    coord_t c1, c2;

    coord_t min_r, max_r;

    map<coord_t, bool>::iterator it;
    for(it = bad.begin(); it != bad.end(); it++)
    {
        if(bad_used.find((*it).first) == bad_used.end())
        {
            cerr << "at bad: " << write_coord_t((*it).first) << endl;
            bad_used.clear();
            while(!q.empty()) q.pop();

            q.push((*it).first);
            bad_used[(*it).first] = true;

            min_r = (*it).first;
            max_r = (*it).first;

            while(!q.empty())
            {
                c1 = q.front();
                q.pop();

                for(unsigned int i = 0; i < dK_bad; i++)
                {
                    c2 = c1;
                    c2.first += dx_bad[i];
                    c2.second += dy_bad[i];

                    if(bad.find(c2) != bad.end() && bad_used.find(c2) == bad_used.end())
                    {
                        cerr << "adding bad: " << write_coord_t(c2) << endl;

                        solve_fast_minmax(min_r, max_r, c2);

                        bad_used[c2] = true;
                        q.push(c2);
                    }
                }
            }

            if(solve_fast_inrange(min_r, max_r, A))
            {
                bool inrange = true;
                queue<coord_t> q1;
                while(!q1.empty()) q1.pop();
                map<coord_t, bool> A_used;

                A_used[A] = true;
                q1.push(A);

                coord_t tt1, tt2;

                while(!q1.empty())
                {
                    tt1 = q1.front();
                    q1.pop();

                    for(unsigned int si = 0; si < dK; si++)
                    {
                        tt2 = tt1;
                        tt2.first += dx[si];
                        tt2.second += dy[si];

                        if(valid_coord_t(tt2))
                        {
                            A_used[tt2] = true;
                            q1.push(tt2);

                            if(!solve_fast_inrange(min_r, max_r, tt2))
                            {
                                //exited
                                inrange = false;
                                while(!q1.empty()) q1.pop();
                                break;
                            }

                            if(tt2 == B)
                            {
                                inrange = false;
                                while(!q1.empty()) q1.pop();
                                break;
                            }
                        }
                    }
                }

                if(inrange) result = false;
            }
            if(solve_fast_inrange(min_r, max_r, B))
            {
                bool inrange = true;
                queue<coord_t> q1;
                while(!q1.empty()) q1.pop();
                map<coord_t, bool> B_used;

                B_used[B] = true;
                q1.push(B);

                coord_t tt1, tt2;

                while(!q1.empty())
                {
                    tt1 = q1.front();
                    q1.pop();

                    for(unsigned int si = 0; si < dK; si++)
                    {
                        tt2 = tt1;
                        tt2.first += dx[si];
                        tt2.second += dy[si];

                        if(valid_coord_t(tt2))
                        {
                            B_used[tt2] = true;
                            q1.push(tt2);

                            if(!solve_fast_inrange(min_r, max_r, tt2))
                            {
                                //exited
                                inrange = false;
                                while(!q1.empty()) q1.pop();
                                break;
                            }

                            if(tt2 == A)
                            {
                                inrange = false;
                                while(!q1.empty()) q1.pop();
                                break;
                            }
                        }
                    }
                }

                if(inrange) result = false;
            }

            if(min_r.first == 1 && max_r.first == size.first)
            {
                if(A.second < min_r.second && B.second > max_r.second) result = false;
                if(A.second > min_r.second && B.second < max_r.second) result = false;
            }

            if(min_r.second == 1 && max_r.second == size.second)
            {
                if(A.first < min_r.first && B.first > max_r.first) result = false;
                if(A.first > min_r.first && B.first < max_r.first) result = false;
            }

            if(!result) break;
        }
    }
}

void write()
{
    cerr << "size: " << write_coord_t(size) << endl;
    cerr << "A: " << write_coord_t(A) << endl;
    cerr << "B: " << write_coord_t(B) << endl;
    cerr << "K: " << K << endl;

    /*map<coord_t, bool>::iterator it;
    num_t i = 0;*/

    coord_t t_coord;
    t_coord.first = 3;
    t_coord.second = 1;
    cerr << " valid " << write_coord_t(t_coord) << ": " << valid_coord_t(t_coord) << endl;

    /*for(it = bad.begin(); it != bad.end(); it++)
    {
        cerr << " bad #" << i++ << ": " << (*it) << endl;
    }*/

    cout << (result ? "Yes" : "No") << endl;
}

int main()
{
    read();
    //solve_slow();
    solve_fast();
    write();

    return 0;
}
