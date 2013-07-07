#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG
//#undef DEBUG

#define NMAX 200005
long long arr[NMAX];
long long N;
long long T;

#define RC 150

long long longPow(long long a, long long b, long long m)
{
    long long res = 1;
    long long i;
    for(i = 0; i < b; i++)
    {
        res %= m;
        res *= a;
        res %= m;
    }
    return(res);
}

bool primeTest(long long a, long long s, long long t, long long m)
{
    long long x = longPow(a, t, m);
    //cerr << "x=" << x << endl;
    if(x == 1)
        return(true);
    for(long long i = 1; i <= s - 1; i++)
    {
        if(x == m - 1)
            return(true);
        x = (x * x) % m;
    }
    //cerr << "x=" << x << endl;
    return(x == m - 1);
}

bool isPrime(long long m)
{
    if(m % 2 == 0) return(false);
    if(m <= RC)
    {
        for(int i = 2; i < m; i++)
        {
            if(m % i == 0)
                return(false);
        }
        return(true);
    }

    long long s = 0;
    long long t = m - 1;
    while(t % 2 == 0)
    {
        t /= 2;
        s++;
    }
    //cerr << m << "-1=" << "2**" << s << "*" << t << endl;

    for(long long a = 3; a < RC; a++)
        if(!primeTest(a, s, t, m))
        {
            cerr << a << " " << s << " " << t << " " << m << endl;
            return(false);
        }

    return(true);
}

inline bool llcmp(long long a, long long b)
{
    return(a < b);
}

void dumpArr()
{
    cerr << "=== ARR ===" << endl;
    for(long long i = 0; i < N; i++)
        cerr << arr[i] << " ";
    cerr << endl;
}

bool testDiv()
{
    for(long long i = 0; i < N; i++)
        if((T % arr[i]) != 0)
            return(0);
    return(1);
}

long long countDiv(long long a)
{
    long long res = 0;
    for(long long i = 0; i < N; i++)
        if((a % arr[i]) == 0)
            res++;
    return(res);
}

long long llSqrt(long long a)
{
    long long l = 1;
    long long r = sqrt(a) + 100;
    long long m;
    while(r - l > 1)
    {
        m = (r + l) / 2;
        if(m * m > a)
            r = m;
        else l = m;
    }
    if(l * l == a)
        return(l);
    else if(r * r == a)
        return(r);
    return(-1);
}

long long divisorsN(long long a)
{
    long long res = 1;
    long long alpha;
    for(long long i = 2; i * i * i <= a; i++)
    {
        alpha = 0;
        while(a % i == 0)
        {
#ifdef DEBUG
            cerr << "div " << i << endl;
#endif
            a /= i;
            alpha++;
        }
        res *= 1 + alpha;
    }

    if(a > 1)
    {
        if(isPrime(a)) //p
            res *= 2;
        else if(llSqrt(a) != -1) // p^2
            res *= 3;
        else res *= 4; //pq
    }
    return(res);
}

int main()
{
    scanf("%lld", &N);

    long long i;
    for(i = 0; i < N; i++)
        scanf("%lld", arr + i);

    if(N == 1)
    {
        cout << (arr[0] == 1 ? "yes" : "no") << endl;
        return 0;
    }

    // N > 1

#ifdef DEBUG
    dumpArr();
#endif
    sort(arr, arr + N, llcmp);
#ifdef DEBUG
    dumpArr();
#endif

    T = arr[N - 1];

#ifdef DEBUG
    cerr << "T=" << T << endl;
#endif

    if(divisorsN(T) != N)
    {
#ifdef DEBUG
        cerr << "divisorsN" << endl;
#endif
        cout << "no" << endl;
        return 0;
    }

#ifdef DEBUG
    cerr << "testdiv" << endl;
#endif
    cout << (testDiv() ? "yes" : "no") << endl;

    return(0);
}
