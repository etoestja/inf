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
//    return(sqrt(1 + x) - 1 / x);
    return(2 * pow(x, 7) - 16 * pow(x, 4) - 1);
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
    double l = 1.9, r = 2.1;
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
