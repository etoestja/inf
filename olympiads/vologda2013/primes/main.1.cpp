#include <iostream>

using namespace std;

#define N 30000
int isprime[N];

int main()
{
    for(int i = 0; i < N; i++) isprime[i] = true;

    for(int i = 2; i < N; i++)
    {
        if(isprime[i])
        {
            for(int j = i * i; j < N; j += i) isprime[j] = false;
        }
    }

    for(int i = 20000; i < 300; i++)
        if(isprime[i]) cout << i << " ";

    return 0;
}
