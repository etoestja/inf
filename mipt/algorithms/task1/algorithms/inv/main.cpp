#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int N;
int* arr;

int solve_slow()
{
    int i, j, c = 0;
    for(i = 0; i < N; i++)
        for(j = i + 1; j < N; j++)
            if(arr[i] > arr[j]) c++;
    return(c);
}

int solve_fast_ans;

int* solve_fast_r(int* arr, int N)
{
    cerr << "called: N=" << N << "arr=";
    for(int i = 0; i < N; i++) cerr << arr[i] << " ";
    cerr << endl;

    if(N == 0) return NULL;

    int* ans = new int[N];

    if(N == 1)
    {
        ans[0] = arr[0];
        return(ans);
    }

    int Nl = N / 2, Nr = N - Nl;
    int *l = new int[Nl], *r = new int[Nr];

    for(int i = 0; i < N; i++)
    {
        if(i < Nl) l[i] = arr[i];
        else r[i - Nl] = arr[i];
    }

    int* l1 = solve_fast_r(l, Nl);
    int* r1 = solve_fast_r(r, Nr);

    int i, j;

    for(i = 0, j = 0; i + j < N; )
    {
        if(i < Nl && j < Nr)
        {
            if(l1[i] < r1[j])
                ans[i + j] = l1[i++];
            else
            {
                solve_fast_ans += Nl - i;
                ans[i + j] = r1[j++];
            }
        }
        else if(i < Nl)
        {
            ans[i + j] = l1[i++];
        }
        else
        {
            ans[i + j] = r1[j++];
        }
    }

    return(ans);
}

int solve_fast()
{
    solve_fast_ans = 0;
    int *a = solve_fast_r(arr, N);

    cerr << "sorted: ";
    for(int i = 0; i < N; i++) cerr << a[i] << " ";
    cerr << endl;

    return(solve_fast_ans);
}

int main()
{
    cin >> N;
    arr = new int[N];

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    cout << solve_slow() << endl << solve_fast() << endl;
}
