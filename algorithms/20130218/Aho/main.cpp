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
        if(cprev == NULL)
        {
            out = prev = pi = this;
        }
        else
        {
            pi = NULL;
            out = this;
            prev = cprev;
        }
        int i;
        for(i = 0; i < L; i++) c[i] = NULL;
        word = false;
    }
    void insert(char* word)
    {
        if(*word != 0)
        {
            if(c[(unsigned) *word] == NULL)
                c[(unsigned) *word] = new Trie(this);
            c[(unsigned) *word]->insert(word + 1);
            c[(unsigned) *word]->linkchar = *word;
        }
        else
            this->word = true;
    }

    void getPi(Trie* root)
    {
        // x - prev
        // |
        // t - this

        if(prev == this)
        {
            cout << "pi1" << endl;
            pi = root;
            return;
        }

        Trie* cPi = prev->pi;
        while(cPi != root && cPi->c[(unsigned) linkchar] == NULL)
            cPi = cPi->pi;
        if(cPi->c[(unsigned) linkchar] == NULL || cPi->c[(unsigned) linkchar] == this)
        {
            cout << "pi2" << endl;
            pi = root;
            return;
        }
        pi = cPi->c[(unsigned) linkchar];
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
            current->getPi(this);

            cout << "position: " << current << "[" << current->linkchar << "] newpi=" << current->pi << endl;
            for(i = 0; i < L; i++)
                if(current->c[i] != NULL)
                    q.push(current->c[i]);
       }
    }
    void print(string pref = "")
    {
        if(!pref.compare(""))
        {
            cout << this << "\t" << prev << "\t";
            if(pi == NULL) cout << "0x000000";
            cout << pi << "\tr" << endl;
        }
        int i;
        for(i = 0; i < L; i++)
        {
            if(c[i] != NULL)
            {
//                cout << "prev char=" << linkchar << endl;
                cout << c[i] << "\t";
                cout << c[i]->prev << "\t";
                if(c[i]->pi == NULL) cout << "0x000000";
                cout << c[i]->pi << "\t";
                cout << pref << ((char) (i));
                if(c[i]->word) cout << "*";
                cout << endl;
                string pref1 = pref;
                pref1 += (char) (i);
                c[i]->print(pref1);
            }
        }
    }
};

int main()
{
    Trie* myTrie = new Trie(NULL); // root
    myTrie->insert((char *) "abacaba");
    myTrie->insert((char *) "ba");
    myTrie->insert((char *) "aba");
    myTrie->insert((char *) "bacaba");
    myTrie->calcPi();
    myTrie->print();
    return 0;
}
