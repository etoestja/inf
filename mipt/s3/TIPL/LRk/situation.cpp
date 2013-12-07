#include "situation.h"

situation::situation(Rule *_rule, unsigned int _pos)
{
    rule = _rule;
    pos = _pos;
}

void situation::incPos()
{
    pos++;
}
