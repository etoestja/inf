#include <stdio.h>
#include <stdlib.h>

struct Point
{
    int x;
    int y;
};

int cmp_Point(const void *p1, const void* p2)
{
    struct Point a, b;
    a = *((struct Point*) p1);
    b = *((struct Point*) p2);

    int r1 = a.x * a.x + a.y * a.y;
    int r2 = b.x * b.x + b.y * b.y;

    if(r1 == r2)
    {
        if(a.x == b.x)
        {
            if(a.y == b.y)
                return 0;
            else return(a.y > b.y ? 1 : -1);
        }
        else return(a.x > b.x ? 1 : -1);
    }
    return(r1 > r2 ? 1 : -1);
}

#define NMAX 1001
struct Point arr[NMAX];

int main()
{
    int i, N;
    scanf("%d", &N);


    for(i = 0; i < N; i++)
    {
        scanf("%d", &(arr[i].x));
        scanf("%d", &(arr[i].y));
    }

    qsort(arr, N, sizeof(struct Point), cmp_Point);

    for(i = 0; i < N; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);

    return 0;
}
