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

int H = 45;
int M = n2;

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

    for(int k = 0; k < n1; k++)
        for(int l = k + 1; l < n1; l++)
        {
            int sum = 0;
            s.clear();
            for(a = Zns.begin(); a != Zns.end(); a++)
            {
                for(b = Zn.begin(); b != Zn.end(); b++)
                {
                    v.clear();
                    for(int tk = 0; tk < n1; tk++)
                    {
                        v.push_back(f(*a, *b, tk));
                    }

                    if(s.find(v) == s.end() && f(*a, *b, k) == f(*a, *b, l)) sum++;

                    s.insert(v);
                }
            }
            if(sum * M > H)
                cout << "non-uni k=" << k << " l=" << l << " sum=" << sum << endl;
        }
}
