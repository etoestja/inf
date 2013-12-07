#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>
#include <string>
#include <set>
#include "rule.h"

using std::string;
using std::vector;
using std::set;

class Grammar
{
private:
    string S;
    string endSymbol;

    set<char> terminals;
    set<char> nonTerminals;

    vector<Rule> rules;
    bool isTerminal(char c);
    bool isTerminal(string c);
    void fillSymbols();

    void read(istream &s);
public:
    string print();
    Grammar();
    Grammar(istream &s);
    void addRule(Rule t);
};

#endif // GRAMMAR_H
