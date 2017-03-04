#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

#define MAXN 150
int N;
int arr[MAXN];
int idx[MAXN];

static int comp_arr(const void* p1, const void* p2)
{
    int i1 = *(int*) p1;
    int i2 = *(int*) p2;
    if(i1 == 0)
    {
        return(-1);
    }
    else if(i2 == 0)
    {
        return(1);
    }
    else
    {
        return(arr[i1] < arr[i2] ? 1 : -1);
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        idx[i] = i;
    }

    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += arr[i];

    //cout << sum << " " << N << endl;

    if(sum < N - 1 || arr[0] == 0)
    {
        cout << "-1" << endl;
        return(0);
    }

    qsort(idx, N, sizeof(int), comp_arr);

    /*for(int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
    for(int i = 0; i < N; i++)
        cout << i + 1 << " ";
    cout << endl;
    for(int i = 0; i < N; i++)
        cout << idx[i] + 1 << " ";
    cout << endl;*/

    int target = 1;
    cout << N - 1 << endl;
    for(int i = 0; i < N; i++)
    {
        int current = idx[i];
        while(target < N && arr[current] > 0)
        {
            arr[current]--;
            cout << (current + 1) << " " << (idx[target] + 1) << endl;
            target++;
        }
    }

    return(0);
}
