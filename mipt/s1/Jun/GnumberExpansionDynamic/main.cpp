#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const unsigned int M = 101;

int main()
{
    unsigned int A[M + 1][M + 1], i, si, n, N, an, t;

    for(i = 0; i <= M; i++)
        for(si = 0; si <= M; si++) A[i][si] = 0;

    for(i = 0; i <= M; i++) A[0][i] = 1;

    A[1][1] = 1;

    for(N = 1; N <= M; N++)
    {
        A[N][1] = 1;
        for(n = 2; n <= M; n++)
        {
            for(an = 0; an <= N / n; an++)
            {
                t = N - n * an;
                A[N][n] += A[t][n - 1];
            }
        }
    }

    /*for(i = 1; i <= M; i++)
    {
        cout << "i=" << i << ":\t";

        for(si = 1; si <= M; si++)
            cout << A[i][si] << " ";

        cout << endl;
    }*/

    cin >> N;

    //for(i = 1; i <= M; i++) cout << A[i][M] << endl;

    cout << A[N][M] << endl;
}
