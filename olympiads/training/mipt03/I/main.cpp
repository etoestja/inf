#include <iostream>

using namespace std;

int a[10011];
int t[10011];
int sum[10011];
int k;

int newpos(int pos)
{
    int l = 0;
    int r = pos;
    int m = 0;
    while (r-l>1)
    {
        m = (r+l)/2;
        if (((m==0) && (sum[pos-1]>=k)) || ((m > 0) && (sum[pos-1] - sum[m-1] >= k)))
            l = m;
        else
            r = m;
    }
    return l;
}

int main()
{
    int pos = 0;
    int n, m;
    int time = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i==0)
            sum[i]=a[i];
        else
            sum[i] = sum[i-1]+a[i];
    }
    for (int i = 0; i < m; i++)
        cin >> t[i];
    for (int next = 0; next < m; next++)
    {
        if (n-pos<t[next]-time)
        {
            cout << time+n-pos;
            return 0;
        }
        pos+=t[next]-time-1;
        time=t[next];
        //cout << pos << " -> ";
        pos=newpos(pos);
        //cout << pos << "(" << time << ")" << endl;
    }
    cout << time+n-pos;
    return 0;
}

