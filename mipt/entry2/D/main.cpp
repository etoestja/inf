#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int sum = 0, N;
    cin >> N;

    int a = 0;

    for(int i = 0; i < N; i++)
    {
        cin >> a;
        sum += a;
    }

    cout << sum << endl;

    return(0);
}
