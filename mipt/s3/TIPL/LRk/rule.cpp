#include "rule.h"
#include <sstream>

using std::stringstream;

Rule::Rule()
{
    L = "";
    R = "";
}

Rule::Rule(istream &s)
{
    read(s);
}

string Rule::print()
{
    stringstream ss;
    ss << "[" << L << "]->[" << (R.length() ? R : EPS) << "]";
    return(ss.str());
}

void Rule::read(istream &s)
{
    s >> L;
    s >> R;
    if(!R.compare(EPS))
        R = "";
}


Rule::Rule(string tL, string tR)
{
    L = tL;
    R = tR;
}
