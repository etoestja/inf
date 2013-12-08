#include <iostream>
#include "grammar.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    //cout << "Hello World!" << endl;
    Grammar G(cin, 2);
    cout << G.print();
    return 0;
}

