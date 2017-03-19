#include <string.h>
#include <stdio.h>

#define NMAX 51

int N, K;

#define LMAX 15

char names[NMAX][LMAX];

int answers[NMAX];

int S;

int is_OK()
{
    for(int s = 0; s < S; s++)
    {
        // s...s + k - 1
        bool dup_found = 0;
        for(int i = s; i <= s + K - 1; i++)
        {
            for(int j = i + 1; j <= s + K - 1; j++)
            {
                if(!strcmp(names[i], names[j]))
                {
                    dup_found = 1;
                }
            }
        }
        bool need_dup = !answers[s];
        if(dup_found != need_dup)
        {
            //printf("Error for s = %d range [%d %d] true = %d our = %d\n", s, s, s + K - 1, need_dup, dup_found);
            return(0);
        }
    }
    return(1);
}

void fill_name(char* dst, int i)
{
    char tmp[LMAX];
    char start_c = 'a';
    char end_c = 'z';
    int ptr = 0;
    int NCHAR = (end_c - start_c + 1);
    while(i >= 0)
    {
        tmp[ptr] = start_c + i % NCHAR;
        i /= NCHAR;
        ptr++;
        if(i == 0)
            break;
    }

    for(int i = 0; i < ptr; i++)
        dst[i] = tmp[ptr - i - 1];

    dst[0] += 'A' - 'a';
}

void different_names()
{
    for(int i = 0; i < N; i++)
        fill_name(names[i], i);
}

int main()
{
    scanf("%d", &N);
    scanf("%d", &K);

    memset(names, 0x00, sizeof(names));

    different_names();

    /*for(int i = 0; i < N; i++)
    {
        printf("%s\n", names[i]);
    }*/

    S = N - K + 1;

    for(int i = 0; i < S; i++)
    {
        char in[LMAX];
        scanf("%s", in);
        if(!strcmp(in, "YES"))
        {
            answers[i] = 1;
        }
        else if(!strcmp(in, "NO"))
        {
            answers[i] = 0;
        }

        //printf("Answers %d = %d\n", i, answers[i]);
    }

    for(int i = 0; i < S; i++)
    {
        if(!answers[i])
        {
            // i -> i + k - 1
            // names[i + k - 1] <- names[i]
            //printf("Copying %d <- %d\n", i + K - 1, i);
            memcpy(names[i + K - 1], names[i], LMAX);
        }
    }

    for(int i = 0; i < N; i++)
    {
        printf("%s\n", names[i]);
        //printf("%d %s\n", i, names[i]);
    }

    return(!is_OK());

    return(0);
}
