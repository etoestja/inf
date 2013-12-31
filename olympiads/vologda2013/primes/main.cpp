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

    for(int i = 20000; i < 30000; i++)
        if(isprime[i]) cout << i << " ";

    for(int i = 2; i < 29989; i++)
        if(29989 % i == 0) cout << "error " << i << endl;

    return 0;
}
