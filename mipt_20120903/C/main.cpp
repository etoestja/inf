#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// no plan, no backup...

void read();
void solve();
void write();

long double N, M, K;
bool result;

void read()
{
    cin >> N >> M >> K;
}

void solve()
{
    result = K > K * M / N;
}

void write()
{
    cout << (result ? "YES" : "NO") << endl;
}

int main()
{
    read();
    solve();
    write();

    return 0;
}
