#include <iostream>
#include <string>

using std::cout;
using std::endl;

using std::string;

const unsigned N = 7;

const double t[N] = {19.1, 25.0, 30.1, 36.0, 40.0, 45.1, 50.0};
const double R[N] = {76.30, 77.80, 79.75, 80.80, 82.35, 83.90, 85.10};

void print_v(double v, string s)
{
    cout << s << " = " << v << endl;
}

int main()
{
    double st = 0, st2 = 0, sR = 0, stR = 0;
    for(unsigned i = 0; i < N; i++)
    {
        st += t[i];
        st2 += t[i] * t[i];
        sR += R[i];
        stR += t[i] * R[i];
    }

    double d = N * st2 - st * st;

    double d0 = sR * st2 - stR * st;
    double d1 = N * stR - st * sR;

    print_v(st, "st");
    print_v(st2, "st2");
    print_v(sR, "sR");
    print_v(d0 / d, "a0");
    print_v(d1 / d, "a1");

    return(0);
}
