#include <iostream>
#include <vector>
#include <set>

using std::set;

using std::vector;

using std::cout;
using std::endl;

int f(int a, int b, int k)
{
    return(((a * k + b) % 8) % 5);
}

vector<int> Zns;
vector<int> Zn;

int n1 = 8;
int n2 = 5;

int main()
{
    Zns.push_back(1);
    Zns.push_back(2);
    Zns.push_back(4);
    Zns.push_back(5);
    Zns.push_back(7);
    Zns.push_back(8);

    for(int i = 0; i < 9; i++)
        Zn.push_back(i);

    vector<int>::iterator a;
    vector<int>::iterator b;

    vector<int> v;
    set< vector<int> > s;

    for(a = Zns.begin(); a != Zns.end(); a++)
    {
        for(b = Zn.begin(); b != Zn.end(); b++)
        {
            cout << (*a) << "\t" << (*b) << "\t";
            v.clear();
            for(int k = 0; k < n1; k++)
            {
                cout << f(*a, *b, k) << " ";
                v.push_back(f(*a, *b, k));
            }
            if(s.find(v) != s.end())
                cout << " <====";
            s.insert(v);
            cout << endl;
        }
        cout << endl;
    }

    cout << s.size() << endl;
}
