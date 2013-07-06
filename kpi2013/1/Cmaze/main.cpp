#include <iostream>
#include <string>

using namespace std;

#define NMAX 105
#define BMAX 210
#define KMAX 100000

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

void fillMinK()
{
    int i, j;
    for(i = 0; i < BMAX; i++)
        for(j = 0; j < BMAX; j++)
        {
            // never been there
            minK[i][j] = -1;
        }


    coord pos(0, 0);
    for(int j = 0; j < K; j++)
    {
        coordAdd(pos, charToCoord(path[j]));
        cerr << "fmk @ ";
        coordPrint(pos);
        cerr << endl;
    }
}

int main()
{
    return(0);
}
