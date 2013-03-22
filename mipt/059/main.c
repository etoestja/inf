#include <stdio.h>

#define KMAX 20
int arr[KMAX];

int main()
{
    int K, N, i;
    scanf("%d%d", &N, &K);

    for(i = 0; i < K; i++)
        scanf("%d", &(arr[i]));

    unsigned int counter;
    int maxTime = 0, cTime;

    for(counter = 0; counter < (1 << K); counter++)
    {
        cTime = 0;
        for(i = 0; i < K; i++)
            cTime += (counter & (1 << i)) ? arr[i] : 0;
        if(cTime <= N && maxTime < cTime) maxTime = cTime;
    }

    printf("%d\n", maxTime);
}
