#include <iostream>
#include <string>
#include <map>
#include <stdio.h>

#define FILENAME "/home/user/MyDocs/.documents/notes/Debts.txt"

using std::cout;
using std::endl;

using std::string;
using std::map;

map<string, int> m;

int main(int argc, char** argv)
{
    freopen(FILENAME, "r", stdin);
    char ss[500];
    string s = "~";
    int i;

    if(argc == 2)
        cout << "=== Log ===" << endl;

    scanf("%s", ss);

    while(scanf("%d %s", &i, ss) == 2)
    {
        s = ss;
        if(m.find(s) != m.end())
            m[s] += i;
        else m[s] = i;
        if(argc == 2) cout << s << " " << i << endl;
    }

    map<string, int>::iterator it;

    if(argc == 2) cout << "=== Sum ===" << endl;

    int total = 0;

    for(it = m.begin(); it != m.end(); it++)
        if((*it).second)
        {
            total += (*it).second;
            cout << (*it).first << " " << (*it).second << endl;
        }

    if(argc == 2) cout << "=== Total ===" << endl << total << endl;

    return(0);
}
