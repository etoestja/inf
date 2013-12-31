#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long v[200001];
long long MaxV;
int N;

int f(long long a)
{
    int ans = 1;
    int i = 2;
    long long r = sqrt(a)+1;
    while (i <= r)
    {
        int alpha = 1;
        while (a % i == 0)
        {
            a/=i;
            alpha++;
        }
        ans*=alpha;
        if (ans > N)
            return ans;
        i++;
    }
    if (ans == 1)
        ans++;

    return ans;
}

int main() {
    cin >> N;
    MaxV = -1;
    for (int i = 0 ; i < N; i++)
    {
        cin >> v[i];
        if (v[i] > MaxV)
            MaxV = v[i];
    }

    int TeorNum = f(MaxV);
    //cout << "Teornum: " << TeorNum << endl;
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
