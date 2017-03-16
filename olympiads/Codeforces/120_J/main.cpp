#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define MAXN 500005

#define sq(x) ((x) * (x))

int N;
int XYI[MAXN][3];

int ans_idx0 = -1;
int ans_idx1 = -1;

int distance(int idx0, int idx1)
{
    return(sq(XYI[idx0][0] - XYI[idx1][0]) + sq(XYI[idx0][1] - XYI[idx1][1]));
}

void input()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        XYI[i][0] = a;
        XYI[i][1] = b;
    }
}

void generate(int NMAX)
{
    N = rand() % NMAX;
    for(int i = 0; i < N; i++)
    {
        XYI[i][0] = rand() % 20;
        XYI[i][1] = rand() % 20;
        XYI[i][2] = i;
    }
}

int slowSolution()
{
    int best_ans = 800000000;
    for(int i = 0; i < N; i++)
    {
        for(int j = i + 1; j < N; j++)
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

void printDistances()
{
    printf("\t");
    for(int i = 0; i < N; i++)
    {
        printf("%d\t", i);
    }
    printf("\n");
    for(int i = 0; i < N; i++)
    {
        printf("%d\t", i);
        for(int j = 0; j < N; j++)
        {
            bool is_best = distance(ans_idx0, ans_idx1) == distance(i, j);
            if(is_best)
                printf("[");
            printf("%d", distance(i, j));
            if(is_best)
                printf("]");
            printf("\t");
        }
        printf("\n");
    }
}

static int comp(const void* p1, const void* p2)
{
    int* arr1 = ((int*) (p1));
    int* arr2 = ((int*) (p2));
    //printf("%d %d %d %d %d %d\n", arr1[0], arr2[0], arr1[1], arr2[1], arr1[2], arr2[2]);
    return(((arr1[0] < arr2[0]) || ((arr1[0] == arr2[0]) && (arr1[1] < arr2[1]))) == 0 ? -1 : 1);
}

void sortX()
{
    qsort(XYI, N, 3 * sizeof(int), comp);
}

void updateBest(int i, int j)
{
    bool do_update = false;
    if(ans_idx0 == -1 || ans_idx1 == -1)
    {
        do_update = true;
    }
    else
    {
        int dist_best = distance(ans_idx0, ans_idx1);
        int dist = distance(i, j);
        do_update = dist < dist_best;
    }
    if(do_update)
    {
        ans_idx0 = i;
        ans_idx1 = j;
    }
}

int fastSolution(int i1, int i2)
{
    int pts = i2 - i1;
    if(pts <= 1)
        return(0);
    else if(pts == 2)
    {
        update_best(i1, i2 - 1);
        return(distance(i1, i2 - 1));
    }
    else
    {
        int m = (i1 + i2) / 2;
        int h1 = fastSolution(i1, m);
        int h2 = fastSolution(m, i2);
        int h = h1;
        if(h2 < r)
            h = h2;

        int l = m;
        for(int i = m; i >= i1; i--)
        {
            if(sq(XYI[i][0] - XYI[m][0]) < h)
            {
                l = i;
            }
            else
                break;
        }

        int r = m;
        for(int i = m; i < i2; i++)
        {
            if(sq(XYI[i][0] - XYI[m][0]) < h)
            {
                r = i;
            }
            else
                break;
        }


    }
}

int printSolution(int i, int j)
{
    printf("%d %d %d\n", XYI[i][2], XYI[j][2], distance(i, j));
}

void printPoints()
{
    printf("<POINTS>\n");
    for(int i = 0; i < N; i++)
    {
        printf("%d %d %d\n", XYI[i][0], XYI[i][1], XYI[i][2]);
    }
    printf("</POINTS>\n");
}

int main()
{
//    input();
    generate(31);

    printPoints();
    sortX();
    printPoints();
    slowSolution();
    printDistances();
    printSolution(ans_idx0, ans_idx1);

    return(0);
}
