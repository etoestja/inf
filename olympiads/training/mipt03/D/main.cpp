#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define BRACKETS 3
#define SENTPARTS 3

char b1[BRACKETS] = {'{', '(', '['};
char b2[BRACKETS] = {'}', ')', ']'};


stringstream res;

void skipc()
{

    char c = ' ';
    while(c == ' ')
    {
        cin >> std::noskipws >> c;
    }
    cin.putback(c);
}

typedef pair<string, unsigned> br_word;

br_word getBrWord()
{
    char b1c;
    cin >> b1c;

    br_word b;
    for(unsigned i = 0; i < BRACKETS; i++)
    {
        if(b1c == b1[i])
        {
            //cerr << "detected opening " << b1c << " code " << i << endl;
            b.second = i;
        }
    }

    stringstream ss;

    char c;

    bool ok = false;

    while(!ok)
    {
        cin >> std::noskipws >> c;

        c = tolower(c);

        //cerr << "got c [" << c << "]" << endl;

        for(unsigned i = 0; i < BRACKETS; i++)
        {
            if(c == b2[i])
            {
                //cerr << "detected closing " << c << " code " << i << endl;
                ok = true;
                break;
            }
        }

        if(!ok)
        {
            ss << c;
        }
    }

    b.first = ss.str();

    return(b);
}

void printSentence(bool needFirstLetter)
{
    br_word p[SENTPARTS];

    for(unsigned i = 0; i < SENTPARTS; i++)
    {
        p[i] = getBrWord();
        skipc();
        //cerr << "got " << i << " [" << p[i].second << "] [" << p[i].first << "]" << endl;
    }

    for(unsigned i = 0; i < BRACKETS; i++)
    {
        for(unsigned j = 0; j < SENTPARTS; j++)
        {
            if(p[j].second == i)
            {
                if(i == 0 && needFirstLetter)
                {
                    p[j].first[0] = toupper(p[j].first.c_str()[0]);
                }
                res << p[j].first;
                if(i < BRACKETS - 1)
                    res << " ";
            }
        }
    }
}

int main()
{
    printSentence(true);

    char c;

    cin >> std::noskipws >> c;

    if(c == ',')
    {
        res << ',';

        bool ok = false;

        while(!ok)
        {
            cin >> std::noskipws >> c;

            for(unsigned i = 0; i < BRACKETS; i++)
            {
                if(c == b1[i])
                {
                    cin.putback(c);
                    printSentence(false);
                    ok = true;
                    break;
                }
            }

            if(!ok)
            {
                res << c;
            }
        }
    }

    cout << res.str() << endl;

    return 0;
}

