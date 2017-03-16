#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

#define NMAX 150005
#define KMAX 6

int arr[NMAX];
int T[NMAX];

int inArr = 0;

int N, K, Q;

       static int
       comp(const void *p1, const void *p2)
       {
           /* The actual arguments to this function are "pointers to
              pointers to char", but strcmp(3) arguments are "pointers
              to char", hence the following cast plus dereference */

           return(T[*((int*) p1)] > T[*((int*) p2)] ? -1 : 1);
       }

void printInArr()
{
    printf("<");
    for(int i = 0; i < inArr; i++)
       printf("[%d %d] ", arr[i], T[arr[i]]);
    printf(">\n");
}

int main()
{
    scanf("%d", &N);
    scanf("%d", &K);
    scanf("%d", &Q);

    for(int i = 0; i < NMAX; i++)
        arr[i] = 0;

    for(int i = 0; i < N; i++)
        scanf("%d", &(T[i]));

    for(int i = 0; i < Q; i++)
    {
        int type, idx;
        scanf("%d %d", &type, &idx);
        idx--;
        if(type == 2)
        {
            qsort(arr, inArr, sizeof(int), comp);
            bool found = 0;
            for(int j = 0; j < inArr && j < K; j++)
                if(arr[j] == idx)
                {
                    found = 1;
                    break;
                }
            printf("%s\n", found ? "YES" : "NO");
        }
        else if(type == 1)
        {
            arr[inArr] = idx;
            inArr++;
        }
//        printInArr();
    }
    return(0);
}
