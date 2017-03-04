#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

#define MAXN 150
int N;
int arr[MAXN];
int is_ok[MAXN];

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        is_ok[i] = 0;
    }

    is_ok[0] = 1;

    int k;
    cin >> k;

    if(k == -1)
    {
        cout << "-1" << endl;
        return(0);
    }

    for(int i = 0; i < k; i++)
    {
        int fr, to;
        cin >> fr >> to;
        fr--;
        to--;
        if(arr[fr] > 0 && is_ok[fr])
        {
            arr[fr]--;
            is_ok[to] = 1;
        }
    }

    int OK = 1;
    for(int i = 0; i < N; i++)
    {
        if(!is_ok[i])
        {
            OK = 0;
            cout << (i + 1) << " not ok!" << endl;
        }
    }

    cout << OK << endl;

    return(0);
}
