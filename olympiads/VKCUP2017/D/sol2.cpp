#include <iostream>
using namespace std;

int a[100010];

int count_bit(int x)
{
    int ans = 0;
    while (x > 0)
    {
        x &= x - 1;
        ans++;
    }

    return ans;
}

char interest(int a, int b, int k)
{
    return count_bit(a ^ b) == k;
}

int broot_forse(int N, int k)
{
    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            ans += interest(a[i], a[j], k);
    return(ans);
}

int main()
{
    int N, k;

    cin >> N >> k;
    for (int i = 0; i < N; i++)
        cin >> a[i];

    cout << broot_forse(N, k) << endl;

    return 0;

}
