#include <iostream>
#include <string>

using namespace std;
bool a[100][100];
int okres[101][101] = {{-35}};
string s;

int N, k;

void Change(int &x, int &y, char c)
{
    if (c == 'R')
        x++;
    else if (c == 'L')
        x--;
    else if (c == 'U')
        y--;
    else if (c == 'D')
        y++;
}

bool CoordOK(int x, int y)
{
    return (x >= 0) && (x < N) && (y >= 0) && (y < N) && (a[x][y]);
}

bool OK(int x, int y, int k)
{
    if (okres[x][y] != -35)
            return (k <= okres[x][y]);
    int x0=x;
    int y0=y;
    bool res = CoordOK(y, x);
    for (int i = 0; i < k; i++)
    {
        if (!res)
        {
            okres[x0][y0] = i-1;
            return false;
        }
        Change(x, y, s[i]);
        res &= CoordOK(y, x);
    }
    if (res)
        okres[x0][y0] = k;
    else
        okres[x0][y0] = k-1;
    return res;
}


int KOK(int kl)
{
    int vars = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (OK(i, j, kl))
                vars++;
        }
    return vars;
}

int main() {
    cin >> N >> k;
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            okres[i][j]=-35;
    int num0 = 0;
    char c;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> c;
            //cout << c;

            a[i][j] = (c == '0');
            if (a[i][j])
                num0++;
        }
        //cout << endl;
    }
    cin >> s;
    if (num0 == 0)
    {
        cout << "-1\n";
        return 0;
    }
    if ((k == 0) && (num0 == 1))
    {
        cout << "0\n";
        return 0;
    }
    if (k == 0)
    {
        cout << "-1\n";
        return 0;
    }
    if (KOK(k) <= 0)
    {
        cout << "-1\n";
        return 0;
    }
    int l = 0;
    int r = k+1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (KOK(m) > 1)
            l = m;
        else
            r = m;
    }
    if (l == 0)
    {
        cout << "0\n";
        return 0;
    }
    if (l == k)
    {
        cout << "-1\n";
        return 0;
    }
    cout << l+1 << endl;
	return 0;
}
