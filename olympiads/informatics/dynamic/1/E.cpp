#include <iostream>

using namespace std;

#define NMAX 105
#define min(a, b) (a < b ? a : b)

int arr[NMAX];
int N;

int main()
{
    cin >> N;

    arr[0] = 0;
    arr[1] = 0;

    for(int i = 2; i <= N + 1; i++)
    {
        cin >> arr[i];
        arr[i] += min(arr[i - 1], arr[i - 2]);
    }

    cout << arr[N + 1] << endl;

    return(0);
}
