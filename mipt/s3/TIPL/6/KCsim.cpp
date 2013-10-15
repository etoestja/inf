#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//#undef DEBUG
#define DEBUG
//#define OUTPUT_TEX
//#define OUTPUT_NORMAL
//#define OUTPUT_TEXRULES


typedef pair< string, string > rule;
vector<rule> rules;

string printRule(int i, rule a)
{
    stringstream ss;
    ss << "[" << a.first << "] =(" << i << ")=> " << "[" << a.second << "]";
    return(ss.str());
}

void printRulesTex()
{
    rule a;
    for(int i = 0; i < rules.size(); i++)
    {
        a = rules[i];
        if(a.second.length() == 0)
            a.second = "\\varepsilon";
        cout << "\\item $" << a.first << " \\longrightarrow " << a.second << "$" << endl;
    }
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
#ifdef DEBUG
        cout << " Found occurence at " << pos1 << " and " << pos2 << "!" << endl;
#endif
        return(-1);
    }
    int pos = pos1;
#ifdef OUTPUT_PLAIN
    cout << current.substr(0, pos) << "[" << r.first << "]" << current.substr(pos + r.first.length()) << " =(" << p + 1 << ")=> ";
#endif
#ifdef OUTPUT_TEX
    cout << current.substr(0, pos) << "\\underline{" << r.first << "}" << current.substr(pos + r.first.length()) << " \\overset{(" << p + 1 << ")}{\\Longrightarrow}";
#endif
    string res = current.replace(pos, r.first.length(), r.second);
#ifdef DEBUG
    cout << " RTO [" << res << "]" << endl;
#endif
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
#ifdef DEBUG
                cout << "ERROR: can apply to [" << current << "] both " << p << " and " << i << endl;
                cout << " " << printRule(p, rules[p]) << endl;
                cout << " " << printRule(i, rules[i]) << endl;
#endif
                return(-2);
            }
        }
    }
    if(p != -1)
    {
#ifdef DEBUG
        cout << "Applying rule " << printRule(p, rules[p]) << endl;
#endif
        if(applyRule(p) != 0) return(-1);
        return(0);
    }
    else
    {
#ifdef DEBUG
        cout << "Can't apply to [" << current << "] anything..." << endl;
#endif
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
#ifdef OUTPUT_TEXRULES
    printRulesTex();
#endif
    applyLoop();
#ifdef OUTPUT_TEX
    cout << current << endl;
#endif
#ifdef OUTPUT_PLAIN
    cout << current << endl;
#endif
}
