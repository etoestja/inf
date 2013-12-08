#include "situation_set.h"

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
