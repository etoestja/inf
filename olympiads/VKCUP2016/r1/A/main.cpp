#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

#define NMAX 150005
#define KMAX 6
int topK[KMAX];

int T[NMAX];

int N, K, Q;

int inTopK = 0;

int main()
{
    scanf("%d", &N);
    scanf("%d", &K);
    scanf("%d", &Q);

    for(int i = 0; i < KMAX; i++)
        topK[i] = -1;

    for(int i = 0; i < N; i++)
        scanf("%d", &(T[i]));

    for(int i = 0; i < Q; i++)
    {
        int type, idx;
        scanf("%d %d", &type, &idx);
        idx--;
        if(type == 2)
        {
            bool found = 0;
            for(int j = 0; j < inTopK; j++)
                if(topK[j] == idx)
                {
                    found = 1;
                    break;
                }
            printf("%s\n", found ? "YES" : "NO");
        }
        else if(type == 1)
        {
            int minInTopK = -1;
            for(int j = 0; j < inTopK; j++)
            {
                if(minInTopK == -1 || T[topK[j]] < T[topK[minInTopK]])
                {
                    minInTopK = j;
                }
            }
            if(minInTopK == -1)
            {
                topK[0] = idx;
                inTopK = 1;
            }
            else if(inTopK < K)
            {
                topK[inTopK] = idx;
                inTopK++;
            }
            else if(T[topK[minInTopK]] < T[idx])
            {
                topK[minInTopK] = idx;
            }
        }
    }
    return(0);
}
