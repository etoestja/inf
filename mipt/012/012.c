#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DMAX 1000
#define LMAX (20 + 1)
#define TMAX 20

int arr[DMAX][DMAX];
int D, wordsUsed = 0, wordsCountUsed = 0;
char words[DMAX][LMAX], dwords[DMAX][LMAX];

int visited[DMAX];

int time[DMAX], ctime;

int findOrInsertWord(char word[LMAX], char words[DMAX][LMAX], int* wordsUsed)
{
    int i;
    for(i = 0; i < *wordsUsed; i++)
        if(!strcmp(word, words[i])) return(i);
    for(i = 0; i < LMAX; i++)
        words[*wordsUsed][i] = word[i];
    (*wordsUsed)++;
    return(*wordsUsed - 1);
}

void incorrect()
{
    printf("NOT CORRECT\n");
    exit(0);
}

void dfs(int vertex)
{
//    fprintf(stderr, "dfs at %d\n", vertex);
    if(visited[vertex])
    {
        if(time[vertex] == -1)
        {
//            fprintf(stderr, "error at vertex %d\n", vertex);
            incorrect();
        }
        return;

    }
    visited[vertex] = 1;

    int j;
    for(j = 0; j < D; j++)
    {
        if(arr[vertex][j])
        {
//            fprintf(stderr, "dfs at %d and going to %d\n", vertex, j);
            dfs(j);
        }
    }

    time[vertex] = ctime++;
}

int main()
{
    int i, tN, t, prevCount;
    char tw[LMAX], ttw[LMAX];

    int i1, i2, iCount, badBit = 0;

    for(i1 = 0; i1 < DMAX; i1++)
    {
        for(i2 = 0; i2 < DMAX; i2++)
            arr[i1][i2] = 0;
    }

    scanf("%d", &D);

    for(i = 0; i < D; i++)
    {
        scanf("%s", tw);
        i1 = findOrInsertWord(tw, words, &wordsUsed);

        prevCount = wordsCountUsed;
        iCount = findOrInsertWord(tw, dwords, &wordsCountUsed);
        if(wordsCountUsed == prevCount)
            badBit = 1;
//        else fprintf(stderr, "new word %s\n", tw);

        scanf("%d", &tN);
        for(t = 0; t < tN; t++)
        {
            scanf("%s", ttw);
            i2 = findOrInsertWord(ttw, words, &wordsUsed);
            arr[i1][i2] = 1;
        }
    }

    D = wordsUsed;

/*    for(i = 0; i < D; i++)
    {
        for(t = 0; t < D; t++)
            printf("%d ", arr[i][t]);
        printf("\n");
    }*/

    if(badBit) incorrect();

    for(i = 0; i < D; i++)
    {
        ctime = 0;
        for(t = 0; t < D; t++)
        {
            visited[t] = 0;
            time[t] = -1;
        }
//        fprintf(stderr, "dfs from %d\n", i);
        dfs(i);
    }

    printf("CORRECT\n");
    return(0);
}
