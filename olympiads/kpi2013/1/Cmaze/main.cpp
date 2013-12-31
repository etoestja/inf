#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

//#define DEBUG
#undef DEBUG

#define NMAX    105
#define BMAX    210
#define KMAX    100000
#define MINKINF 1000000

int N, K;
int maxK[NMAX][NMAX];
int minK[BMAX][BMAX];
int maze[NMAX][NMAX];
string path;

typedef pair<int, int> coord;

inline coord coordToIndex(coord a)
{
    return(make_pair(a.first + BMAX / 2, a.second + BMAX / 2));
}

inline coord indexToCoord(coord b)
{
    return(make_pair(b.first - BMAX / 2, b.second - BMAX / 2));
}

inline void writeMinK(coord a, int m)
{
    coord res = coordToIndex(a);
    minK[res.first][res.second] = m;
}

inline int readMinK(coord a)
{
    coord res = coordToIndex(a);
    return(minK[res.first][res.second]);
}

// arr [i]  [j]
//    rows columns

// L R  0 C -1
// R R  0 C +1
// D R +1 C  0
// U R -1 C  0

// transposed!
coord charToCoord(char c)
{
    if(c == 'R')
        return(make_pair(0, 1));
    else if(c == 'L')
        return(make_pair(0, -1));
    else if(c == 'U')
        return(make_pair(-1, 0));
    else if(c == 'D')
        return(make_pair(1, 0));
    return(make_pair(0, 0));
}

inline void coordAdd(coord &a, coord b)
{
    a.first += b.first;
    a.second += b.second;
}

void coordPrint(coord &a)
{
    cerr << a.first << " " << a.second;
}

void input()
{
    cin >> N >> K;
    char c;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            c = ' ';
            while(c != '1' && c != '0')
                cin >> c;
            maze[i][j] = (c == '0');
        }
    }

    if(K != 0)
        cin >> path;
}

inline bool indexOk(coord a)
{
    return(a.first >= 0 && a.first < BMAX && a.second >= 0 && a.second < BMAX);
}

void fillMinK()
{
    int i, j;
    for(i = 0; i < BMAX; i++)
        for(j = 0; j < BMAX; j++)
        {
            // never been there
            minK[i][j] = MINKINF;
        }


    coord pos(0, 0);

    coord ind(BMAX / 2, BMAX / 2);
    minK[ind.first][ind.second] = 0;

    for(int j = 1; j <= K; j++)
    {
        coordAdd(pos, charToCoord(path[j - 1]));
        coordAdd(ind, charToCoord(path[j - 1]));
        if(!indexOk(ind))
        {
            cout << "-1" << endl;
            exit(0);
        }
#ifdef DEBUG
        cerr << "fmk @ "; coordPrint(pos); cerr << " ";
        cerr << "index: "; coordPrint(ind); cerr << endl;
#endif
        if(minK[ind.first][ind.second] == MINKINF)
            minK[ind.first][ind.second] = j;
    }
}

void dumpMinK()
{
    const int offset = 10;
    cerr << "=== minK ===" << endl;
    for(int i = BMAX / 2 - offset; i < BMAX / 2 + offset; i++)
    {
        for(int j = BMAX / 2 - offset; j < BMAX / 2 + offset; j++)
        {
            if(minK[i][j] == MINKINF)
                cerr << "-";
            else
                cerr << minK[i][j];
            cerr << "\t";
        }
        cerr << endl;
    }
}

void fillMaxK()
{
    int i, j;
    int x, y;
    int t;

    int maxKc, minKc;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
        {
            // (i, j) - start coords
            maxKc = K;
//            for(t1 = -i + BMAX / 2; t1 < N - i + BMAX / 2; t1++)
//                for(t2 = -j + BMAX / 2; t2 < N - j + BMAX / 2; t2++)

            //in maze
            for(x = 0; x < N; x++)
                for(y = 0; y < N; y++)
                {
                    if(maze[x][y] == 0 && maxKc > (minKc = minK[x - i + BMAX / 2][y - j + BMAX / 2] - 1))
                        maxKc = minKc;
                }

            //borders
            for(t = 0; t < N; t++)
            {
                //  t -1
                //  t  N
                // -1  t
                //  N  t

                if(maxKc > (minKc = minK[t - i + BMAX / 2][-1 - j + BMAX / 2] - 1))
                    maxKc = minKc;
                if(maxKc > (minKc = minK[t - i + BMAX / 2][N - j + BMAX / 2] - 1))
                    maxKc = minKc;
                if(maxKc > (minKc = minK[-1 - i + BMAX / 2][t - j + BMAX / 2] - 1))
                    maxKc = minKc;
                if(maxKc > (minKc = minK[N - i + BMAX / 2][t - j + BMAX / 2] - 1))
                    maxKc = minKc;
            }

            maxK[i][j] = maxKc;
        }
}

void dumpMaxK()
{
    cerr << "=== maxK ===" << endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cerr << maxK[i][j] << "\t";
        cerr << endl;
    }
}

int maxKmax;
int minKone;
#define MINKONEINF 1000000

void getMaxKmax()
{
    maxKmax = -1;
    int maxKc;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            maxKc = maxK[i][j];
            if(maxKmax < maxKc) maxKmax = maxKc;
        }
}

int countK(int k)
{
    int res = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            if(maxK[i][j] >= k)
                res++;
        }
    return(res);
}

void getMinKOne()
{
    if(countK(K) != 1)
    {
        minKone = MINKONEINF;
        return;
    }
    int l = 0;
    int r = K;
    int m;
    while(r - l > 1)
    {
        m = (r + l) / 2;
        //2222211111
        //l   m    r
        if(countK(m) > 1)
            l = m;
        else r = m;
    }
    if(countK(l) == 1)
    {
        minKone = l;
        return;
    }
    minKone = r;
}

void printAns()
{
    if(maxKmax < K)
        cout << "-1" << endl;
    else
    {
        if(minKone == MINKONEINF)
            cout << "-1" << endl;
        else
            cout << minKone << endl;
    }
}

int main()
{
    input();
    fillMinK();
    fillMaxK();
#ifdef DEBUG
    dumpMinK();
    dumpMaxK();
#endif
    getMaxKmax();
    getMinKOne();
    printAns();
    return(0);
}
