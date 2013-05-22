#include <iostream>

using namespace std;

#define N 30000
int isprime[N];

int main()
{
    for(int i = 0; i < N; i++) isprime[i] = true;
    
    for(int i = 0; i < N; i++)
    {
        if(isprime[i])
        {
            for(int j = i * i; j < N; j += i) isprime[j] = 
        }
    }
    
    cout << "Hello world!" << endl;
    return 0;
}
