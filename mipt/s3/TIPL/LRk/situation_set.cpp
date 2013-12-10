#include "situation_set.h"
#include <sstream>

using std::endl;
using std::stringstream;

SituationSet::SituationSet()
{
}

void SituationSet::add(Situation s)
{
    situations.insert(s);
}

void SituationSet::add(SituationSet ss)
{
    situations.insert(ss.situations.begin(), ss.situations.end());
}

bool SituationSet::operator==(SituationSet &a) const
{
    set<Situation>::iterator it1, it2;
    for(it1 = situations.begin(), it2 = a.situations.begin(); it1 != situations.end() && it2 != a.situations.end(); it1++, it2++)
        if(!((*it1).equal(*it2)))
            return(false);
    if(it1 != situations.end() || it2 != a.situations.end())
        return(false);
    return(true);
}

string SituationSet::print() const
{
    stringstream ss;

    set<Situation>::iterator it;
    for(it = situations.begin(); it != situations.end(); it++)
        ss << (*it).print() << endl;

    return(ss.str());
}

bool SituationSet::operator ()(const SituationSet &a, const SituationSet &b) const
{
    return(a.situations < b.situations);
}
