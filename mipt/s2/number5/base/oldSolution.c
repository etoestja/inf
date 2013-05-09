#include <stdio.h>
#include <string.h>

#define MAXN 1000
#define MAXD 11
#define MAXBASE 3000

typedef struct equation
{
    //x[j]=a0a1a2...
    char x[MAXD];
    char y[MAXD];
    char z[MAXD];
    int xLen;
    int yLen;
    int zLen;
    char op;
} equation;

typedef unsigned long long nType;

#define fprintf zero

void zero(void* s, ...)
{

}

nType basePowers[MAXD];
struct equation array[MAXN];
int minBase = 0;
int N;

int charOk(char c)
{
    return((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'));
}

int find(char* s, char c)
{
    int i = 0;
    while(s[i] && s[i] != c) i++;
    if(!s[i]) return(0);
    return(i);
}

char charToNum(char c)
{
    if(c >= '0' && c <= '9') return(c - '0');
    else return(c - 'a' + 10);
}

char numToChar(char c)
{
    if(c <= 9) return(c + '0');
    return(c + 'a' - 10);
}

void parseStr(char* s, equation *eq)
{
    int pPlus = find(s, '+');
    int pMul  = find(s, '*');
    int pEq   = find(s, '=');
//    printf("p+=%d\tp*=%d\tp==%d", pPlus, pMul, pEq);
    eq->op = pMul ? '*' : '+';
    
    if(pMul == 0) pMul = pPlus;

    int i, j;
    for(i = pMul - 1, j = 0; i >= 0; i--, j++)
    {
        eq->x[j] = charToNum(s[i]);
        if(eq->x[j] > minBase) minBase = eq->x[j];
    }
    eq->xLen = pMul;

    for(i = pEq - 1, j = 0; i > pMul; i--, j++)
    {
        eq->y[j] = charToNum(s[i]);
        if(eq->y[j] > minBase) minBase = eq->y[j];
    }
    eq->yLen = pEq - pMul - 1;

    for(i = strlen(s) - 1, j = 0; i > pEq; i--, j++)
    {
        eq->z[j] = charToNum(s[i]);
        if(eq->z[j] > minBase) minBase = eq->z[j];
    }
    eq->zLen = strlen(s) - pEq - 1;
}

void strNorm(char* str)
{
    if(!charOk(*(str + strlen(str) - 1)))
        *(str + strlen(str) - 1) = 0;
}

nType getNum(char * x, int len, nType base)
{
    int i;
    nType baseAcc = 1;
    nType answer = 0;
    for(i = 0; i < len; i++)
        answer += basePowers[i] * x[i];
    return(answer);
}

int checkOne(equation *eq, nType base)
{
    nType x = getNum(eq->x, eq->xLen, base);
    nType y = getNum(eq->y, eq->yLen, base);
    nType z = getNum(eq->z, eq->zLen, base);

    nType z1;

    if(eq->op == '+')
        z1 = x + y;
    else z1 = x * y;

    if(z1 == 0)
        return(0);

    if(z == z1)
        fprintf(stderr, " x=%llu\n y=%llu\n z=%llu\n r=%llu\n", x, y, z, z1);

//    return((z - z1) % (1 << 16) == 0);
    return(z == z1);
}

void getBasePowers(nType base)
{
    nType baseAcc = 1, i;
    for(i = 0; i < MAXD; i++)
    {
        basePowers[i] = baseAcc;
        baseAcc *= base;
    }
}

int checkAll(nType base)
{
    getBasePowers(base);
    int i;
    for(i = 0; i < N; i++)
        if(!checkOne(array + i, base)) return(0);
    return(1);
}

void printNum(char *str, int len)
{
    int l = len;
    for(l--; l >= 0; l--)
        printf("%c", numToChar(str[l]));
}

void printOne(equation *eq)
{
    printNum(eq->x, eq->xLen);
    printf("%c", eq->op);
    printNum(eq->y, eq->yLen);
    printf("=");
    printNum(eq->z, eq->zLen);
    printf(" %d %d %d", eq->xLen, eq->yLen, eq->zLen);
    printf("\n");
}

void printAll()
{
    int i;
    for(i = 0; i < N; i++)
        printOne(array + i);
}

int main()
{
    scanf("%d", &N);

    int i, j1;
    unsigned char *ptr;
    char str[MAXD * 3 + 5];
    char c;

    int j;
    for(i = 0; i < MAXN; i++)
    {
        for(j = 0; j < MAXD; j++)
        {
            array[i].x[j] = 0;
            array[i].y[j] = 0;
            array[i].z[j] = 0;
        }
        array[i].op = 0;
    }

    for(i = 0; i < N; i++)
    {
        while(scanf("%c", &c) > 0 && !charOk(c));
        ungetc(c, stdin);
        scanf("%s", str);
        strNorm((char*) str);
//        printf("input: [%s]\n", str);
        parseStr(str, array + i);
    }
//    printAll();

    int lastFound = 0;

    for(i = minBase + 1; i < MAXBASE; i++)
    {
        if(checkAll(i))
        {
            fprintf(stderr, "found %d\n", i);
            if(lastFound != 0)
            {
                printf("-1\n");
                return(0);
            }
            lastFound = i;
        }
    }

    printf("%d\n", lastFound);
    return(0);
}
