#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <fstream>

using namespace std;

int N, i;

#undef DEBUG
//#define DEBUG

void read_config();
bool read_test_program();
//bool do_test();

string config_string, program_string;
size_t config_len1, program_len1;
int config_len, program_len;

enum ptype{PAR, SEQ, NONE};

ifstream ain("input.txt");
ofstream aout("output.txt");

struct pp
{
    int n;
    int used;
    int detached;
    int t;
    bool has;
};

vector< vector<pp> > arr;
vector<pp> inp;

void read_config()
{
    ain >> config_string;

    config_len = config_string.length();
#ifdef DEBUG
    printf("cstr=%s\n", config_string.c_str());
#endif
    int i = 0;
    inp.clear();
    pp a;
    a.n = -1;
    for(i = 0; i < config_len; i++)
    {
        if(config_string[i] >= '0' && config_string[i] <= '9')
        {
            if(a.n != -1)
                inp.push_back(a);
            a.has = 1;
            a.detached = 0;
            a.used = 0;
            a.n = config_string[i] - '0';
        }
        else if(config_string[i] == '-')
            a.t = SEQ;
        else if(config_string[i] == '|')
            a.t = PAR;
        else if(config_string[i] == '#')
        {
            a.has = 0;
        }
    }
    if(a.n != -1)
        inp.push_back(a);


    arr.clear();
    vector<pp> t_vec;
    for(i = 0; i < inp.size(); i++)
    {
        //printf("got i=%d, type=%d, has=%d\n", inp[i].n, inp[i].t, inp[i].has);
        if(i > 0 && inp[i - 1].t == SEQ)
        {
            if(t_vec.size() > 0)
                arr.push_back(t_vec);
            t_vec.clear();
            //printf("clear\n");
        }
        t_vec.push_back(inp[i]);
    }
    if(t_vec.size() > 0)
        arr.push_back(t_vec);

#ifdef DEBUG
    for(i = 0; i < arr.size(); i++)
    {
        printf("item#%d: ", i);
        for(int j = 0; j < arr[i].size(); j++)
        {
            printf("(%d %d %d) ", arr[i][j].n, arr[i][j].t, arr[i][j].has);
        }
        printf("\n");
    }
#endif
}

struct cmd
{
    int p1;
    int p2;
    char action;
};

cmd a;

bool run_cmd(int pt, char action)
{
#ifdef DEBUG
    printf("runcmd pt=%d, action=%c\n", pt, action);
#endif
    int i, j, is = -1, js = -1;

    for(i = 0; i < arr.size(); i++)
        for(j = 0; j < arr[i].size(); j++)
            if(arr[i][j].n == pt)
            {
                is = i;
                js = j;
                break;
            }
    if(is == -1 || js == -1)
        return(false);
#ifdef DEBUG
    printf("found is=%d, js=%d\n", is, js);
#endif

    for(i = 0; i < is; i++)
        for(j = 0; j < arr[i].size(); j++)
        {
            if(!arr[i][j].detached || (!arr[i][j].used && arr[i][j].has))
                return(false);
        }

    if(action == '-')
        for(j = 0; j < arr[is].size(); j++)
        {
            if(arr[is][j].n < pt && !arr[is][j].detached)
                return(false);
        }

    if(action == '+')
    {
#ifdef DEBUG
        printf("a+\n");
#endif
        if(!arr[is][js].has)
            return(false);
        if(arr[is][js].used || arr[is][js].detached)
            return(false);
        arr[is][js].used = 1;
    }
    else if(action == '-')
    {
        if(pt == inp.size())
            return(false);
        if((!arr[is][js].used && arr[is][js].has) || arr[is][js].detached)
            return(false);
        arr[is][js].detached = 1;
    }
    return(1);
}

bool read_test_program()
{
    ain >> program_string;
    program_len = program_string.length();

#ifdef DEBUG
    printf("prog=%s\n", program_string.c_str());
#endif

    a.p1 = -1;
    a.p2 = -1;

    for(int i = 0; i < program_len; i++)
    {
        if(program_string[i] >= '0' && program_string[i] <= '9')
        {
            if(a.p1 == -1)
                a.p1 = program_string[i] - '0';
            else
                a.p2 = program_string[i] - '0';
        }
        else if(program_string[i] == '-' || program_string[i] == '+')
        {
            a.action = program_string[i];
            if(a.p1 != -1)
                if(!run_cmd(a.p1, a.action))
                    return(0);
            if(a.p2 != -1)
                if(!run_cmd(a.p2, a.action))
                    return(0);
            a.p1 = -1;
            a.p2 = -1;
        }
    }

#ifdef DEBUG
    printf("testing...\n");
#endif

    for(int i = 0; i < arr.size(); i++)
        for(int j = 0; j < arr[i].size(); j++)
        {
            if(arr[i][j].n == inp.size())
            {
                if(arr[i][j].detached)
                    return(false);
            }
            else
            {
                if((arr[i][j].has && !arr[i][j].used) || !arr[i][j].detached)
                    return(false);
            }
        }

    return(true);
}

//bool do_test()
//{
//    return(1);
//}

int main()
{
    ain >> N;

    for(i = 0; i < N; i++)
    {
#ifdef DEBUG
        printf("reading %d\n", i);
#endif
        read_config();
        if(read_test_program())
            aout << "CORRECT" << endl;
        else
            aout << "INCORRECT" << endl;
    }

    return(0);
}
