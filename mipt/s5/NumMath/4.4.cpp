#include <iostream>
#include <string>
#include <math.h>

using std::cout;
using std::endl;

using std::string;

void print_v(double v, string s)
{
    cout << s << " = " << v << endl;
}

double f(double x)
{
    return(0.001 * pow(x, 5) + pow(x, 2) - 1);
}

int sign(double x)
{
    if(x == 0)
        return(0);
    else if(x > 0)
        return(1);
    else if(x < 0)
        return(-1);
}

int main()
{
//    double l = -10, r = -9;
//    double l = -1.5, r = -0.5;
    double l = 0.5, r = 1.5;
    double m;

    int sl = sign(f(l));
    int sr = sign(f(r));
    int sm;

    double eps = 0.01;

    while(r - l >= eps)
    {
        m = (l + r) / 2;
        sm = sign(f(m));
        
        if(sm == sl)
            l = m;
        else r = m;
        cout << l << "\t" << r << endl;
    }

    return(0);
}
