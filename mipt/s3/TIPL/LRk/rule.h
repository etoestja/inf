#ifndef RULE_H
#define RULE_H

#include <string>
#include <istream>

using std::string;
using std::istream;

const string EPS = "eps";

class Grammar;
class Analyzer;
class Situation;
class SituationSet;

class Rule
{
    friend class Grammar;
    friend class Analyzer;
    friend class Situation;
    friend class SituationSet;
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
    bool operator==(const Rule& a) const;
};

#endif // RULE_H
