#include "situation.h"

Situation::Situation(Rule *_rule, unsigned int _pos)
{
    rule = _rule;
    pos = _pos;
}

Situation::Situation()
{
}

void Situation::incPos()
{
    pos++;
}

bool Situation::operator()(const Situation &a, const Situation& b) const
{
    if(a.rule->L < b.rule->L)
        return(1);
    if(a.rule->R < b.rule->R)
        return(1);
    if(a.pos < b.pos)
        return(1);
    return(0);
}

bool Situation::operator=(const Situation &a)
{
    return(rule == a.rule && pos == a.pos);
}
