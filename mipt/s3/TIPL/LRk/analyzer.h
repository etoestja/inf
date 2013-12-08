#ifndef ANALYZER_H
#define ANALYZER_H

#include "grammar.h"
#include "situation_set.h"

class Analyzer
{
private:
    Grammar G;
    SituationSet states;

    void calcStates();
    SituationSet closure(SituationSet s);

public:
    Analyzer();
    Analyzer(Grammar G);
};

#endif // ANALYZER_H
