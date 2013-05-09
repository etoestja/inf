#include <stdio.h>
#include <string.h>

#define MAXN 1000
#define MAXD 11
#define MAXBASE 1000000

#define fprintf zero

void zero(void* s, ...)
{

}

typedef struct equation
{
    //x[j]=a0a1a2...
    int x[MAXD];
    int y[MAXD];
    int z[MAXD];
    int xLen;
    int yLen;
    int zLen;
    char op;
} equation;

typedef unsigned long long nType;

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

nType getNum(int * x, int len)
{
    int i;
    nType answer = 0;
    for(i = 0; i < len; i++)
        answer += ((nType) basePowers[i]) * x[i];
    return(answer);
}

int checkOne(equation *eq)
{
    nType x = getNum(eq->x, eq->xLen);
    nType y = getNum(eq->y, eq->yLen);
    nType z = getNum(eq->z, eq->zLen);

    nType z1;

    if(eq->op == '+')
        z1 = x + y;
    else z1 = x * y;

//    if(z1 == 0)
//        return(0);

    fprintf(stderr, " x=%llu\n y=%llu\n z=%llu\n r=%llu\n", x, y, z, z1);

    //return(((z - z1) % (((nType) 1) << 63)) == 0);
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
        if(!checkOne(array + i)) return(0);
    return(1);
}

void printNum(int *str, int len)
{
    int l = len;
    for(l--; l >= 0; l--)
        fprintf(stderr, "%c", numToChar(str[l]));
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

int poly[MAXD * 2]; //current polynom
#define MAXDIVISORS 10000
int divisors[MAXDIVISORS];
int divisorsCount = 0;
int divisorsInf = 1;

void addNumber(int t);
int addDivisors(int x);
void callDivisors();
void getPoly(equation* eq);
void resetPoly();

//get polynom for equation
void resetPoly()
{
    int i;
    for(i = 0; i < MAXD * 2; i++)
        poly[i] = 0;
}

void printPoly()
{
    int i;
    for(i = MAXD * 2; i >= 0; i--)
        if(poly[i] != 0) break;

    for(; i >= 0; i--)
    {
        if(poly[i])
        {
            if(poly[i] == -1)
            {
                if(i > 0)
                    fprintf(stderr, "-");
                else fprintf(stderr, "-1");
            }
            else if(poly[i] == 1)
                fprintf(stderr, "+");
            else
            {
                if(poly[i] > 0)
                    fprintf(stderr, "+");
                fprintf(stderr, "%d", poly[i]);
            }
            if(i > 0)
                fprintf(stderr, "x");
            if(i > 1)
                fprintf(stderr, "^%d", i);
        }
    }
}

void getPoly(equation* eq)
{
    int i, j;

    if(eq->op == '+')
        for(i = 0; i < MAXD; i++)
            poly[i] = eq->x[i] + eq->y[i];
    else if(eq->op == '*')
        for(i = 0; i < MAXD * 2; i++)
            for(j = 0; j <= i; j++)
            {
                if(j < MAXD && i - j < MAXD)
                    poly[i] += eq->x[j] * eq->y[i - j];
            }

    for(i = 0; i < MAXD; i++)
        poly[i] -= eq->z[i];

    fprintf(stderr, "poly: ");
    printPoly();
    fprintf(stderr, "\n");
}

//call function below for first non-zero coefficient
void callDivisors()
{
    int i;
    for(i = 0; i < MAXD * 2; i++)
        if(poly[i] != 0)
        {
            divisorsInf = 0;
            addDivisors(poly[i] > 0 ? poly[i] : -poly[i]);
            return;
        }
}

//add divisors of a number
int addDivisors(int x)
{
    int i;
    int j = 0;
    divisorsCount = 0;
    for(i = 1; i <= x; i++)
    {
        if(x % i == 0)
        {
            j++;
            addNumber(i);
        }
    }
    return(j);
}

//add a number
void addNumber(int t)
{
    fprintf(stderr, "adding divisor %d\n", t);
    int i;
    for(i = 0; i < divisorsCount; i++)
        if(divisors[i] == 0)
        {
            divisors[i] = t;
            return;
        }
    divisors[divisorsCount++] = t;
}

void rmNumber(int index)
{
    if(index == divisorsCount - 1) divisorsCount--;
    else if(index > divisorsCount - 1) return;
    divisors[index] = 0;
}

void testDivisors()
{
    int i;
    fprintf(stderr, "divCount=%d\n", divisorsCount);
    for(i = 0; i < divisorsCount; i++)
        if(divisors[i] != 0)
        {
            fprintf(stderr, "checking divisor %d\n", divisors[i]);
            if(divisors[i] <= minBase ||
                    !checkAll(divisors[i]))
            {
                fprintf(stderr, "#removing divisor %d\n", divisors[i]);
                rmNumber(i);
            }
        }
}

void processDivisors()
{
    resetPoly();

    int i;
    for(i = 0; i < N; i++)
    {
        divisorsCount = 0;
        divisorsInf = 1;
        getPoly(array + i);
        callDivisors();
        if(!divisorsInf) break;
    }

    testDivisors();
}

int divisorsRecount()
{
    int i, j = 0;
    for(i = 0; i < divisorsCount; i++)
        if(divisors[i] != 0) j++;
    return(j);
}

//void processBruteforce

int main()
{
    scanf("%d", &N);

    int i;
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
//        fprintf(stderr, "input: [%s]\n", str);
        parseStr(str, array + i);
    }
//    printAll();

//    int lastFound = 0;

//    for(i = minBase + 1; i < MAXBASE; i++)
//    {
//        if(checkAll(i))
//        {
//            if(lastFound != 0)
//            {
//                printf("-1\n");
//                return(0);
//            }
//            lastFound = i;
//        }
//    }

    processDivisors();

    fprintf(stderr, "inf=%d\n", divisorsInf);
    fprintf(stderr, "count=%d\n", divisorsCount);

    //int i;
    for(i = 0; i < divisorsCount; i++)
    {
        if(divisors[i] != 0)
            fprintf(stderr, "%d\n", divisors[i]);
    }

    if(divisorsInf == 1)
    {
        printf("-1\n");
    }
    else
    {
        j = divisorsRecount();
        if(j == 1)
        {
            for(i = 0; i < divisorsCount; i++)
            {
                if(divisors[i] != 0)
                {
                    printf("%d\n", divisors[i]);
                    return(0);
                }
            }
        }
        else if(j == 0)
            printf("0\n");
        else printf("-1\n");
    }

    //printf("%d\n", lastFound);
    return(0);
}
