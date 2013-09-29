#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

int N, i;

void read_config();
void read_program();
bool do_test();

char *config_string = NULL, *program_string = NULL;
size_t config_len1, program_len1;
int config_len, program_len;

enum ptype{PAR, SEQ, NONE};

struct pp
{
    int n;
    int used;
    int t;
    bool has;
};

vector< vector<pp> > arr;
vector<pp> inp;

void read_config()
{
    config_string = NULL;
    getline(&config_string, &config_len1, stdin);
    printf("cstr=%s\n", config_string);
    config_len = strlen(config_string);
    int t1;
    char t2;
    int t;
    int i = 0;
    inp.clear();
    int sumLen = 0, lastLen;
    while(sumLen < config_len && ((t = sscanf(config_string + sumLen, "%d%c%n", &t1, &t2, &lastLen)) == 2))
    {
        sumLen += lastLen;
        //printf("got N=%d, ll=%d, t=%d, c=%c\n", t1, lastLen, t, t2);
        pp a;
        a.n = t1;
        a.t = NONE;
        if(t2 == '-')
            a.t = SEQ;
        if(t2 == '|')
            a.t = PAR;
        a.used = 0;
        inp.push_back(a);
        //exit(-1);
    }

    for(i = 0; i < inp.size(); i++)
    {
        printf("got i=%d, type=%d, has=%d\n", inp[i].n, inp[i].t, inp[i].has);
    }
}

void read_program()
{
    program_string = NULL;
    getline(&program_string, &program_len1, stdin);
    program_len = strlen(program_string);
}

bool do_test()
{
    return(1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d\n", &N);

    for(i = 0; i < N; i++)
    {
        fprintf(stderr, "reading %d\n", i);
        read_config();
        read_program();
        printf("%s\n", do_test() ? "CORRECT" : "INCORRECT");
    }

    return(0);
}
