#include <iostream>
#include <stdlib.h>

using namespace std;

#define RC 150

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
    long long x = binPow(a, t, m);
    cerr << "x=" << x << endl;
    if(x == 1)
        return(true);
    for(long long i = 1; i <= s - 1; i++)
    {
        if(x == m - 1)
            return(true);
        x = modMult(x, x, m);
    }
    cerr << "x=" << x << endl;
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

int main()
{
    long long N;
    cin >> N;
    cout << isPrime(N) << endl;

//    long long a, b;
//    cin >> a >> b;
//    cout << longPow(a, b) << endl;

    return(0);
}
