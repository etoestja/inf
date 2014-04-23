#include <set>
#include <iostream>

using std::cout;
using std::endl;

using std::set;

#define p 23

int pow1(int a, int n)
{
    if(n == 0) return(1 % p);
    else if(n % 2 == 0)
    {
        int m = pow1(a, n / 2);
        return((m * m) % p);
    }
    else return((a * pow1(a, n - 1)) % p);
}

int isR(int t)
{
    int i;
    set<int> s;
    for(i = 1; i <= p; i++)
    {
        s.insert(pow1(t, i) % p);
    }

    return(s.size() == p - 1);
}

int main()
{
    int i;
    for(i = 1; i < p; i++)
    {
        if(isR(i))
            cout << i << endl;
    }

    return(0);
}
