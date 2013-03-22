#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>

//#define QT_NO_DEBUG_OUTPUT

using std::string;
using std::pair;
using std::vector;

#define L 256

class Trie
{
private:
    Trie* c[L];
    Trie* pi;
    Trie* out;
    Trie* prev;
    bool word;
    unsigned char linkchar;
public:
    Trie(Trie* cprev);
    void insert(unsigned char* word);
    void getPi(Trie* root);
    void update();
    string print();
    string getString();
    string getShortInfo();
    string getFullInfo();
    vector< pair<unsigned, string> > find(string text);
};

#endif // TRIE_H
