#ifndef SET_H
#define SET_H

#include "situation.h"
#include <set>

using std::set;

class Analyzer;

class SituationSet
{
    friend class Analyzer;
private:
    set<Situation, Situation> situations;
public:
    SituationSet();
    void add(Situation s);
    void add(SituationSet ss);
};

#endif // SET_H
