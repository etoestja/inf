#include "analyzer.h"
#include "rule.h"
#include "common.h"
#include <sstream>
#include <iostream>

using std::endl;
using std::stringstream;
using std::cerr;

void Analyzer::calcStates()
{
    Rule fRule;
    vector<Rule>::iterator it;
    for(it = G.rules.begin(); it != G.rules.end(); it++)
    {
        if(!(*it).L.compare(G.S))
        {
            fRule = *it;
            break;
        }
    }

    Situation tS(fRule, 0);
    tS.match = "";
    SituationSet tSet;
    tSet.add(tS);

    cerr << "TSET=" << tSet.print() << endl;

    states.insert(closure(tSet));
}

SituationSet Analyzer::closure(SituationSet s)
{
    SituationSet res = s, prev;

    set<Situation>::iterator it;
    vector<Rule>::iterator rit;

    Situation tS;

    set<string>::iterator ssit;
    set<string> tSSet;

    char c;

    while(true)
    {
        prev = res;

        for(it = res.situations.begin(); it != res.situations.end(); it++)
        {
            c = (*it).currentSymbol();
            cerr << "c=[" << c << "]" << endl;
            if(c != '\0' && !G.isTerminal(c))
            {
                for(rit = G.rules.begin(); rit != G.rules.end(); rit++)
                {
                    if(!(*rit).L.compare(stringFromChar(c)))
                    {
                        cerr << "found rule " << (*rit).print() << endl;
                        tS.rule = *rit;
                        tS.pos = 0;
                        //if(tS.pos >= (*rit).R.length())
                        //    continue;
                        //if((*it).pos + 1 >= (*it).rule.R.length())
                        //    continue;
                        tSSet = G.first((*it).rule.R.substr((*it).pos + 1).append((*it).match));
                        for(ssit = tSSet.begin(); ssit != tSSet.end(); ssit++)
                        {
                            tS.match = *ssit;
                            res.situations.insert(tS);
                            cerr << "CLOSURE:adding " << tS.print() << endl;
                        }
                    }
                }
            }
        }

        if(prev == res)
            break;
    }

    return(res);
}

Analyzer::Analyzer()
{
}

Analyzer::Analyzer(Grammar _G)
{
    G = _G;
    calcStates();
}

string Analyzer::print()
{
    stringstream ss;
    ss << "Sets:" << endl;
    set<SituationSet>::iterator it;

    for(it = states.begin(); it != states.end(); it++)
        ss << "{" << endl << (*it).print() << endl << "}" << endl;
    return(ss.str());
}
