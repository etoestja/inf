#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// no plan, no backup...

void read();
void solve();
void write();

unsigned int N;
int answer;
bool answer_isset = false;

void read()
{
    cin >> N;
}

void solve()
{
    int t;
    for(unsigned int i = 0; i < N; i++)
    {
        cin >> t;
        if(!answer_isset || t > answer)
        {
            answer = t;
            answer_isset = true;
        }
    }
}

void write()
{
    cout << answer << endl;
}

int main()
{
    read();
    solve();
    write();

    return 0;
}
