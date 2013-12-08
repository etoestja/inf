#ifndef SITUATION_H
#define SITUATION_H

#include <string>
#include "rule.h"

class SituationSet;

class Situation
{
    friend class SituationSet;
private:
    Rule* rule;
    unsigned int pos;
public:
    Situation(Rule* _rule, unsigned int _pos);
    Situation();
    void incPos();
    bool operator()(const Situation &a, const Situation& b) const;
    bool operator=(const Situation &a);
};

#endif // SITUATION_H
