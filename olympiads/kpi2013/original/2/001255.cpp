#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define maxopt 1000000
long long v[200001];
bool optimize[maxopt];
long long MaxV;
int N;

int f(long long a)
{
    long long a0 = a;
    int ans = 1;
    int i = 2;
    long long r = sqrt(a)+1;
    while (i <= r)
    {
        int alpha = 1;
        while (a % i == 0)
        {
            if (!optimize[i])
            {
                cout << "no";
                exit(0);
            }
            a/=i;
            alpha++;
        }
        ans*=alpha;
        if (ans > N)
            return ans;
        i++;
    }
    if (a > 1)
        ans*=2;

    return ans;
}

int main() {
    cin >> N;
    MaxV = -1;
    for (int i = 0; i < maxopt; i++)
        optimize[i] = false;

    for (int i = 0 ; i < N; i++)
    {
        cin >> v[i];
        if (v[i] < maxopt)
            optimize[v[i]] = true;
        if (v[i] > MaxV)
            MaxV = v[i];
    }

    int TeorNum = f(MaxV);
//    cout << MaxV << endl;
//    cout << "Teornum: " << TeorNum << endl;
    if (TeorNum != N)
    {
        cout << "no";
        return 0;
    }
    bool ans = true;
    for (int i = 0; i < N; i++)
        ans &= (MaxV % v[i] == 0);
    if (ans)
        cout << "yes";
    else
        cout << "no";
	return 0;

}
