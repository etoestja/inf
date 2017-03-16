#include <stdio.h>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define MAXN 500005
#define NK 4

#define sq(x) (x * x)

int N;
int XYK[MAXN][3];

int X_sign[NK] = {+1, -1, +1, -1};
int Y_sign[NK] = {+1, +1, -1, -1};

int k_ans[NK] = {4, 3, 2, 1};

void fill_one(int a, int b)
{
    static int i = 0;
    for(int k = 0; k < NK; k++)
    {
        XYK[i + k][0] = X_sign[k] * a;
        XYK[i + k][1] = Y_sign[k] * b;
        XYK[i + k][2] = k;
    }
    i += NK;
}

int ans_idx0 = -1;
int ans_idx1 = -1;

int distance(int idx0, int idx1)
{
    return(sq(XYK[idx0][0] - XYK[idx1][0]) + sq(XYK[idx0][1] - XYK[idx1][1]));
}

int SlowSolution()
{
    int best_ans = 800000000;
    for(int i = 0; i < NK * N; i++)
    {
        for(int j = 0; j < NK * N; j++)
        {
            int dist = distance(i, j);
            if(dist < best_ans)
            {
                best_ans = dist;
                ans_idx0 = i;
                ans_idx1 = j;
            }
        }
    }
    return(best_ans);
}

int print_solution(int i, int j)
{
    printf("%d %d %d %d\n", i, XYK[i][2] + 1, j, k_ans[XYK[j][2]]);
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        fill_one(a, b);
    }

    SlowSolution();
    print_solution(ans_idx0, ans_idx1);

    return(0);
}
