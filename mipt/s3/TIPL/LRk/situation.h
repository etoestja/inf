#ifndef SITUATION_H
#define SITUATION_H

#include <string>
#include "rule.h"

class situation
{
private:
    Rule* rule;
    unsigned int pos;
public:
    situation(Rule* _rule, unsigned int _pos);
    void incPos();
};

#endif // SITUATION_H
