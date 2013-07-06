#include <iostream>

using namespace std;

#define NMAX 1000
long long arr[NMAX][NMAX];
int N;

void calc_dyn()
{
    arr[0][0] = 1;


    int i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
        {
            if(i == 0 && j == 0) continue;
            arr[i][j] = 0;
            if(i > 0) arr[i][j] += arr[i - 1][j];
            if(j > 0) arr[i][j] += arr[i][j - 1];
        }
}

void print_all()
{
    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            cerr << arr[i][j] << '\t';
        cerr << endl;
    }
}

void print_ans()
{
    cout << arr[N - 1][N - 1] << endl;
}

int main()
{
    cin >> N;

    calc_dyn();

    print_all();

    print_ans();

    return(0);
}
