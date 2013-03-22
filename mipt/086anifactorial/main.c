#include "stdio.h"

#define LMAX 255

const int base = 10;

typedef struct mylong
{
    short int arr[LMAX];
    int size;
} mylong;

int mylongCmp(mylong a, mylong b)
{
    if(a.size == b.size)
    {
        int p;
        for(p = a.size - 1; p >= 0; p--)
        {
            if(a.arr[p] != b.arr[p])
                return(a.arr[p] > b.arr[p]);
        }
    }
    else
        return(a.size > b.size);
    return(0);
}

mylong mylongCreate()
{
    mylong res;
    res.size = 0;
    int i;
    for(i = 0; i < LMAX; i++) res.arr[i] = 0;
    return(res);
}

mylong mylongAdd(mylong a, mylong b)
{
    int carry = 0;
    int i = 0;
    mylong res = mylongCreate();

    int cDigit;

    while(i < a.size || i < b.size || carry)
    {
        cDigit = carry;
        if(i < a.size)
            cDigit += a.arr[i];
        if(i < b.size)
            cDigit += b.arr[i];

        res.arr[i] = cDigit % base;
        carry = cDigit / base;
        i++;
    }

    res.size = i;

    return(res);
}

mylong mylongMul(mylong a, int b)
{
    mylong res = mylongCreate();
    int i;
    //123456789
    //    12345

    //    100
    //x   100
    //  100


    //876543210
    int carry = 0;
    int bDigit, cDigit, offset = 0;
    mylong temp;
    while(b)
    {
        bDigit = b % base;

        //printf("bDigit is %d\n", bDigit);

        carry = 0;
        temp = mylongCreate();
        i = 0;
        while(i < a.size || carry)
        {
            cDigit = carry;
            if(i < a.size)
                cDigit += a.arr[i] * bDigit;
            temp.arr[i + offset] = cDigit % base;
            carry = cDigit / base;
            i++;
        }
        temp.size = i + offset;

        //mylongPrint(temp);
        //printf("\n");

        res = mylongAdd(res, temp);

        b -= bDigit;
        b /= base;
        offset++;
    }

    for(i = LMAX - 1; i >= 0; i--)
        if(res.arr[i] != 0)
        {
            res.size = i + 1;
            break;
        }

    return(res);
}

void mylongPrint(mylong a)
{
    int i;
    for(i = a.size - 1; i >= 0; i--)
        printf("%d", a.arr[i]);
}

int t;
#define swap(x, y) {t = (x); (x) = (y); (y) = t;}

mylong mylongRevers(mylong a)
{
    int i;
    for(i = 0; i < a.size / 2; i++)
    {
        swap(a.arr[i], a.arr[a.size - i - 1]);
    }
    return(a);
}

mylong mylongScan()
{
    mylong a = mylongCreate();
    char c;
    while(scanf("%c", &c) > 0 && c >= '0' && c <= '9')
        a.arr[a.size++] = c - '0';
    a = mylongRevers(a);
    return(a);
}

mylong factorial(int n)
{
    mylong res = mylongCreate();
    res.size = 1;
    res.arr[0] = 1;

    for(; n; n--)
        res = mylongMul(res, n);
    return(res);
}

int main(void)
{
    int l = 1;
    int r = 146;
    int m;

//    scanf("%d", &m);

//    mylong a = factorial(m);
//    mylongPrint(a);
//    printf("\n");

    mylong a = mylongScan();

    while(r - l > 1)
    {
        m = (l + r) / 2;
        if(mylongCmp(factorial(m), a)) r = m;
        else l = m;
    }

    if(!mylongCmp(factorial(r), a)) l = r;

    printf("%d\n", l);

    return 0;
}

