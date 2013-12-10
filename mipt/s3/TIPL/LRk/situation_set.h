#ifndef SET_H
#define SET_H

#include "situation.h"
#include <set>
#include <string>

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
    bool operator==(SituationSet& a) const;
    string print() const;
    bool operator()(const SituationSet &a, const SituationSet &b) const;
};

#endif // SET_H
