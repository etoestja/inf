#include <iostream>

using namespace std;

int main()
{
    long long res = 1, i;
    for(i = 1; res < 1E17; res *= i, i++)
    {
        cout << i << " ";
    }
    cout << endl;
    return(0);
}
