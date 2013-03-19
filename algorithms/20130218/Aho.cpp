#include <iostream>
#include <vector>
#include <string>

#define L 26
#define NMAX 100

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::string;

class Trie
{
private:
    Trie* c[L];
    Trie* pi;
    Trie* out;
    Trie* prev;
    bool word;
public:
    Trie(Trie* cprev)
    {
        int i;
        for(i = 0; i < L; i++) c[i] = NULL;
        pi = this;
        out = this;
        prev = cprev;
        word = false;
    }
    void insert(char* word)
    {
        if(*word != 0)
        {
            if(c[*word - 'a'] == NULL)
                c[*word - 'a'] = new Trie(this);
            c[*word - 'a']->insert(word + 1);
        }
        else
            this->word = true;
    }
    void print(string pref = "")
    {
        int i;
        for(i = 0; i < L; i++)
        {
            if(c[i] != NULL)
            {
                cout << pref << ((char) ('a' + i));
                if(c[i]->word) cout << "*";
                cout << endl;
                string pref1 = pref;
                pref1 += (char) ('a' + i);
                c[i]->print(pref1);
            }
        }
    }
};

int main()
{
    Trie* myTrie = new Trie(NULL); // root
    myTrie->insert("abacaba");
    myTrie->insert("aba");
    myTrie->insert("bacaba");
    myTrie->print();
    return 0;
}
