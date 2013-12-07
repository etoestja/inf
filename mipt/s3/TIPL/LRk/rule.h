#ifndef RULE_H
#define RULE_H

#include <string>
#include <istream>

using std::string;
using std::istream;

const string EPS = "eps";

class Grammar;

class Rule
{
    friend class Grammar;
private:
    string L;
    string R;

public:
    Rule(string tL, string tR);
    Rule();
    Rule(istream &s);
    string print();
    void read(istream &s);
    string& getL();
    string& getR();
};

#endif // RULE_H
