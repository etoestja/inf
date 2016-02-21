#include "analyzer.h"
#include "ui_analyzer.h"

#include <fstream>
#include <iostream>
#include <string>
#include <locale>
#include <stdio.h>
#include <string.h>
#include <strings.h>
//#include <codecvt>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;

struct descr
{
    string n1;
    string n2;
    int h;
    int m;
    int s;
    int d;
    int M;
    int y;
};

int readDescr(string s, descr& d)
{
    if(!(s[0] >= 'A' && s[0] <= 'Z' && s[s.length() - 1] == ':'))
        return(1);

    char *n1 = (char*) malloc(s.length());
    char *n2 = (char*) malloc(s.length());
    sscanf(s.c_str(), "%s %s (%d:%d:%d %d/%d/%d):", n1, n2, &d.h, &d.m, &d.s, &d.d, &d.M, &d.y);
    fprintf(stderr, "n1=%s n2=%s (%d:%d:%d %d/%d/%d)\n", n1, n2, d.h, d.m, d.s, d.d, d.M, d.y);
    d.n1 = n1;
    d.n2 = n2;
    delete n1;
    delete n2;
    return(0);
}

std::istream &getlineSafe(std::istream &is, std::string &s) {
    char ch;

    s.clear();

    while (is.get(ch) && ch != '\n' && ch != '\r')
        s += ch;
    return is;
}

void Analyzer::readFile()
{
    ifstream f;
    f.imbue(std::locale("en_US.UTF8"));
    f.open(filename.c_str());
    string sLine;
    descr d;

    int *p_ptr = NULL;

    while(!f.eof() && f.is_open())
    {
        getlineSafe(f, sLine);

        cout << "[" << sLine << "]" << endl;

        if(!readDescr(sLine, d))
        {
            if(!d.n1.compare("Sergey"))
            {
                p_ptr = &(year[d.M - 1][d.d - 1].msg_out);
            }
            else
            {
                p_ptr = &(year[d.M - 1][d.d - 1].msg_in);
            }
        }
        else if(p_ptr != NULL && sLine[0] != '\t')
            *p_ptr += sLine.length();
    }

    f.close();
}
