#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    int* arr = (int *) malloc(sizeof(int) * N);

    int i;
    for(i = 0; i < N; i++)
        scanf("%x", &(arr[i]));

    unsigned int y;
    scanf("%x", &y);
    unsigned int x = (y >> 26);
    if(x >= N) printf("error");
    else
    {
        y <<= 6;
        y >>= 6;
        printf("%x", arr[x] + y);
    }

    printf("\n");
    return(0);
}
