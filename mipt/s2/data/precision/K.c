#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    long n,d;
    long double p=0;
    scanf("%ld", &n);
    for(d=n; d>=1;d--)
    {
        p+=((long double) 1)/((long double)d);
    }
    cout.precision(41);
    cout << p << endl;
    return 0;
}
