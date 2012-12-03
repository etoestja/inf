#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NMAX (200 + 2)

char arr[NMAX];

int charcmp(const void * p1, const void * p2)
{
    if(*((char*) p1) > *((char*) p2)) return(1);
    else if(*((char*) p1) < *((char*) p2)) return(-1);
    return(0);
}

int main(void)
{
//    freopen("next.in", "r", stdin);
//    freopen("next.out", "w", stdout);
    scanf("%s", arr);

    int N = strlen(arr), i, imax, imin;

    char t;

    for(imax = N - 2; imax >= 0; imax--)
    {
        imin = -1;

        for(i = imax; i < N; i++)
        {
            if(arr[i] > arr[imax] && (imin == -1 || arr[i] < arr[imin])) imin = i;
        }
        if(imin != -1)
        {
            //arr[imax] arr[imin]
            //arr[imin] ... sorted
            t = arr[imin];
            arr[imin] = arr[imax];
            arr[imax] = t;
            qsort(arr + imax + 1, N - imax - 1, sizeof(char), charcmp);
            printf("%s\n", arr);
            return(0);
        }
    }

    printf("no word\n");
    return(0);

    return 0;
}

