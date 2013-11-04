#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;
using std::set;
using std::next_permutation;

class rule
{
public:
    string q1;
    string q2;
    string input;
    char X;
    string Y;
};

vector<rule> rules;
set<string> states;
string initial;
vector<string> Galph;

int N, G;

vector< vector<string> > states2;

void getStates(int n, int c = 0, vector<string> prev = vector<string>(0))
{
    if(c == 0)
        states2.clear();
    if(n == 0)
    {
        states2.push_back(prev);
        return;
    }
    set<string>::iterator sit;
    for(sit = states.begin(); sit != states.end(); sit++)
    {
        vector<string> current = prev;
        current.resize(prev.size() + 1);
        current[c] = *sit;
        getStates(n - 1, c + 1, current);
    }
}

int main()
{
    cin >> initial;

    cin >> G;
    string g;
    for(int i = 0; i < G; i++)
    {
        cin >> g;
        Galph.push_back(g);
    }

    cin >> N;
    rule t;
    for(int i = 0; i < N; i++)
    {
        cin >> t.q1 >> t.q2 >> t.input >> t.X >> t.Y;
        if(!t.Y.compare("eps"))
            t.Y = "";
        if(!t.input.compare("eps"))
            t.input = "";
        rules.push_back(t);

    }

    vector<rule>::iterator it;
    for(it = rules.begin(); it != rules.end(); it++)
    {
        states.insert((*it).q1);
        states.insert((*it).q2);
    }

    set<string>::iterator sit;
    vector<string>::iterator git;
    for(sit = states.begin(); sit != states.end(); sit++)
    {
        for(git = Galph.begin(); git != Galph.end(); git++)
        {
            cout << "S->[" << initial << *git << *sit << "]" << endl;
        }
    }
    cout << endl;

/*    getStates(5);
    vector< vector<string> >::iterator ssit;
    for(ssit = states2.begin(); ssit != states2.end(); ssit++)
    {
        for(git = (*ssit).begin(); git != (*ssit).end(); git++)
        {
            cout << *git;
        }
        cout << endl;
    }*/

    for(it = rules.begin(); it != rules.end(); it++)
    {
        getStates((*it).Y.length());
        
        int i;
        vector< vector<string> >::iterator ssit;
        for(i = 0, ssit = states2.begin(); ssit != states2.end(); ssit++, i++)
        {
            cout << "[" << (*it).q1 << (*it).X << (*ssit)[(*ssit).size() - 1] << "]->" << (*it).input;
            for(git = (*ssit).begin(); git != (*ssit).end(); git++)
            {
                cout << "[";
                if(i == 0)
                    cout << (*it).q2;
                else
                    cout << (*ssit)[i - 1];
                cout << *git;
                cout << (*it).Y[i];
                cout << "]";
            }
            cout << endl;
        }
    }

    return(0);
}
