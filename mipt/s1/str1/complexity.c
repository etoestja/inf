#include <stdio.h>
#include <string.h>

#define N 100

int beginClosed = 0;

struct complexity
{
    long long int arr[N];
};

struct complexity getComplexity();
struct complexity getComplexityOne();

void pPrint(struct complexity res)
{
    int i, isPrinted = 0;
    for(i = 10; i >= 0; i--)
    {
        if(res.arr[i])
        {
            if(isPrinted) printf("+");
            if(i > 0)
            {
                if(res.arr[i] != 1)
                    printf("%lld*", res.arr[i]);
                printf("n");
                if(i != 1)
                    printf("^%lld", i);
            }
            else
                printf("%lld", res.arr[i]);
            isPrinted = 1;
        }
    }
    if(!isPrinted)
        printf("0");

    printf("\n");
}

struct complexity pMul(struct complexity a, struct complexity b)
{
    struct complexity res;
    int i, j;

    for(i = 0; i < N; i++) res.arr[i] = 0;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
        {
            if(i + j < N)
                res.arr[i + j] += a.arr[i] * b.arr[j];
        }

    return(res);
}

int eatone()
{
    char c;
    if((c = getc(stdin)) > 0)
    {
        if(c != ' ' && c != '\r' && c != '\n')
        {
            ungetc(c, stdin);
            return 0;
        }
        else
            return 1;
    }
    return 0;
}

void eat()
{
    while(eatone());
}

int isZero(struct complexity c)
{
    int i;
    for(i = 0; i < N; i++)
        if(c.arr[i] != 0) return(0);
    return(1);
}

struct complexity pSum(struct complexity a, struct complexity b)
{
    int i;
    struct complexity res;
    for(i = 0; i < N; i++) res.arr[i] = a.arr[i] + b.arr[i];
    return(res);
}

int isDataAvailable()
{
    eat();
    char c;
    if(scanf("%c", &c) > 0)
    {
        ungetc(c, stdin);

        //printf("got: %c\n", c);

        if(c == 'O' || c == 'B' || c == 'L')
            return 1;
    }
    return 0;
}

struct complexity getComplexity()
{
    int i;

    struct complexity res;

    for(i = 0; i < N; i++) res.arr[i] = 0;

    while(!beginClosed && isDataAvailable())
    {
        eat();
        res = pSum(res, getComplexityOne());
    }

    return(res);
}

struct complexity getComplexityOne()
{
    int i;
    long long int tint;
    struct complexity res;
    for(i = 0; i < N; i++) res.arr[i] = 0;
    char cmd[N];
    char c;

    eat();
    if(scanf("%s", cmd) > 0)
    {
        if(!strcmp(cmd, "OP"))
        {
            eat();
            scanf("%lld", &tint);
            res.arr[0] = tint;
        }
        else if(!strcmp(cmd, "BEGIN"))
        {
            res = getComplexity();
            eat();
            scanf("%s", cmd);
            beginClosed = 1;
        }
        else if(!strcmp(cmd, "LOOP"))
        {
            eat();
            scanf("%c", &c);
            if(c == 'n') res.arr[1] = 1;
            else
            {
                ungetc(c, stdin);
                scanf("%lld", &tint);
                res.arr[0] = tint;
            }
            res = pMul(res, getComplexity());
            eat();
            scanf("%s", cmd);
        }
        else if(cmd[0])
        {
            for(i = 0; cmd[i]; i++)
                ungetc(cmd[i], stdin);
        }
    }

    return(res);
}

int main()
{
    freopen("complexity.in", "r", stdin);
    freopen("complexity.out", "w", stdout);

    struct complexity res = getComplexity();

    printf("Runtime = ");
    pPrint(res);

    fclose(stdin);
    fclose(stdout);


    return(0);
}
