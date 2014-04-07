#include <set>
#include <string>
#include <iostream>

using std::set;
using std::string;

using std::endl;
using std::cin;
using std::cout;

set<string> s;

int main()
{
    string x;
    while(1)
    {
        cin >> x;
        if(s.find(x) == s.end())
            cout << x << endl;
        s.insert(x);
    }
    return(0);
}
