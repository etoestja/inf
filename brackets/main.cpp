#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    char x;

    int counter = 0;

    while((x = cin.get()) && (x == '(' || x == ')'))
    {
        if(x == '(') counter++;
        else
        {
            if(counter > 0) counter--;
            else
            {
                counter = 1;
                break;
            }
        }
    }

    cout << (counter ? "NO" : "YES") << endl;

    return 0;
}
