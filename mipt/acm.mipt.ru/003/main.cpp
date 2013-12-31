#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::cerr;

using std::queue;

#define NMAX (200 + 2)

int arr[NMAX][NMAX];

int main()
{
    int N, i, si;
    char c;

    for(i = 0; i < NMAX; i++)
        for(si = 0; si < NMAX; si++)
            arr[i][si] = 0;

    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        for(si = 0; si < i; si++)
        {
            scanf("%c", &c);
            if(c == '+') arr[i + 1][si + 1] = 1;
            else if(c == '-') arr[si + 1][i + 1] = 1;
        }
    }

    bool found = 0;

    queue<

    return 0;
}
