#include "trie.h"
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <QDebug>

using std::endl;
using std::string;
using std::queue;
using std::stringstream;

Trie::Trie(Trie* cprev)
{
    if(cprev == NULL)
    {
        out = prev = pi = this;
    }
    else
    {
        pi = NULL;
        out = NULL;
        prev = cprev;
    }
    int i;
    for(i = 0; i < L; i++) c[i] = NULL;
    word = false;
}
void Trie::insert(unsigned char *word)
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

void Trie::getPi(Trie* root)
{
    // x - prev
    // |
    // t - this

    if(prev == this)
    {
        qDebug() << "pi1";
        pi = root;
        out = root;
        return;
    }

    Trie* cPi = prev->pi;
    while(cPi != root && cPi->c[(unsigned) linkchar] == NULL)
        cPi = cPi->pi;
    if(cPi->c[(unsigned) linkchar] == NULL || cPi->c[(unsigned) linkchar] == this)
    {
        qDebug() << "pi2";
        pi = root;
        out = root;
        return;
    }

    if(cPi->c[(unsigned) linkchar]->word)
        out = cPi->c[(unsigned) linkchar];
    else out = cPi->c[(unsigned) linkchar]->out;

    pi = cPi->c[(unsigned) linkchar];
}

void Trie::update()
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

        qDebug() << "position=" << current->getShortInfo().c_str()
                 << "newpi=" << current->pi->getShortInfo().c_str();

        for(i = 0; i < L; i++)
            if(current->c[i] != NULL)
                q.push(current->c[i]);
   }
}
string Trie::print()
{
    stringstream res;
    if(this == prev)
        res << getFullInfo();

    for(int i = 0; i < L; i++)
    {
        if(c[i] != NULL)
        {
            res << c[i]->getFullInfo();
            res << c[i]->print();
        }
    }
    return(res.str());
}

string Trie::getString()
{
    string x;
    Trie* a = this;
    while(a->prev != a)
    {
        x += a->linkchar;
        a = a->prev;
    }

    string y;
    string::reverse_iterator rit;
    for(rit = x.rbegin(); rit != x.rend(); rit++)
        y += *rit;

    return(y);
}

string Trie::getShortInfo()
{
    stringstream ss;
    ss << "[" << getString();
    if(word) ss << "*";
    ss << "]@" << this;
    return(ss.str());
}

string Trie::getFullInfo()
{
    stringstream res;
    res << getShortInfo() << endl;
    res << "\tprev\t" << prev->getShortInfo() << endl;
    res << "\tpi\t" << pi->getShortInfo() << endl;
    res << "\tout\t" << out->getShortInfo() << endl;
    return(res.str());
}

vector< pair<unsigned, string> > Trie::find(string text)
{
    vector< pair<unsigned, string> > resVect;
    Trie *pos = this, *outLink = NULL, *piLink = NULL;
    unsigned i = 0;

	char c;

    for(;;)
    {
	scanf("%c", &c);
	if(!(c >= 'A' && c <= 'z')) c = 'a';
        if(pos->c[(unsigned) c] != NULL) //there is a link
        {
            //qDebug() << "found a link" << pos->c[(unsigned) c]->getShortInfo().c_str();
            pos = pos->c[(unsigned) c];
       	} 
        else
        {
            //qDebug() << "ntfnd a link";
            piLink = pos->pi;
            while(piLink != this && piLink->c[(unsigned) c] == NULL)
            {
                piLink = piLink->pi;
            }
            pos = piLink;
            if(pos == this && pos->c[(unsigned) c] != NULL)
                pos = pos->c[(unsigned) c];
        }

        outLink = pos;
        if(!outLink->word) outLink = outLink->out;
        while(outLink != this)
        {
            resVect.push_back(pair<unsigned, string> (i - pos->getString().length(), outLink->getString()));
            //qDebug() << "STRING " << outLink->getShortInfo().c_str();
            outLink = outLink->out;
        }
    }
    return(resVect);
}
