#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <fstream>

using namespace std;

#define NMAX 100005
unsigned long long arr[NMAX];
unsigned long long N, i;
unsigned long long ncount[NMAX];

inline int ucmp(unsigned long long x, unsigned long long y)
{
    return(x > y ? 1 : 0);
}

unsigned long long gcd(unsigned long long m, unsigned long long n)
{
    unsigned long long gcdt;
    while(n != 0)
    {
        gcdt = m % n;
        m = n;
        n = gcdt;
    }
    return(m);
}

int main()
{
    ifstream in("wheel.in");
    ofstream out("wheel.out");

    in >> N;

    if(N == 0)
    {
        out << 0 << endl;
        return 0;
    }
    else if(N == 1)
    {
        out << 1 << endl;
        return 0;
    }

    vector<unsigned long long> arr;
    arr.resize(N + 1);

    for(i = 0; i < N; i++)
        in >> arr[i];
    sort(arr.begin(), arr.end(), ucmp);

    for(i = 0; i < N; i++) ncount[i] = 0;

    unsigned long long int uniquec = 0;
    for(i = 0; i < N; i++)
    {
        if(i > 0 && arr[i] != arr[i - 1])
            uniquec++;
        ncount[uniquec]++;
    }

    unsigned long long gcdres = ncount[0];
    for(i = 1; i <= uniquec; i++)
        gcdres = gcd(gcdres, ncount[i]);

    out << N / gcdres << endl;

    return 0;
}