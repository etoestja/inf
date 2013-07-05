#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// no plan, no backup...

void read();
void solve();
void write();

unsigned int N, K;
unsigned int result;

void read()
{
    cin >> K >> N;
}

void solve()
{
    result = N % K;
}

void write()
{
    cout << result << endl;
}

int main()
{
    read();
    solve();
    write();

    return 0;
}
