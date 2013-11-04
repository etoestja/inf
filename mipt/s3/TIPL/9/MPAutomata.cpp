#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using std::string;
using std::vector;
using std::stringstream;
using std::ifstream;
using std::endl;
using std::cout;
using std::cin;

#define DEBUG_PROGRESS
#define DEBUG_OUTPUT
//#define DEBUG_DEBUG

class state
{
public:
    string input;
    string stack;
    string state;
};

enum _ACCEPT {ACCEPT_FINALSTATE, ACCEPT_EMPTYSTACK};
int acceptType = ACCEPT_FINALSTATE;

vector<string> finalStates;

class rule
{
public:
    string oldState;
    string newState;
    string symbol;
    string stackSymbol;
    string stackRepl;
};

vector<rule> delta;

string input;
string stack;
string state;

bool accepted;

string rulePrint(rule);

bool ruleApplyable(rule r)
{
    if(stack.length() == 0)
        return(false);
    if(state.compare(r.oldState) != 0)
        return(false);
    if(stack[0] != r.stackSymbol[0])
        return(false);
    if(!(r.symbol.length() == 0 || (input[0] == r.symbol[0])))
    {
//        cout << "LF" << rulePrint(r) << endl;
        return(false);
    }
    return(true);
}

void ruleApply(rule r)
{
    if(input.length() > 0)
        input = input.substr(r.symbol.length());
    state = r.newState;
    if(stack.length() > 0)
        stack = r.stackRepl + stack.substr(1);
}

string rulePrint(rule r)
{
    stringstream ss;
    ss << "[" << r.oldState << "->" << r.newState << ", " << r.stackSymbol << "=>" << r.stackRepl << "]";
    return(ss.str());
}

bool tryRules()
{
    vector<rule>::iterator it;
    int applyable = 0;
    bool res = true;
    rule firstApplyable;
    vector<rule> applyableRules;
    for(it = delta.begin(); it != delta.end(); it++)
        if(ruleApplyable(*it))
        {
            applyable++;
            if(applyable == 1)
                firstApplyable = *it;
            applyableRules.push_back(*it);
        }
#ifdef DEBUG_DEBUG
        else
        {
            cout << " can't apply " << rulePrint(*it) << endl;
        }
#endif
#ifdef DEBUG_PROGRESS
    cout << "state: [" << state << "]\t[" << input << "]" << "\t[" << stack << "]\t";
#endif
    if(acceptType == ACCEPT_EMPTYSTACK)
    {
        if(stack.length() == 0)
        {
            if(input.length() != 0)
            {
#ifdef DEBUG_PROGRESS
                cout << "BROKEN" << endl;
#endif
                return(false);
            }
            accepted = true;
#ifdef DEBUG_PROGRESS
            cout << "ACCEPTING" << endl;
#endif
            return(false);
        }
    }
    else if(acceptType == ACCEPT_FINALSTATE)
    {
        if(input.length() == 0)
        {
            vector<string>::iterator it;
            for(it = finalStates.begin(); it != finalStates.end(); it++)
                if(!(*it).compare(state))
                {
#ifdef DEBUG_PROGRESS
                    cout << "ACCEPTING" << endl;
#endif
                    accepted = true;
                    return(false);
                }
        }
    }

    if(applyable == 0)
    {
#ifdef DEBUG_PROGRESS
        cout << "can't apply any rule...";
#endif
        res = false;
    }
    else if(applyable > 1)
    {
#ifdef DEBUG_PROGRESS
        cout << "can apply more than one rule!" << endl;
        for(int i = 0; i < applyableRules.size(); i++)
            cout << i << ": " << rulePrint(applyableRules[i]) << endl;
#endif
    }
    if(applyable >= 1)
    {
        ruleApply(firstApplyable);
#ifdef DEBUG_PROGRESS
        cout << "applying rule " << rulePrint(firstApplyable);
#endif
    }
#ifdef DEBUG_PROGRESS
    cout << endl;
#endif
    return(res);
}

void inputA()
{
    ifstream file("task1A0");
    int N;
    file >> N;
    string s;
    for(int i = 0; i < N; i++)
    {
        file >> s;
        finalStates.push_back(s);
    }
    file >> state;
    file >> stack;
    cin >> input;
    file >> N;
    rule tR;
    for(int i = 0; i < N; i++)
    {
        file >> tR.oldState >> tR.newState >> tR.symbol >> tR.stackSymbol >> tR.stackRepl;
        if(tR.symbol.compare("eps") == 0)
            tR.symbol = "";
        if(tR.stackRepl.compare("eps") == 0)
            tR.stackRepl = "";
        delta.push_back(tR);
    }
    cout << N << endl << endl;
}

void loop()
{
    accepted = false;
    for(; tryRules(); );
#ifdef DEBUG_OUTPUT
    cout << (accepted ? "ACCEPTED" : "REJECTED") << endl;
#endif
}

int main()
{
    inputA();
    loop();
    return(0);
}
