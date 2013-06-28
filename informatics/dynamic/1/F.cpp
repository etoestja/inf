#include <iostream>

using namespace std;

#define NMAX 1000005

int arr[NMAX];
int N;

void input()
{
    cin >> N;
}

#define update(t, x) {if(t > x) t = x;}

void fill()
{
    arr[0] = 0;
    arr[1] = 0;
    int t;
    for(int i = 2; i <= N; i++)
    {
        t = arr[i - 1];
        if(i % 2 == 0)
            update(t, arr[i / 2]);
        if(i % 3 == 0)
            update(t, arr[i / 3]);
        arr[i] = t + 1;
    }
}

int main()
{
    input();
    fill();

    cout << arr[N] << endl;

    return(0);
}
