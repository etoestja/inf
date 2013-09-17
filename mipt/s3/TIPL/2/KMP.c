#include <stdio.h>
#include <string.h>

#define NMAX 100
int prefix[NMAX];
char P[NMAX];
char T[NMAX];
char S[NMAX];

// S <- P#T
void makeS()
{
    sprintf(S, "*%s#%s", P, T);
}

// calculates pi(string[1]...string[len]) and stores to prefix[1]...prefix[len]
void fillPrefix(char* string)
{
    int i, l = strlen(string) - 1, t;

    prefix[0] = 0;

    for(i = 0; i <= l - 1; i++)
    {
        printf("fillPrefix at i=%d, looking at symbol %c\n", i, string[i + 1]);
        t = prefix[i];

        while(string[i + 1] != string[t + 1])
        {
            t = prefix[t];
            if(t == 0)
            {
                printf("  zero prefix[%d, %c]\n", t, string[t]);
                prefix[i + 1] = 0;
                break;
            }
            else
                printf("  going deeper[%d, %c]\n", t, string[t]);
        }
        if(string[i + 1] == string[t + 1] && i != t)
        {
                printf("  got prefix[%d, %c] . '%c'\n", t, string[t], string[i + 1]);
                prefix[i + 1] = t + 1;
        }
    }
}

void printPrefix(char* string)
{
    int i;
    printf("n\t");
    for(i = 0; i < strlen(string); i++)
    {
        if(i < 10)
            printf("%d\t", i);
        else
            printf("%c\t", 'A' + i - 10);
    }
    printf("\nc\t");
    for(i = 0; i < strlen(string); i++)
        printf("%c\t", string[i]);
    printf("\np\t");
    for(i = 0; i < strlen(string); i++)
        printf("%d\t", prefix[i]);
    printf("\n");
}

void findPInT()
{
    int i;
    for(i = 1; i <= strlen(S); i++)
        if(prefix[i] == strlen(P))
            printf("findPInT: found P in T starting from position %d\n", i - strlen(P) + 1);
}

int main()
{
    scanf("%s", &P);
    scanf("%s", &T);

    makeS();
    fillPrefix(S);
    printPrefix(S);
    findPInT();

    return(0);
}
