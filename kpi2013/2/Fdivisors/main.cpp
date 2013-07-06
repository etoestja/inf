#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG
//#undef DEBUG

#define NMAX 200005
long long arr[NMAX];
long long N;
long long T;

inline bool llcmp(long long a, long long b)
{
    return(a < b);
}

void dumpArr()
{
    cerr << "=== ARR ===" << endl;
    for(long long i = 0; i < N; i++)
        cerr << arr[i] << " ";
    cerr << endl;
}

bool testDiv()
{
    for(long long i = 0; i < N; i++)
        if((T % arr[i]) != 0)
            return(0);
    return(1);
}

long long countDiv(long long a)
{
    long long res = 0;
    for(long long i = 0; i < N; i++)
        if((a % arr[i]) == 0)
            res++;
    return(res);
}

long long divisorsN(long long a)
{
    long long res = 1;
    long long alpha;
    for(long long i = 2; i * i * i <= a; i++)
    {
        alpha = 0;
        while(a % i == 0)
        {
#ifdef DEBUG
            cerr << "div " << i << endl;
#endif
            a /= i;
            alpha++;
        }
        res *= 1 + alpha;
    }

    if(a > 1)
    {
        long long count = countDiv(a);
#ifdef DEBUG
        cerr << "a=" << a << endl;
        cerr << "count=" << count << endl;
#endif
        if(count == 4)
        {
#ifdef DEBUG
            cerr << "count = 4" << endl;
#endif
            res *= 4;
        }
        else if(count == 3 || count == 2)
        {
#ifdef DEBUG
            cerr << "count in {2, 3}" << endl;
#endif
            for(long long i = 0; i < N; i++)
                if((a % arr[i]) == 0 && arr[i] != 1)
                {
                    if(a == arr[i])
                        res *= 2;
                    else
                    {
                        if(a / arr[i] == arr[i])
                            res *= 3;
                        else
                            res *= 4;
                    }
                    break;
                }
        }
        else
        {
#ifdef DEBUG
            cerr << "count not in {2, 3, 4}" << endl;
#endif
            cout << "no" << endl;
            exit(0);
        }
    }
    return(res);
}

int main()
{
    scanf("%lld", &N);

    long long i;
    for(i = 0; i < N; i++)
        scanf("%lld", arr + i);

    if(N == 1)
    {
        cout << (arr[0] == 1 ? "yes" : "no") << endl;
        return 0;
    }

    // N > 1

#ifdef DEBUG
    dumpArr();
#endif
    sort(arr, arr + N, llcmp);
#ifdef DEBUG
    dumpArr();
#endif

    T = arr[N - 1];

#ifdef DEBUG
    cerr << "T=" << T << endl;
#endif

    if(divisorsN(T) != N)
    {
#ifdef DEBUG
        cerr << "divisorsN" << endl;
#endif
        cout << "no" << endl;
        return 0;
    }

#ifdef DEBUG
    cerr << "testdiv" << endl;
#endif
    cout << (testDiv() ? "yes" : "no") << endl;

    return(0);
}
