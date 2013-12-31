#include <iostream>
#include <math.h>

using namespace std;

long double dr, dx, R, H;

long double min3(long double x, long double r)
{
    long double res = x;
    if(R - r < res) res = R - r;
    return(res);
}

long double f(long double x)
{
    long double r, res = 0;
//    res = M_PI * (pow(R, 3) / 3. - R * pow(x, 2) + 2. /3 * pow(x, 3));
//    res += M_PI * (pow(x, 3));
    res = M_PI * (pow(H, 4) / 192. - 1. / 24 * pow(H, 3) * R + 1. / 8 * (H * H * R * R));
/*    for(r = 0; r <= R; r += dr)
    {
        res += 2 * M_PI * r * dr * min3(x, r);
    }*/
    return(res);
}

long double g()
{
    long double x, res = 0;
    for(x = 0; x <= H / 2; x += dx)
    {
        res += f(x) * dx;
    }

    res *= 2;
    res /= M_PI * R * R * H;
    return(res);
}

long double N = 5000;

int main()
{
    cin >> R >> H;
    dx = H / N;
    dr = R / N;
    cout.precision(10);
    cout << g() << endl;
    return(0);
}
