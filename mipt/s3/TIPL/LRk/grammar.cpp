#include "grammar.h"
#include <sstream>
#include "common.h"
#include <iostream>
#include <vector>
#include <map>
#include <assert.h>

using std::stringstream;
using std::endl;
using std::set;
using std::map;
using std::string;
using std::vector;

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

void Grammar::calcFirst()
{
    //F.clear();
    map< string, set<string> > Fprev;

    set<char>::iterator it;
    for(it = terminals.begin(); it != terminals.end(); it++)
    {
        Fprev[stringFromChar(*it)].insert(stringFromChar(*it));
    }

    vector<Rule>::iterator rit;
    for(rit = rules.begin(); rit != rules.end(); rit++)
    {
        if(!isTerminal((*rit).L) && (*rit).R.length() == 0)
        {
            Fprev[(*rit).L].insert("");
        }
    }

    string::iterator sit;

    while(true)
    {
        F = Fprev;
        for(rit = rules.begin(); rit != rules.end(); rit++)
        {
            Rule cRule = *rit;
            set<string> addFR;
            for(sit = cRule.R.begin(); sit != cRule.R.end(); sit++)
            {
                set<string> addF = Fprev[stringFromChar(*sit)];

                if(sit == cRule.R.begin())
                    addFR = addF;
                else
                {
                    set<string> addFRold = addFR;
                    addFR = firstAppend(addFRold, addF);
                }
            }
            F[cRule.L].insert(addFR.begin(), addFR.end());
        }
        if(F == Fprev) break;
        else Fprev = F;
    }
}

set<string> Grammar::firstAppend(set<string> xParse, set<string> yParse)
{
    set<string>::iterator sit1, sit2;
    set<string> res;
    for(sit1 = xParse.begin(); sit1 != xParse.end(); sit1++)
        for(sit2 = yParse.begin(); sit2 != yParse.end(); sit2++)
        {
            res.insert(((*sit1) + (*sit2)).substr(0, k));
        }
    return(res);
}

set<string> Grammar::firstAppend(string xParse, string yPlain)
{
    set<string> res;
    string::iterator it;
    set<string>::iterator sit;
    for(it = xParse.begin(); it != xParse.end(); it++)
    {
        set<string> currentF = F[stringFromChar(*it)];
        for(sit = currentF.begin(); sit != currentF.end(); sit++)
            res.insert(((*sit) + yPlain).substr(0, k));
    }
    return(res);
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

    ss << "First:" << endl;
    map<string, set<string> >::iterator mit;
    set<string>::iterator ssit;
    for(mit = F.begin(); mit != F.end(); mit++)
    {
        ss << (*mit).first << " ";
        for(ssit = (*mit).second.begin(); ssit != (*mit).second.end(); ssit++)
        {
            ss << "[" << (*ssit);
            if(!(*ssit).length())
                ss << EPS;
            ss << "] ";
        }
        ss << endl;
    }

    return(ss.str());
}

Grammar::Grammar()
{
    rules.clear();
}

Grammar::Grammar(istream &s, unsigned int _k)
{
    read(s);
    fillSymbols();
    S = "S";
    k = _k;
    calcFirst();
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

set<string> Grammar::first(string A)
{
    return(firstAppend(A, ""));
}
