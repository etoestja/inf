#include "grammar.h"
#include <sstream>
#include <iostream>
#include <assert.h>

using std::stringstream;
using std::endl;

bool Grammar::isTerminal(char c)
{
    assert(endSymbol.length() == 1);
    return((c >= 'a' && c <= 'z') || c == endSymbol[0]);
}

bool Grammar::isTerminal(string c)
{
    assert(c.length() == 1);
    return(isTerminal(c[0]));
}

void Grammar::fillSymbols()
{
    vector<Rule>::iterator it;
    string::iterator sit;
    for(it = rules.begin(); it != rules.end(); it++)
    {
        assert((*it).L.length() == 1);
        for(sit = (*it).L.begin(); sit != (*it).L.end(); sit++)
            if(isTerminal(*sit))
                terminals.insert(*sit);
            else
                nonTerminals.insert(*sit);
        for(sit = (*it).R.begin(); sit != (*it).R.end(); sit++)
            if(isTerminal(*sit))
                terminals.insert(*sit);
            else
                nonTerminals.insert(*sit);
    }
}

string Grammar::print()
{
    stringstream ss;

    ss << "Terminals: ";

    set<char>::iterator sit;
    for(sit = terminals.begin(); sit != terminals.end(); sit++)
        ss << (*sit) << " ";

    ss << endl;

    ss << "Non-terminals: ";
    for(sit = nonTerminals.begin(); sit != nonTerminals.end(); sit++)
        ss << (*sit) << " ";
    ss << endl;

    ss << "Rules:" << endl;
    vector<Rule>::iterator it;
    for(it = rules.begin(); it != rules.end(); it++)
        ss << (*it).print() << endl;
    return(ss.str());
}

Grammar::Grammar()
{
    rules.clear();
}

Grammar::Grammar(istream &s)
{
    read(s);
    fillSymbols();
    S = "S";
}

void Grammar::read(istream &s)
{
    unsigned int i, N;
    s >> N;
    s >> S;
    s >> endSymbol;
    Rule tRule;
    for(i = 0; i < N; i++)
    {
        tRule.read(s);
        rules.push_back(tRule);
    }
    fillSymbols();
}
