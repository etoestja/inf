#include <iostream>

using namespace std;

long long n, k;

int main()
{
    cin >> n >> k;

    long long a;

    long long unused = 0, surv = 0;

    for(unsigned i = 0; i < n; i++)
    {
        cin >> a;

        unused += max(0LL, a - k);
        surv += max(k-a, 0LL);
    }

    cout << unused << " " << surv << endl;

    return 0;
}

