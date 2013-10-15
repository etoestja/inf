#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

typedef pair< string, string > rule;
vector<rule> rules;

string printRule(int i, rule a)
{
    stringstream ss;
    ss << "[" << a.first << "] =(" << i << ")=> " << "[" << a.second << "]";
    return(ss.str());
}

void readRules()
{
    int N;
    cin >> N;
    rule tRule;
    rules.clear();
    for(int i = 0; i < N; i++)
    {
        cin >> tRule.first >> tRule.second;
        if(tRule.second.compare("eps") == 0)
            tRule.second = "";
        rules.push_back(tRule);
    }
}

string input;
string current;

int applyRule(int p)
{
    rule r = rules[p];
    int pos1 = current.find(r.first);
    int pos2 = current.rfind(r.first);
    if(pos1 != pos2)
    {
        cout << " Found occurence at " << pos1 << " and " << pos2 << "!" << endl;
        return(-1);
    }
    int pos = pos1;
    string res = current.replace(pos, r.first.length(), r.second);
    cout << " RTO [" << res << "]" << endl;
    current = res;
    return(0);
}

int applyRules()
{
    rule cr;
    int p = -1;
    for(int i = 0; i < rules.size(); i++)
    {
        cr = rules[i];
        if(current.find(cr.first) != string::npos)
        {
            if(p == -1)
                p = i;
            else
            {
                cout << "ERROR: can apply to [" << current << "] both " << p << " and " << i << endl;
                cout << " " << printRule(p, rules[p]) << endl;
                cout << " " << printRule(i, rules[i]) << endl;
                return(-2);
            }
        }
    }
    if(p != -1)
    {
        cout << "Applying rule " << printRule(p, rules[p]) << endl;
        if(applyRule(p) != 0) return(-1);
        return(0);
    }
    else
    {
        cout << "Can't apply to [" << current << "] anything..." << endl;
        return(1);
    }
}

void init()
{
    readRules();
    cin >> input;
    current = input;
}

void applyLoop()
{
    for(; applyRules() == 0; );
}

int main()
{
    init();
    applyLoop();
}
