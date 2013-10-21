#include <iostream>
#include <stdio.h>

using namespace std;

unsigned long long a, b, A, B, C, N, K;
#define KMAX (200000 + 5)

int arr[KMAX];
int arrP = 0;

unsigned int d[200010];
unsigned int size = 0;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void SiftUp(int i)
{
    if ((i > 1) && (d[i] < d[i/2]))
    {
        swap(d[i], d[i >> 1]);
        SiftUp(i >> 1);
    }
}

void SiftDown(int i)
{
    int min;
    if (i*2 > size)
        return;
    if ((i*2 == size) || (d[i*2] < d[i*2+1]))
        min = i*2;
    else
        min = i*2+1;
    if (d[i] > d[min])
    {
        swap(d[i], d[min]);
        SiftDown(min);
    }
}

void Add(int x)
{
    size++;
    d[size] = x;
    SiftUp(size);
}

int top()
{
    return d[1];
}

int pop()
{
    int ans = d[1];
    swap(d[1], d[size]);
    size--;
    SiftDown(1);
    return ans;
}

//#define DEBUG
#define OUTPUT

#define PL ((unsigned long long) (2147483648))

void input()
{
    scanf("%llu", &N);
    scanf("%llu", &K);
    scanf("%llu", &a);
    scanf("%llu", &b);
    scanf("%llu", &A);
    scanf("%llu", &B);
    scanf("%llu", &C);
}

inline void update(long long t)
{
    int tm = t;
#ifdef DEBUG
    cout << "tm=" << tm << endl;
#endif
    if(size < K)
    {
#ifdef DEBUG
        cout << "SIZE0" << endl;
#endif
        Add(tm);
    }
    else
    {
#ifdef DEBUG
        cout << " TOP=" << h.top() << endl;
#endif
        //WARNINGWARNINGWARNING
        if(tm >= top())
            //if(tm < h.top())
        {
#ifdef DEBUG
            cout << " TM<=TOP" << endl;
#endif
            Add(tm);
            if(size > K)
            {
                pop();
            }
        }
    }
#ifdef DEBUG
    cout <<  endl;
#endif
}

void output()
{
#ifdef DEBUG
    cout << "sz=" << size << endl;
#endif
    //pop();
    while(size > 0)
        arr[arrP++] = pop();
#ifdef OUTPUT
    for(int i = arrP - 1; i >= 0; i--)
        printf("%d ", arr[i]);
#endif
    printf("\n");
}

void generate()
{
    unsigned long long i;
    unsigned long long t, tprev = -1;

    for(i = 1; i <= N; i++)
    {
        //        t = (A * a) % PL;
        //        t += (B * b) % PL;
        //        t += C % PL;
        //        t %= PL;
        t = ((A * a) + (B * b) + C) % (PL);
#ifdef DEBUG
        cout << i << ": " << t << endl;
#endif
        // >=
        if((tprev == -1) || (t >= tprev) || (size < K))
            update(t);
        a = b;
        b = t;
        tprev = t;
    }
}

int main()
{
    input();
    generate();
    output();
    //    h.push(-1);
    //    h.push(-3);
    //    h.push(-5);
    //    cout << "TOP=" << h.top() << endl;
    return 0;
}
