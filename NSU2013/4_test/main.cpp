#include <iostream>
#include <math.h>

using namespace std;

long double dr, dx, R, H;

long double min3(long double x, long double r)
{
    long double res = x;
    if(H - x < res) res = H - x;
    if(R - r < res) res = R - r;
    return(res);
}

long double f(long double x)
{
    long double r, res = 0;
    for(r = 0; r <= R; r += dr)
    {
        res += 2 * M_PI * r * dr * min3(x, r);
    }
    return(res);
}

long double g()
{
    long double x, res = 0;
    for(x = 0; x <= H; x += dx)
    {
        res += f(x) * dx;
    }

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
