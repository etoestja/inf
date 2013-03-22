#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define L 255
#define NMAX 100

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::string;
using std::queue;

class Trie
{
private:
    Trie* c[L];
    Trie* pi;
    Trie* out;
    Trie* prev;
    bool word;
    char linkchar;
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
            c[*word - 'a']->linkchar = *word - 'a';
        }
        else
            this->word = true;
    }

    void getPi()
    {
        // x - prev
        // |
        // t - this

        if(prev == NULL)
        {
            pi = NULL;
            return;
        }
        Trie* cPi = prev->pi;
        while(cPi != NULL && cPi->c[linkchar] == NULL)
            cPi = cPi->pi;
        if(cPi == NULL)
        {
            pi = NULL;
            return;
        }
        pi = cPi->c[linkchar];
    }

    void calcPi()
    {
        //bfs 
        queue<Trie*> q;
        q.push(this);
        Trie* current;
        int i;
        while(!q.empty())
        {
            current = q.front();
            q.pop();
            current->getPi();

            cout << "position: " << current << endl;
            for(i = 0; i < L; i++)
                if(current->c[i] != NULL)
                    q.push(current->c[i]);
       }
    }
    void print(string pref = "")
    {
        int i;
        for(i = 0; i < L; i++)
        {
            if(c[i] != NULL)
            {
//                cout << "prev char=" << linkchar << endl;
                cout << c[i] << "\t";
                cout << c[i]->prev << "\t";
                cout << c[i]->pi << "\t";
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
    myTrie->insert((char *) "abacaba");
    myTrie->insert((char *) "aba");
    myTrie->insert((char *) "bacaba");
    myTrie->calcPi();
    myTrie->print();
    return 0;
}
