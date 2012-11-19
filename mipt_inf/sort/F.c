#include <stdio.h>
#include <stdlib.h>

#define NMAX 10000
#define LMAX 31

int N;

struct st
{
    char name[LMAX];
    int x;
} arr[NMAX];

int cmp_str(const void *p1, const void *p2)
{
    char* s1 = (char*) p1;
    char* s2 = (char*) p2;

    int i;
    for(i = 0; i < LMAX; i++)
    {
        if(s1[i] == 0 && s2[i] == 0)
            return 0;
        else if(s1[i] == 0)
            return -1;
        else if(s2[i] == 0)
            return 1;
        else
        {
            if(s1[i] != s2[i])
                return(s1[i] > s2[i] ? 1 : -1);
        }

    }

    return 0;
}

int cmp_name(const void *p1, const void *p2)
{
    struct st s1 = *((struct st*) p1);
    struct st s2 = *((struct st*) p2);

    return(cmp_str(s1.name, s2.name));
}

int cmp_x(const void *p1, const void *p2)
{
    struct st s1 = *((struct st*) p1);
    struct st s2 = *((struct st*) p2);

    if(s1.x != s2.x)
        return(s1.x > s2.x ? -1 : 1);
    else return(cmp_str(s1.name, s2.name));
}

void print()
{
    int i;
    for(i = 0; i < N; i++)
        printf("%s %d\n", arr[i].name, arr[i].x);
}

int main()
{
    int i;

    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        scanf("%s", arr[i].name);
        scanf("%d", &(arr[i].x));
    }

    qsort(arr, N, sizeof(struct st), cmp_name);

    print();
    printf("\n");

    qsort(arr, N, sizeof(struct st), cmp_x);

    print();

    return 0;
}
