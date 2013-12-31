#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

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

int main()
{
    long long N;
    cin >> N;
    cout << llSqrt(N) << endl;

//    long long a, b;
//    cin >> a >> b;
//    cout << longPow(a, b) << endl;

    return(0);
}
