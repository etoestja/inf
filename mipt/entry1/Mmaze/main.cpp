#include <iostream>
#include <vector>
#include <stack>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::pair;
using std::stack;

typedef pair<unsigned int, unsigned int> coord;
vector<coord> objects, destinations;
coord me;

const unsigned int M_ = 10;
unsigned int M, N;

const char EMPTY = '.';
const char WALL  = '*';
const char OBJ   = '#';
const char DEST  = 'x';
const char ME    = '@';
const char OBJ_D = '$';
const char ME_D  = '%';

char field[M_ + 2][M_ + 2];

unsigned int find_path(coord dest, coord start = me)
{
    unsigned int r;
    stack<coord> st;
    coord top;

    st.push(me);
    while(!st.empty())
    {
        top = st.top();
        if(top == dest) return;
    }
}

int main()
{
    unsigned int i, si;
    char t;

    coord t_coord;

    cin >> N >> M;

    for(i = 0; i <= M_ + 1; i++)
        for(si = 0; si <= M_ + 1) field[i][si] = WALL;

    for(i = 1; i <= M; i++)
        for(si = 1; si <= N; si++)
        {
            cin >> field[i][si];

            t_coord.first = i;
            t_coord.second = si;

            if(field[i][si] == ME) me = t_coord;
            else if(field[i][si] == OBJ) objects.push_back(t_coord);
            else if(field[i][si] == DEST) destinations.push_back(t_coord);
            else if(field[i][si] == OBJ_D)
            {
                objects.push_back(t_coord);
                destinations.push_back(t_coord);
            }
            else if(field[i][si] == ME_D)
            {
                destinations.push_back(t_coord);
                me = t_coord;
            }
        }




    return 0;
}
