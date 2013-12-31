#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

//#define DEBUG
#undef DEBUG

#define NMAX 200005
long long arr[NMAX];
long long N;
long long T;

#define RC 200

long long modMult(long long a, long long b, long long m)
{
    long long res = 0;
    a %= m;
    while(b)
    {
        if(b & 1)
        {
            res += a;
            res %= m;
            b--;
        }
        else
        {
            a += a;
            a %= m;
            b >>= 1;
        }
    }
    return(res);
}

long long binPow(long long a, long long b, long long m)
{
    long long res = 1;
    a %= m;
    while(b)
    {
        if(b & 1)
        {
            //res *= a;
            res = modMult(res, a, m);
            res %= m;
            b--;
        }
        else
        {
            //a *= a;
            a = modMult(a, a, m);
            a %= m;
            b >>= 1;
        }
    }
    return(res);
}

bool primeTest(long long a, long long s, long long t, long long m)
{
#ifdef DEBUG
    cerr << "a=" << a << " s=" << s << " t=" << t << " m=" << m << endl;
#endif
    long long x = binPow(a, t, m);
#ifdef DEBUG
    cerr << "x=" << x << endl;
#endif

    if(x == 1)
        return(true);
    for(long long i = 1; i <= s - 1; i++)
    {
        if(x == m - 1)
            return(true);
        x = modMult(x, x, m);
    }
    //cerr << "x=" << x << endl;
    return(x == m - 1);
}

bool isPrime(long long m)
{
#ifdef DEBUG
    cerr << "isPrime" << endl;
#endif
    if(m == 2) return(true);
    if(m % 2 == 0) return(false);
    if(m <= RC)
    {
        for(long long i = 2; i < m; i++)
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
#ifdef DEBUG
    cerr << m << "-1=" << "2**" << s << "*" << t << endl;
#endif

    for(long long a = 3; a < RC - 1; a++)
        if(!primeTest(a, s, t, m))
        {
#ifdef DEBUG
            cerr << a << " " << s << " " << t << " " << m << endl;
#endif
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

long long llSqrt(unsigned long long a)
{
#ifdef DEBUG
    cerr << "llSqrt a=" << a << endl;
#endif
    unsigned long long l = 1;
    unsigned long long r = sqrt(a);
    r <<= 1;

    unsigned long long m;
    while(r - l > 1)
    {
#ifdef DEBUG
        cerr << "llSqrt l=" << l << " m=" << m << " r=" << r;
#endif
        m = (r + l) / 2;
        if(m * m > a)
        {
#ifdef DEBUG
            cerr << " <- ";
#endif
            r = m;
        }
        else
        {
#ifdef DEBUG
            cerr << " -> ";
#endif
            l = m;
        }
#ifdef DEBUG
        cerr << endl;
#endif
    }
#ifdef DEBUG
    cerr << "/llSqrt l= " << l << " r=" << r << endl;
#endif
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
#ifdef DEBUG
        cerr << "a > 1, a=" << a << endl;
#endif
        if(isPrime(a))
        {
#ifdef DEBUG
            cerr << " # a isPrime" << endl;
#endif
            res *= 2;
        }
        else if(llSqrt(a) != -1) // p^2
        {
#ifdef DEBUG
            cerr << " # a = p^2" << endl;
#endif
            res *= 3;
        }
        else
        {
#ifdef DEBUG
            cerr << " # a = pq" << endl;
#endif
            res *= 4; //pq
        }
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

    long long dN = divisorsN(T);
    if(dN != N)
    {
#ifdef DEBUG
        cerr << "divisorsN mismatch: got " << N << " instead of " << dN << endl;
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
