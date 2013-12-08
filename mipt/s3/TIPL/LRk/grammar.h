#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>
#include <string>
#include <set>
#include <map>
#include "rule.h"

using std::string;
using std::vector;
using std::set;
using std::map;

class Analyzer;

class Grammar
{
    friend class Analyzer;
private:
    unsigned int k;
    string S;
    string endSymbol;

    set<char> terminals;
    set<char> nonTerminals;

    map< string, set<string> > F;

    vector<Rule> rules;
    bool isTerminal(char c);
    bool isTerminal(string c);
    void fillSymbols();

    void calcFirst();

    set<string> firstAppend(string xParse, string yPlain);
    set<string> firstAppend(set<string> xParse, set<string> yParse);

    void read(istream &s);
public:
    string print();
    Grammar();
    Grammar(istream &s, unsigned int _k);
    void addRule(Rule t);
    set<string> first(string A);
};

#endif // GRAMMAR_H
