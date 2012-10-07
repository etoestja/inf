#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::string;

string x;

int get_opener(int pos)
{
    cerr << "x=" << x << " requested opener before " << pos << ": " << x.rfind('(', pos) << endl;
    return(x.rfind('(', pos));
}

int get_closer(int pos)
{
    cerr << "x=" << x << " requested closer after " << pos << ": " << x.find(')', pos) << endl;
    return(x.find(')', pos));
}

int main()
{
    cin >> x;

    int opener_pos, closer_pos;

    for(closer_pos = get_closer(0); closer_pos != -1; closer_pos = get_closer(0))
    {
        opener_pos = get_opener(closer_pos);
        if(opener_pos != -1)
        {
            x[opener_pos] = 'X';
            x[closer_pos] = 'X';
        }

        cerr << x << endl;

        if(opener_pos == -1) break;
    }

    opener_pos = get_opener(-1);
    closer_pos = get_closer(0);

    cout << ((opener_pos == -1 && closer_pos == -1) ? "YES" : "NO") << endl;

    return 0;
}
