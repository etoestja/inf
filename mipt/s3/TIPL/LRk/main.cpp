#include <iostream>
#include "grammar.h"
#include "analyzer.h"
#include <set>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::string;

int main()
{
    //cout << "Hello World!" << endl;
    Grammar G(cin, 2);
    cout << G.print();
    set<string>::iterator it;
    set<string> s = G.first("SS");
    for(it = s.begin(); it != s.end(); it++)
        cout << "[" << (*it) << "] ";
    cout << endl;

    Analyzer A(G);
    cout << A.print() << endl;
    return 0;
}

