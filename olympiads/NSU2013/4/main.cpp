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
        A = (2 * H - R) * R / (6 * H);
    }
    else
    {
        A = H * (H * H - 8 * H * R + 24 * R * R) / (96 * R * R);
    }
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
