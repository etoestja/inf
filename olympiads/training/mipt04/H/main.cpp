#include <iostream>
#include <string>
using namespace std;

string s;
//string ans;
int ans[100000];
int a[100000];
int main()
{
    int n;
    cin >> n;
    cin >> s;
    int k = s.length();
    int i = k;
    while (s[i-1] == '=')
    {
        a[i] = 0;
        i--;
    }
    for (; i>=0; i--)
    {
        if (s[i-1] == '>')
            a[i] = -1;
        else if (s[i-1] == '<')
            a[i] = 1;
        else
            a[i] = a[i+1];
    }

    /*for (int i = 0; i <=k; i++)
        cout << a[i] << endl;
*/
    if (a[0] == 1)
        ans[0] = 1;
    else
    {
        ans[0] = n;
    }

    for (int i = 0; i < k; i++)
    {
        if (s[i] == '=')
            ans[i+1] = ans[i];
        else if ((a[i+2] != a[i+1]) && (a[i+2] != 0))
        {
            if ((a[i+2] == 1) && (ans[i] != 1))
                ans[i+1]=1;
            else if (ans[i] != n)
                ans[i+1]=n;
        }
        else
        {
            if (a[i+1] == 1)
                ans[i+1]=ans[i]+1;
            else
                ans[i+1]=ans[i]-1;
        }
        if ((ans[i+1]<1) || (ans[i+1] > n))
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i <=k; i++)
        cout << (char) ((int) 'a' + ans[i] - 1);
    cout << endl;
    return 0;
}

