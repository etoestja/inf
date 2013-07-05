#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KMAX (1024 + 1)
#define NMAX

int my_strcmp(const void *p1, const void *p2)
{
    return strcmp(* (char * const *) p1, * (char * const *) p2);
}

long long int N, i, t;

int main()
{
    char** arr, c;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%lld", &N);

    if(N != 0)
    {
        while((scanf("%c", &c) > 0) && (c == ' ' || c == '\r' || c == '\n'));
        ungetc(c, stdin);


        arr = malloc(sizeof(char*) * N);

        for(i = 0; i < N; i++)
        {
            arr[i] = malloc(KMAX * sizeof(char*));
            fgets(arr[i], KMAX, stdin);
            t = strlen(arr[i]);
            if(arr[i][t - 1] == '\n')
                arr[i][t - 1] = 0;
        }

        qsort(arr, N, sizeof(char*), my_strcmp);

        for(i = 0; i < N; i++)
        {
            printf("%s\n", arr[i]);
            free(arr[i]);
        }

        free(arr);
    }

    return 0;
}
