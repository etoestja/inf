#include <iostream>
#include <cstdio>

using namespace std;

unsigned U, V, UMax = 0, VMax = 0, N, x, y;

char getSym()
{
    char c = '\n';
    while(c != '#' && c != '.')
        cin >> c;
    return(c);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> U >> V;

    char c;

    for(unsigned i = 1; i <= U; i++)
    {
        for(unsigned j = 1; j <= V; j++)
        {
            c = getSym();

            if(c == '#')
            {
                if(i > UMax)
                    UMax = i;
                if(j > VMax)
                    VMax = j;
            }
        }
    }

    cin >> N;
    bool printed = false;

    for(unsigned i = 1; i <= N; i++)
    {
        cin >> x >> y;
        if(x >= UMax && y >= VMax && !printed)
        {
            printed = true;
            cout << i << endl;
        }
    }

    return(0);
}
