#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

long double x, v, a, m = 1, l = 1, t = 0, dt = 1e-4, tm = 10000, k = 1;

int main()
{
    x = 0.0025;
    v = 0;
    a = 0;

    long double t_x_prev = 0, xPrev = 0;

    for(t = 0; t <= tm; t += dt)
    {
        x += v * dt + a * dt * dt / 2;
        v += a * dt;
        a = - k / m * (sqrt(pow(l, 2) + pow(x, 2)) - l) * x / sqrt(pow(x, 2) + pow(l, 2));

        if(t != 0 && ((xPrev >= 0 && x <= 0) || (xPrev <= 0 && x >= 0)))
        {
            cout << "Period/2: " << t - t_x_prev << endl;
            t_x_prev = t;
        }

//        cerr << "t = " << t << "\t" << "x = " << x << "\t" << "v = " << v << "\t" << "a = " << a << endl;

        xPrev = x;
    }

    return(0);
}
