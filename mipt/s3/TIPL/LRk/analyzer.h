#ifndef ANALYZER_H
#define ANALYZER_H

#include "grammar.h"
#include "situation_set.h"

class Analyzer
{
private:
    Grammar G;
    SituationSet states;
public:
    Analyzer();
};

#endif // ANALYZER_H
