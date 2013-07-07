#include <iostream>

using namespace std;

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

int main()
{
    long long a, b, m;
    cin >> a >> b >> m;
    cout << binPow(a, b, m) << endl;
    return(0);
}
