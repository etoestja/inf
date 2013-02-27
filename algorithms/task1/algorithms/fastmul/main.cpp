#include "fastmul.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    num_t a, b;

    cin >> a >> b;

    cout << fastmul(a, b) << endl;
}
