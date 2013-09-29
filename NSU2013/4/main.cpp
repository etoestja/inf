#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

ifstream ain("input.txt");
ofstream aout("output.txt");

long double R, H;

long double g()
{
    long double A = 0;
    if(H >= 2 * R)
    {
        A = pow(R, 4) / 4. + pow(R, 4) / 6. + pow(R, 3) * (H / 2. - R) / 3.;
    }
    else
    {
        A = pow(H, 4) / 64. + pow(H, 4) / 96. - 1. / 24 * pow(H, 3) * R + 1. / 6 * H * pow(R, 3);
    }
    A *= 2;
    A /= pow(R, 2) * H;
    A /= 5. / 3;
    return(A);
}

int main()
{
    ain >> R >> H;
    //cout << "R=" << R << " H=" << H << endl;
    aout.precision(20);
    aout << g() << endl;
    return(0);
}
