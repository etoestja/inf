#ifndef SITUATION_H
#define SITUATION_H

#include <string>
#include "rule.h"

class SituationSet;
class Analyzer;

using std::string;

class Situation
{
    friend class SituationSet;
    friend class Analyzer;
private:
    Rule rule;
    unsigned int pos;
    string match;
public:
    Situation(Rule _rule, unsigned int _pos);
    Situation();
    void incPos();
    bool operator()(const Situation &a, const Situation& b) const;
    bool operator=(const Situation &a);
    bool equal(Situation a) const;
    char currentSymbol() const;
    string print() const;
    bool operator<(const Situation &a) const;
};

#endif // SITUATION_H
