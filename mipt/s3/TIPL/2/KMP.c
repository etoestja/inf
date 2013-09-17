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

// prints S[1]...S[p]
void printSPrefix(int p)
{
    int i;
    printf("<");
    for(i = 1; i <= p; i++)
        printf("%c", S[i]);
    printf(">\t");
}

// calculates pi(string[1]...string[len]) and stores to prefix[1]...prefix[len]
void fillPrefix(char* string)
{
    int i, l = strlen(string) - 1, t;

    prefix[0] = 0;

    for(i = 0; i <= l - 1; i++)
    {
        printf("Looking at [%d], %c:", i + 1, string[i + 1]);
        t = prefix[i];
        printf("\tlastP=");
        printSPrefix(t);

        while(string[i + 1] != string[t + 1])
        {
            t = prefix[t];
            printf("lastP=");
            printSPrefix(t);
            if(t == 0)
            {
                printf("break\t");
                prefix[i + 1] = 0;
                break;
            }
        }
        if(string[i + 1] == string[t + 1] && i != t)
        {
            prefix[i + 1] = t + 1;
            printf("Found P=");
            printSPrefix(prefix[i + 1]);
        }
        else
        {
            printf("Found P=<>");
        }
        printf("\n");
    }
}

void printPrefix(char* string)
{
    int i;
    printf("n ");
    for(i = 0; i < strlen(string); i++)
    {
        if(i < 10)
            printf("%d ", i);
        else
            printf("%c ", 'A' + i - 10);
    }
    printf("\nc ");
    for(i = 0; i < strlen(string); i++)
        printf("%c ", string[i]);
    printf("\np ");
    for(i = 0; i < strlen(string); i++)
        printf("%d ", prefix[i]);
    printf("\n");
}

void findPInT()
{
    int i;
    for(i = 1; i <= strlen(S); i++)
        if(prefix[i] == strlen(P))
            printf("Found, starting from %d\n", i - strlen(P) + 1);
}

int main()
{
    scanf("%s", &P);
    scanf("%s", &T);

    makeS();
    printf("Filling prefix[]\n");
    fillPrefix(S);
    printf("\nPrefix function:\n");
    printPrefix(S);
    printf("\nResult:\n");
    findPInT();

    return(0);
}
