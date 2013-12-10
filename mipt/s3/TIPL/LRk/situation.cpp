#include "situation.h"
#include <sstream>

using std::stringstream;

Situation::Situation(Rule _rule, unsigned int _pos)
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
    if(a.rule.L < b.rule.L)
        return(1);
    if(a.rule.R < b.rule.R)
        return(1);
    if(a.pos < b.pos)
        return(1);
    return(0);
}

bool Situation::operator=(const Situation &a)
{
    return(rule == a.rule && pos == a.pos);
}

bool Situation::equal(Situation a) const
{
    return(rule == a.rule && pos == a.pos);
}

char Situation::currentSymbol() const
{
    return(rule.R[pos]);
}

string Situation::print() const
{
    stringstream ss;
    ss << rule.L << "->" << rule.R.substr(0, pos) << "." << rule.R.substr(pos) << ", " << match;
    return(ss.str());
}

bool Situation::operator <(const Situation &a) const
{
    return(operator()(*this, a));
}
