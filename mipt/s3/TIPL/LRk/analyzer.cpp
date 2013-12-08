#include "analyzer.h"

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

    Situation tS(&fRule, 0);
    SituationSet tSet;
    tSet.add(tS);

    states.add(closure(tSet));
}

SituationSet Analyzer::closure(SituationSet s)
{
    SituationSet res = s, prev;

    while(true)
    {
        prev = res;

        if(prev.situations == res.situations)
            break;
    }

    return(res);
}

Analyzer::Analyzer()
{
}

Analyzer::Analyzer(Grammar G)
{

}
