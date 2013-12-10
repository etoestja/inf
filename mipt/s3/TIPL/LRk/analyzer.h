#ifndef ANALYZER_H
#define ANALYZER_H

#include "grammar.h"
#include "situation_set.h"

#include <string>

using std::string;

class Analyzer
{
private:
    Grammar G;
    set<SituationSet, SituationSet> states;

    void calcStates();
    SituationSet closure(SituationSet s);

public:
    Analyzer();
    Analyzer(Grammar _G);
    string print();
};

#endif // ANALYZER_H
