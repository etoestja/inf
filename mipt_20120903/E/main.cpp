#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

// no plan, no backup...

void read();
void solve();
void write();

unsigned int N;
vector<int> data_now;
int avg;

void read()
{
    int t;
    cin >> N;
    for(unsigned int i = 0; i < N; i++)
    {
        cin >> t;
        data_now.push_back(t);
    }
}

void solve()
{
    avg = 0;

    for(unsigned int i = 0; i < N; i++)
    {
        avg += data_now[i];
    }

    avg /= N;
}

void write()
{
    for(unsigned int i = 0; i < N; i++)
    {
        cout << avg - data_now[i];
        if(i != N - 1) cout << " ";
    }

    cout << endl;
}

int main()
{
    read();
    solve();
    write();

    return 0;
}
